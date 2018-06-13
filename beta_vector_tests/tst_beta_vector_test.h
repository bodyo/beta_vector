#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

#include "../beta_vector.h"
#include <algorithm>
#include <iostream>

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

    ASSERT_EQ(vec.size(), 13);

    ASSERT_EQ(vec.at(3), 4);

    ASSERT_EQ(vec.at(12), 13);
}

TEST(beta_vector_test, check_on_std_algorithm)
{
    beta_vector<int> vec{1,4,6,8,14,46,89,100,104,346};

    auto iter = vec.begin();

    iter-vec.end();

    std::sort(vec.begin(), vec.end(), [](const int val1, const int val2){return val1 < val2;});

    ASSERT_EQ(vec.at(0), 346);

}
