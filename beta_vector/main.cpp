// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
#include "beta_vector.h"
#include "fraction.h"
#include <algorithm>
using namespace std;

template class beta_vector<int>;

template<class T>
struct value
{
  typedef typename beta_vector<T>::iterator value_type;
};

template <class T>
struct value<T*>
{
  typedef T type;
};

//template <>
//struct value<iterator>
//{
//  typedef int type ;
//};

//template <class Iter, class T>
//T sum (value<Iter> v , value<Iter>end)
//{
//  T s = 0;
//  while ( v != end ) {
//	s = s + *v;
//	v ++;
//  }
//  return s ;
//}

int main()
{
  beta_vector<int> a ={2,3,5,7,98};
  beta_vector<int> b ={1,2,57,5,564,6,4};
//  beta_vector<int>::iterator i = a.begin();
//  beta_vector<int>::iterator e = a.end();
//  cout << sum(i, e);
  beta_vector<int> c = a+b;
  cout << c.size() <<endl<< c;
  cout << '*' << c.size() <<'*' << endl;
  b.push_back(5);
  b.push_back(5);
  b.push_back(5);
  b.push_back(5);
  b.push_back(5);
  b.push_back(5);
  b.push_back(5);
  b.push_back(5);
  b.push_back(5);
  b.push_back(5);
  b.push_back(5);
  b.push_back(5);
  b.push_back(5);
  b.push_back(5);
  b.push_back(5);
  b.push_back(5);
  b.push_back(5);
  b.push_back(5);
  b.push_back(5);
  b.push_back(5);
  b.push_back(5);
  b.push_back(5);
  cout <<endl<< c;



  //cout << c;
//  for(beta_vector<int>::iterator i = a.begin(); i != a.end(); ++i)
//	cout << *i << ' ';
//cout << endl;
//  for(beta_vector<int>::const_iterator i = b.begin(); i != b.end(); ++i)
//	cout << *i << ' ';
//  cout <<endl<< c;
  /*
  beta_vector<fraction> my;
  beta_vector<beta_vector<int>> sy;
  beta_vector<int> aa(5, 5);
  cout << endl;
  cout << aa;
  fraction a(1,2);
  for(int i = 0; i < 10; ++i)
    my[i] = a++;
  cout << my.pop_back() << endl;
  cout << my;
  cout << my.size()<< endl;
  int r = 40;
  for(int i = 0; i < r; ++i)
  {
     for(int j = 0; j < r; ++j)
     {
       sy[i][j] = j;
     }
  }

  sy.pop_back();
  cout << sy.size()<<endl;
  for(int i = 0; i < static_cast<int>(sy.size()); ++i)
  {
     for(int j = 0; j < r; ++j)
     {
       cout << sy[i][j] << ' ';
     }
     cout << endl;
  }
  //cout << sy[0][1] << endl;*/
}
