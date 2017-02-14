// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
#include "beta_vector.h"
#include "fraction.h"
#include <algorithm>
using namespace std;

template class beta_vector<int>;

//template<class T>
//struct value
//{
//  typedef typename beta_vector<T>::iterator value_type;
//};

//template <class T>
//struct value<T*>
//{
//  typedef T type;
//};

//template <>
//struct value<iterator>
//{
//  typedef int type ;
//};

template <class Iter, class T, class Func>
T reduse(Iter beg , Iter end, T init, Func op)
{
  T s = init;
  while ( beg != end ) {
	s = op(s, *beg);
	beg++;
  }
  return s;
}

int main()
{
  beta_vector<int> a ={2,3,5,7,98};
  beta_vector<int> b ={1,2,57,5,564,6,4};

  int r = 0;
  int t = reduse(a.begin(), a.end(), r, [](int a, int b){return a+b;});
  cout << t;
}
