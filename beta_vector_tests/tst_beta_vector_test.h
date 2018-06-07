#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

#include "../beta_vector.h"

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
    auto var = vec.at(vec.size()-1);
    vec.pop_back();
    ASSERT_NE(getLast, var);

    getLast = vec[vec.size()-1];
    var = vec.at(vec.size()-1);
    vec.pop_back();
    ASSERT_EQ(getLast, var);

    getLast = vec[vec.size()-1];
    var = vec.at(vec.size()-1);
    vec.pop_back();
    ASSERT_EQ(getLast, var);

    getLast = vec[vec.size()-1];
    var = vec.at(vec.size()-1);
    vec.pop_back();
    ASSERT_EQ(getLast, var);

    ASSERT_EQ(vec.size(), 0);
}

