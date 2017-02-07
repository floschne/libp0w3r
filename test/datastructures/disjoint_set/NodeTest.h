#include <gtest/gtest.h>

#include "../../../src/datastructures/disjoint_set/disjoint_set.h"

using namespace libp0w3r;

TEST(disjointSetTests, NodeTestStandardCtor) {

    disjoint_set<int>::Node n;

    ASSERT_EQ(n._parent, &n);
    ASSERT_EQ(n._data, 0);
    ASSERT_EQ(n._rank, 0);
}
