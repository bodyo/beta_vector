// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
#include "beta_vector.h"
#include "fraction.h"
#include <algorithm>
#include <vector>

using namespace std;

template class beta_vector<int>;

int main()
{
    beta_vector<int> vec{23,1,4,6,8,14,46,89,100,104,346};

    std::sort(vec.begin(), vec.end(), [](int val1, int val2){
        return val1 > val2;
    });

    for (auto elem : vec)
    {
        cout << elem << " ";
    }
}
