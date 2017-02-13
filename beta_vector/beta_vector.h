#ifndef BETA_VECTOR_H
#define BETA_VECTOR_H

#include <initializer_list>
#include <iostream>
template <class data_type>
class beta_vector
{
  size_t size_vec;
  size_t capacity;
  data_type *data;
  data_type get_data_elem(size_t) const;
public:
  class iterator
  {
  public:
	iterator() :elem{nullptr} {}
	iterator(data_type *a): elem{a} {}
	iterator(const iterator &iter): elem{iter.elem} {}
	bool operator== (const iterator& iter) const
	{ return elem == iter.elem; }
	bool operator!=(const iterator& iter) const
	{ return elem != iter.elem; }

	data_type& operator*()
	{ return *elem; }

	data_type* operator ->()
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
	data_type *elem;
  };

  class const_iterator
  {
  public:
	const_iterator() :elem{nullptr} {}
	const_iterator(data_type *a): elem{a} {}
	const_iterator(const const_iterator &iter): elem{iter.elem} {}
	bool operator== (const const_iterator& iter) const
	{ return elem == iter.elem; }
	bool operator!=(const const_iterator& iter) const
	{ return elem != iter.elem; }

	const data_type& operator*()
	{ return *elem; }

	const data_type* operator ->()
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
	data_type *elem;
  };

  iterator begin()
  {
	return iterator(data);
  }

  iterator end()
  {
	return iterator(data+capacity);
  }

  const_iterator begin() const
  {
	return const_iterator(data);
  }
  const_iterator end() const
  {
	return const_iterator(data+capacity);
  }

  beta_vector(size_t size_ = 5): size_vec{size_}, capacity{size_}, data{new data_type[size_]} { }
  beta_vector(size_t size_, data_type val): size_vec{size_}, capacity{size_}
  {
    data = new data_type[size_];
    for(size_t i = 0; i < size_; ++i)
      data[i] = val;
  }

  beta_vector(const beta_vector& temp);

  beta_vector(std::initializer_list<data_type> ls)
  {
    data = new data_type[ls.size()];
    std::copy(ls.begin(), ls.end(), data);
    capacity = size_vec = ls.size();
  }
  beta_vector(beta_vector &&);
  template <class type_d>
  friend std::ostream& operator <<(std::ostream& ord, const beta_vector<type_d> &out);
  void push_back(const data_type &val);
  void resize(size_t addsize = 5);
  beta_vector<data_type>& operator +=(const beta_vector<data_type>& cur);
  beta_vector<data_type>& operator +=(data_type add);
  ~beta_vector()
  {
    delete[] data;
  }
  data_type& operator[](size_t);
  inline size_t size() const{ return size_vec; }
  beta_vector& operator =(const beta_vector &coppy);
  beta_vector& operator =(beta_vector &&coppy);
  data_type pop_back();
};

template<class data_type>
beta_vector<data_type>& beta_vector<data_type>::operator +=(data_type add)
{
  for(size_t i = 0; i < size_vec; ++i)
    data[i] += add;
  return *this;
}

template<class data_type>
beta_vector<data_type>& beta_vector<data_type>::operator =(beta_vector<data_type> &&coppy)
{
  if(this != &coppy)
  {
    delete [] data;
    size_vec = coppy.size_vec;
    capacity = coppy.capacity;
    std::swap(data, coppy.data);
    coppy.size_vec = 0;
    coppy.capacity = 0;
    coppy.data = nullptr;
  }
  return *this;
}

template<class data_elem>
beta_vector<data_elem>::beta_vector(const beta_vector<data_elem> &temp)
{
  data = new data_elem[temp.size_vec+1];
  size_vec = temp.size_vec;
  capacity = temp.size_vec+1;
  for(size_t i = 0; i < temp.size_vec; ++i)
      data[i] = temp.data[i];
}

template<class data_type>
beta_vector<data_type>::beta_vector(beta_vector<data_type> &&other)
  :size_vec{other.size_vec}, capacity{other.capacity}
{
  std::swap(data, other.data);
  other.data = nullptr;
  other.capacity = 0;
  other.size_vec = 0;
}

template<class data_type>
data_type beta_vector<data_type>::get_data_elem(size_t elem) const
{
  return data[elem];
}

template<class data_type>
beta_vector<data_type>& beta_vector<data_type>::operator +=(const beta_vector<data_type>& cur)
{
  resize(cur.size_vec);
  for(size_t i = 0; i < cur.size(); ++i)
    data[i] += cur.data[i];
  if(size_vec < cur.size_vec)
	size_vec = cur.size_vec;
  return *this;
}

template<class data_type>
beta_vector<data_type> operator+ (beta_vector<data_type> first, beta_vector<data_type>& second)
{
  return first+=second;
}

template <class t>
beta_vector<t>& beta_vector<t>::operator =(const beta_vector<t> &coppy)
{
  capacity = 0;
  resize(coppy.capacity);
  size_vec = coppy.size_vec;
  for(size_t i = 0; i < coppy.size_vec; ++i)
	data[i] = coppy.data[i];
  return *this;
}

template <class type_d>
std::ostream& operator <<(std::ostream& ord, const beta_vector<type_d>& out)
{
  for(size_t i = 0; i < out.size(); i++)
    ord << out.get_data_elem(i) << ' ';
  return ord;
}

template <class data_elem>
data_elem& beta_vector<data_elem>::operator [](size_t i)
{
  if(i >= capacity)
  {
    resize(i);
    size_vec+=i;
  }
  return data[i];
}

template <class type_d>
void beta_vector<type_d>::resize(size_t addsize)
{
  capacity+=addsize;
  type_d *new_mas = new type_d[capacity];
  for(size_t i = 0; i < size_vec; ++i)
	new_mas[i] = data[i];
  delete []data;
  data = new_mas;
}

template <class data_type>
void beta_vector<data_type>::push_back(const data_type &val)
{
  if(size_vec+1 > capacity)
	resize();
  std::cout << '|' << size_vec << '|' << capacity << '-';
  data[size_vec++] = val;
}

template <class data_type>
data_type beta_vector<data_type>::pop_back()
{
  data_type temp = data[--size_vec];
  return temp;
}

#endif // BETA_VECTOR_H
