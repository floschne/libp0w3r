#include <gtest/gtest.h>

#include "../../../src/datastructures/disjoint_set/disjoint_set.h"

using namespace libp0w3r;

TEST(disjointSetTests, NodeTestStandardCtor) {

    auto n1Ptr = std::make_shared<disjoint_set<int>::Node>();

    ASSERT_EQ(n1Ptr->_parent.get(), nullptr);
    ASSERT_EQ(n1Ptr->_data, 0);
    ASSERT_EQ(n1Ptr->_rank, 0);
}

TEST(disjointSetTests, NodeTestTwoParameterCtor) {

    auto n1Ptr = std::make_shared<disjoint_set<int>::Node>();

    ASSERT_EQ(n1Ptr->_parent.get(), nullptr);
    ASSERT_EQ(n1Ptr->_data, 0);
    ASSERT_EQ(n1Ptr->_rank, 0);

    int n2_data{1337};
    auto n2Ptr = std::make_shared<disjoint_set<int>::Node>(n2_data, n1Ptr);

    ASSERT_EQ(n2Ptr->_parent, n1Ptr);
    ASSERT_EQ(n2Ptr->_data, n2_data);
    ASSERT_EQ(n2Ptr->_rank, 0);
}

TEST(disjointSetTests, NodeTestOneParameterCtor) {

    int n2_data{1337};
    auto n2Ptr = std::make_shared<disjoint_set<int>::Node>(n2_data);

    ASSERT_EQ(n2Ptr->_parent.get(), nullptr);
    ASSERT_EQ(n2Ptr->_data, n2_data);
    ASSERT_EQ(n2Ptr->_rank, 0);
}

TEST(disjointSetTests, NodeTestOneParameterMoveCtor) {

    int n2_data{1337};
    auto n2Ptr = std::make_shared<disjoint_set<int>::Node>(std::move(n2_data));

    ASSERT_EQ(n2Ptr->_parent.get(), nullptr);
    ASSERT_EQ(n2Ptr->_data, n2_data);
    ASSERT_EQ(n2Ptr->_rank, 0);
}

TEST(disjointSetTests, NodeTestTwoParameterMoveCtor) {


    auto n1Ptr = std::make_shared<disjoint_set<int>::Node>();

    ASSERT_EQ(n1Ptr->_parent.get(), nullptr);
    ASSERT_EQ(n1Ptr->_data, 0);
    ASSERT_EQ(n1Ptr->_rank, 0);

    int n2_data{1337};
    auto n2Ptr = std::make_shared<disjoint_set<int>::Node>(std::move(n2_data), std::move(n1Ptr));

    ASSERT_EQ(n2Ptr->_parent, n1Ptr);
    ASSERT_EQ(n2Ptr->_data, n2_data);
    ASSERT_EQ(n2Ptr->_rank, 0);
}

TEST(disjointSetTests, NodeTestOutputOperator) {

    int n1_data{1337};
    disjoint_set<int>::Node n1(n1_data);

    ASSERT_EQ(n1._parent.get(), nullptr);
    ASSERT_EQ(n1._data, n1_data);
    ASSERT_EQ(n1._rank, 0);

    std::ostringstream oss;

    oss << n1;

    std::string res{oss.str()};

    ASSERT_EQ(std::stoi(res), n1_data);
}