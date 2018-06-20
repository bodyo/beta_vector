#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

#include "../beta_vector.h"
#include <vector>
//#include "../fraction.h"
#include <algorithm>

using namespace testing;

TEST(beta_vector_test, is_size_equal)
{
    beta_vector<int> vec{1,2,3,4,5};

    ASSERT_EQ(vec.size(), 5);
}

TEST(beta_vector_test, push_back_check)
{
    beta_vector<int> vec;
    vec.push_back(1);
    vec.push_back(6);
    vec.push_back(2);
    vec.push_back(4);

    ASSERT_EQ(vec[0], 1);
    ASSERT_EQ(vec[1], 6);
    ASSERT_EQ(vec[2], 2);
    ASSERT_EQ(vec[3], 4);
}

TEST(beta_vector_test, pop_back_check)
{
    beta_vector<int> vec;
    vec.push_back(5);
    vec.push_back(6);
    vec.push_back(22);
    vec.push_back(4);

    ASSERT_EQ(vec.size(), 4);

    auto getLast = vec[vec.size()-1];
    vec.pop_back();
    auto var = vec.at(vec.size()-1);
    ASSERT_NE(getLast, var);

    getLast = vec[vec.size()-1];
    vec.pop_back();
    var = vec.at(vec.size()-1);
    ASSERT_NE(getLast, var);

    getLast = vec[vec.size()-1];
    vec.pop_back();
    ASSERT_EQ(vec.size(), 1);
    var = vec.at(vec.size()-1);
    ASSERT_NE(getLast, var);

    getLast = vec[vec.size()-1];
    vec.pop_back();
    ASSERT_EQ(vec.size(), 0);
    var = vec.at(vec.size());
    ASSERT_EQ(getLast, var);

    ASSERT_EQ(vec.size(), 0);
}

TEST(beta_vector_test, check_for_resize)
{
    beta_vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);

    ASSERT_EQ(vec.size(), 3);

    vec.pop_back();
    ASSERT_EQ(vec.size(), 2);

    vec.push_back(4);
    vec.push_back(5);
    vec.push_back(6);
    vec.push_back(7);
    vec.push_back(8);
    vec.push_back(9);
    vec.push_back(10);
    vec.push_back(11);
    vec.push_back(12);
    vec.push_back(13);

    ASSERT_EQ(vec.size(), 12);

    ASSERT_EQ(vec.at(3), 5);

    ASSERT_EQ(vec.at(11), 13);
}

TEST(beta_vector_test, check_on_std_sort)
{
    beta_vector<int> vec{1,4,6,8,14,46,89,100,104,346};

    std::sort(vec.begin(), vec.end(), std::greater<int>());

    ASSERT_EQ(vec.at(0), 346);
    ASSERT_EQ(vec.at(4), 46);
    ASSERT_EQ(vec.at(6), 8);
    ASSERT_EQ(vec.at(9), 1);
}

TEST(beta_vector_test, check_on_std_remove_if)
{
    beta_vector<int> vec{1,5,2,7,5,2,1,56,25,67,34};

    auto lambda = [](int a) { return a == 56; };
    auto removeIfRes = std::remove_if(vec.begin(), vec.end(), lambda);
    ASSERT_EQ(vec.at(8), 67);
    ASSERT_EQ(vec.size(), 11);

    vec.erase(removeIfRes);
    auto isErased = std::find_if(vec.begin(), vec.end(), lambda);

    ASSERT_EQ(isErased, vec.end());
    ASSERT_EQ(vec.size(), 10);
}

TEST(beta_vector_test, vector_of_vector_test)
{
    beta_vector<beta_vector<int>> vec;

    vec.push_back(beta_vector<int>(4,5));
    vec.push_back(beta_vector<int>(5,6));
    vec.push_back(beta_vector<int>(6,7));

    ASSERT_EQ(vec.size(), 3);
}

TEST(beta_vector_test, dynamic_vector_creation)
{
    auto vec = new beta_vector<int>();

    vec->push_back(1);

    ASSERT_EQ(vec->size(), 1);
    delete vec;
}

TEST(beta_vector_test, std_move_semantic)
{
    beta_vector<int> vec{1,4,5,7,9,0,5};

    auto moveVec = std::move(vec);

    ASSERT_EQ(moveVec.size(), 7);
}
