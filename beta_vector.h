#ifndef BETA_VECTOR_H
#define BETA_VECTOR_H

#include <initializer_list>
#include <cassert>
#include <iostream>

template <class T>
class beta_vector
{
    class memory_manager;
public:
//    typedef T* iterator;
//    typedef T const* const_iterator;

    beta_vector(size_t size_ = 5): m_memoryManager(size_) { }
    beta_vector(size_t size_, const T &val)
        : m_memoryManager(size_)
    {
        m_memoryManager.initializeByVal(val);
    }

  beta_vector(const beta_vector& temp);

  beta_vector(std::initializer_list<T> ls)
      :m_memoryManager(ls)
  { }
  beta_vector(beta_vector &&);

  template <class type_d>
  friend std::ostream& operator <<(std::ostream& ord, const beta_vector<type_d> &out);

  void push_back(const T &val);
  void resize(size_t addsize = 5);
  beta_vector<T>& operator +=(const beta_vector<T>& cur);
  beta_vector<T>& operator +=(const T &add);
  T at(size_t) const;
  T& operator[](size_t);
  inline size_t size() const{ return m_memoryManager.constructedSize(); }
  beta_vector& operator =(const beta_vector &coppy);
  beta_vector& operator =(beta_vector &&coppy);
  void pop_back();

public:
  class iterator
  {
  public:
    iterator() :elem{nullptr} {}
    iterator(T *a): elem{a} {}
    iterator(const iterator &iter): elem{iter.elem} {}
    bool operator== (const iterator& iter) const
    { return elem == iter.elem; }
    bool operator!=(const iterator& iter) const
    { return elem != iter.elem; }

    T& operator*()
    { return *elem; }

    T* operator ->()
    { return elem; }

    iterator operator++()
    {
      ++elem;
      return *this;
    }
    iterator operator--(int)
    {
      iterator temp(*this);
      --elem;
      return temp;
    }
    iterator operator--()
    {
      --elem;
      return *this;
    }

    iterator operator++(int)
    {
      iterator temp(*this);
      ++elem;
      return temp;
    }

    iterator operator +=(const size_t add)
    {
      elem+=add;
      return *this;
    }

    iterator operator+(const size_t add)
    {
      return *this+=add;
    }

  private:
    T *elem;
  };

  class const_iterator
  {
  public:
    const_iterator() :elem{nullptr} {}
    const_iterator(T *a): elem{a} {}
    const_iterator(const const_iterator &iter): elem{iter.elem} {}
    bool operator== (const const_iterator& iter) const
    { return elem == iter.elem; }
    bool operator!=(const const_iterator& iter) const
    { return elem != iter.elem; }

    const T& operator*()
    { return *elem; }

    const T* operator ->()
    { return elem; }

    const_iterator operator++()
    {
      ++elem;
      return *this;
    }
    const_iterator operator--(int)
    {
      const_iterator temp(*this);
      --elem;
      return temp;
    }
    const_iterator operator--()
    {
      --elem;
      return *this;
    }
    const_iterator operator++(int)
    {
      const_iterator temp(*this);
      ++elem;
      return temp;
    }

    const_iterator operator +=(const size_t add)
    {
      elem+=add;
      return *this;
    }

    const_iterator operator+(const size_t add)
    {
      return *this+=add;
    }

  private:
    T *elem;

  };

  iterator begin()
  {
    return m_memoryManager.data();
  }

  iterator end()
  {
    return m_memoryManager.endPointer();
  }

  const_iterator begin() const
  {
    return m_memoryManager.data();
  }
  const_iterator end() const
  {
    return m_memoryManager.endPointer();
  }


private:
  memory_manager m_memoryManager;

  class memory_manager
  {
  public:
      memory_manager(size_t rawSize = 5)
          : m_rawSize(rawSize),
            m_constructedSize(0),
            m_data(static_cast<T *>(operator new(rawSize * sizeof(T))))
      { }
      memory_manager(const std::initializer_list<T> &list)
          : m_rawSize(list.size()),
            m_constructedSize(list.size()),
            m_data(createNewRawMem(list.size()))
      {
          size_t i = 0;
          for (const auto &elem : list)
              new (m_data+i) T(elem);

      }
      memory_manager(memory_manager &&toMove)
      {
          deleteArea(m_data, m_data+m_constructedSize);
          operator delete[](m_data);

          m_constructedSize = toMove.m_constructedSize;
          m_rawSize = toMove.m_rawSize;
          m_data = toMove.m_data;
          toMove.m_data = nullptr;
      }
      memory_manager & operator = (const memory_manager& coppy)
      {
          operator delete[](m_data);
          createNewRawMem(coppy.m_rawSize);
          m_rawSize = coppy.m_rawSize;
          m_constructedSize = coppy.m_constructedSize;
          for (size_t i = 0; i < m_constructedSize; ++i)
              new(m_data+i) T(coppy.m_data[i]);

          return *this;
      }
      memory_manager& operator = (memory_manager &&toMove)
      {
          deleteArea(m_data, m_data+m_constructedSize);
          operator delete[](m_data);

          m_constructedSize = toMove.m_constructedSize;
          m_rawSize = toMove.m_rawSize;
          m_data = toMove.m_data;
          toMove.m_data = nullptr;

          return *this;
      }
      ~memory_manager()
      {
          deleteArea(m_data, m_data + m_constructedSize);

          operator delete[](m_data);
      }

      static T* createNewRawMem(std::size_t size)
      {
          return static_cast<T*>(operator new(size * sizeof(T)));
      }

      void initializeByVal(const T& val)
      {
          for (size_t i = 0; i < m_rawSize; ++i)
              new (m_data + i) T(val);
          m_constructedSize = m_rawSize;
      }

      void addDataElem(const T& elem)
      {
          checkForResize();
          new (m_data + m_constructedSize++) T(elem);
      }

      void checkForResize()
      {
          if (m_constructedSize >= m_rawSize)
              resize(m_rawSize*2);
      }

      void removeLastDataElem()
      {
          --m_constructedSize;
          endPointer()->~T();
      }
      T *endPointer() const
      {
          return m_data + m_constructedSize;
      }
      void resize(size_t size)
      {
          m_rawSize += size;

          auto newData = createNewRawMem(m_rawSize);
          for (size_t i = 0; i < m_constructedSize; ++i)
              new (newData+i) T(m_data[i]);

          operator delete[](m_data);
          m_data = newData;
      }
      T *data() const
      {
          return m_data;
      }

      size_t constructedSize() const
      {
          return m_constructedSize;
      }

      T& getDataElem(size_t index) const
      {
          return m_data[index];
      }

      void extendBy(const memory_manager& memory)
      {
          if (memory.m_constructedSize >= m_rawSize)
              resize(memory.m_constructedSize);
          for (size_t i = m_constructedSize; i < memory.m_constructedSize + m_constructedSize; ++i)
              new (m_data+i) T(m_constructedSize-i);
      }

  private:
      void deleteArea(T* begin, T* end)
      {
          while (begin++ != end)
              begin->~T();
      }

  private:
      size_t m_rawSize;
      size_t m_constructedSize;
      T *m_data{nullptr};
  };
};

template<class T>
beta_vector<T>& beta_vector<T>::operator +=(const T& add)
{
  for(size_t i = 0; i < size(); ++i)
    m_memoryManager.data()[i] += add;

  return *this;
}

template<class T>
beta_vector<T>& beta_vector<T>::operator =(beta_vector<T> &&coppy)
{
    m_memoryManager = std::move(coppy.m_memoryManager);

    return *this;
}

template<class T>
beta_vector<T>::beta_vector(const beta_vector<T> &temp)
{
    m_memoryManager = temp.m_memoryManager;
}

template<class T>
beta_vector<T>::beta_vector(beta_vector<T> &&other)
{
    m_memoryManager = std::move(other.m_memoryManager);
}

template<class T>
T beta_vector<T>::at(size_t elem) const
{
    return m_memoryManager.getDataElem(elem);
}

template<class T>
beta_vector<T>& beta_vector<T>::operator +=(const beta_vector<T>& cur)
{
    m_memoryManager.extendBy(cur.m_memoryManager);

    return *this;
}

template<class data_type>
beta_vector<data_type> operator+ (beta_vector<data_type> first, beta_vector<data_type>& second)
{
  return first+=second;
}

template <class T>
beta_vector<T>& beta_vector<T>::operator =(const beta_vector<T> &coppy)
{
    m_memoryManager = coppy.m_memoryManager;
    return *this;
}

template <class T>
std::ostream& operator <<(std::ostream& ord, const beta_vector<T>& out)
{
  for(size_t i = 0; i < out.size(); i++)
    ord << out.at(i) << ' ';
  return ord;
}

template <class T>
T& beta_vector<T>::operator [](size_t index)
{
    assert(index < m_memoryManager.constructedSize() && "Index out of range");
    return m_memoryManager.getDataElem(index);
}

template <class T>
void beta_vector<T>::push_back(const T &elem)
{
    m_memoryManager.addDataElem(elem);
}

template <class T>
void beta_vector<T>::pop_back()
{
    m_memoryManager.removeLastDataElem();
}

#endif // BETA_VECTOR_H
