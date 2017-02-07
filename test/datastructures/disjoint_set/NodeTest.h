#include <gtest/gtest.h>

#include "../../../src/datastructures/disjoint_set/disjoint_set.h"

using namespace libp0w3r;

TEST(disjointSetTests, NodeTestStandardCtor) {

    disjoint_set<int>::Node n;

    ASSERT_EQ(n._parent, &n);
    ASSERT_EQ(n._data, 0);
    ASSERT_EQ(n._rank, 0);
}

TEST(disjointSetTests, NodeTestTwoParameterCtor) {

    disjoint_set<int>::Node n1;

    ASSERT_EQ(n1._parent, &n1);
    ASSERT_EQ(n1._data, 0);
    ASSERT_EQ(n1._rank, 0);

    int n2_data{1337};
    disjoint_set<int>::Node n2(n2_data, &n1);

    ASSERT_EQ(n2._parent, &n1);
    ASSERT_EQ(n2._data, n2_data);
    ASSERT_EQ(n1._rank, 0);
}
