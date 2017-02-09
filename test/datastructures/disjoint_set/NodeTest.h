#include <gtest/gtest.h>

#include "../../../src/datastructures/disjoint_set/disjoint_set.h"

using namespace libp0w3r;

TEST(disjointSetTests, NodeTestStandardCtor) {

    auto n1Ptr = std::make_shared<disjoint_set<int>::Node>();

    ASSERT_EQ(n1Ptr->getParent().get(), nullptr);
    ASSERT_EQ(n1Ptr->getData(), 0);
    ASSERT_EQ(n1Ptr->getRank(), 0);
}

TEST(disjointSetTests, NodeTestTwoParameterCtor) {

    auto n1Ptr = std::make_shared<disjoint_set<int>::Node>();

    ASSERT_EQ(n1Ptr->getParent().get(), nullptr);
    ASSERT_EQ(n1Ptr->getData(), 0);
    ASSERT_EQ(n1Ptr->getRank(), 0);

    int n2_data{1337};
    auto n2Ptr = std::make_shared<disjoint_set<int>::Node>(n2_data, n1Ptr);

    ASSERT_EQ(n2Ptr->getParent(), n1Ptr);
    ASSERT_EQ(n2Ptr->getData(), n2_data);
    ASSERT_EQ(n2Ptr->getRank(), 0);
}

TEST(disjointSetTests, NodeTestOneParameterCtor) {

    int n2_data{1337};
    auto n2Ptr = std::make_shared<disjoint_set<int>::Node>(n2_data);

    ASSERT_EQ(n2Ptr->getParent().get(), nullptr);
    ASSERT_EQ(n2Ptr->getData(), n2_data);
    ASSERT_EQ(n2Ptr->getRank(), 0);
}

TEST(disjointSetTests, NodeTestOneParameterMoveCtor) {

    int n2_data{1337};
    auto n2Ptr = std::make_shared<disjoint_set<int>::Node>(std::move(n2_data));

    ASSERT_EQ(n2Ptr->getParent().get(), nullptr);
    ASSERT_EQ(n2Ptr->getData(), n2_data);
    ASSERT_EQ(n2Ptr->getRank(), 0);
}

TEST(disjointSetTests, NodeTestTwoParameterMoveCtor) {


    auto n1Ptr = std::make_shared<disjoint_set<int>::Node>();

    ASSERT_EQ(n1Ptr->getParent().get(), nullptr);
    ASSERT_EQ(n1Ptr->getData(), 0);
    ASSERT_EQ(n1Ptr->getRank(), 0);

    int n2_data{1337};
    auto n2Ptr = std::make_shared<disjoint_set<int>::Node>(std::move(n2_data), std::move(n1Ptr));

    ASSERT_EQ(n2Ptr->getParent(), n1Ptr);
    ASSERT_EQ(n2Ptr->getData(), n2_data);
    ASSERT_EQ(n2Ptr->getRank(), 0);
}

TEST(disjointSetTests, NodeTestOutputOperator) {

    int n1_data{1337};
    disjoint_set<int>::Node n1(n1_data);

    ASSERT_EQ(n1.getParent().get(), nullptr);
    ASSERT_EQ(n1.getData(), n1_data);
    ASSERT_EQ(n1.getRank(), 0);

    std::ostringstream oss;

    oss << n1;

    std::string res{oss.str()};

    ASSERT_EQ(std::stoi(res), n1_data);
}

TEST(disjointSetTests, NodeTestSetters) {

    int n1_data{1337};
    disjoint_set<int>::Node n1(n1_data);

    ASSERT_EQ(n1.getParent().get(), nullptr);
    ASSERT_EQ(n1.getData(), n1_data);
    ASSERT_EQ(n1.getRank(), 0);

    n1.setData(n1_data - 1);
    ASSERT_EQ(n1.getData(), n1_data-1);

    auto n2Ptr = std::make_shared<disjoint_set<int>::Node>(std::move(n1_data));
    n1.setParent(n2Ptr);
    ASSERT_EQ(n1.getParent(), n2Ptr);

    ASSERT_THROW(n1.setParent(nullptr), IllegalNullptrAssignmentException);

    n1.setRank(n1_data);
    ASSERT_EQ(n1.getRank(), n1_data);
}