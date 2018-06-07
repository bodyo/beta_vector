// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
#include "beta_vector.h"
#include "fraction.h"
#include <algorithm>
using namespace std;

template class beta_vector<int>;

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
    beta_vector<int> a = {2,3,5,7,98};

    a.push_back(1);
    a.push_back(2);
}
