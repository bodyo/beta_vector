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
    beta_vector<beta_vector<int>> vec{{1,2,3}, {12,45}};

//    vec.push_back(beta_vector<int>(4,5));
//    vec.push_back(beta_vector<int>(5,6));
//    vec.push_back(beta_vector<int>(6,7));

//    beta_vector<std::vector<int>> vec;

//    vec.push_back(std::vector<int>(4,5));
//    vec.push_back(std::vector<int>(5,6));
//    vec.push_back(std::vector<int>(6,7));

//    for (auto elem : vec.at(0))
//    {
//        cout << elem << " ";
//    }
//    cout << endl;
//    for (auto elem : vec.at(1))
//    {
//        cout << elem << " ";
//    }
//    cout << endl;
//    for (auto elem : vec.at(2))
//    {
//        cout << elem << " ";
//    }
//    cout << vec.size();
}
