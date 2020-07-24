#include "Heap.hpp"
#include "../algo/Number.hpp"
#include "gtest/gtest.h"

using ITEM_TYPE = Algo::Number;

namespace Algo {

// fixture
class ParentTest: public testing::Test {
    // must make it protected
    protected:
        // setup will be called for each test
        void SetUp() override {
        }

    Algo::Heap<ITEM_TYPE> Hp{1492, 1776, 1941, 1783, 1865, 1600};

};

// fixture test
TEST_F(ParentTest, 01) {
    EXPECT_EQ(Hp.test_parent(1), 1);
    EXPECT_EQ(Hp.test_parent(4), 4);
    EXPECT_EQ(Hp.test_parent(5), 5);
}

TEST_F(ParentTest, 02) {
    EXPECT_EQ(Hp.test_parent(3), 3);
    EXPECT_EQ(Hp.test_parent(2), 2);
}

TEST_F(ParentTest, 03) {
    // true index
    Hp.test_swap(1, 0);
    // heap index
    EXPECT_EQ(Hp.test_parent(1), 2);
}

TEST_F(ParentTest, 04) {
    // true index
    Hp.test_swap(1, 4);
    // heap index
    EXPECT_EQ(Hp.test_parent(2), 5);
}

} // end algo


int main(int argc, char **argv) {
    // initialize the framework
    testing::InitGoogleTest(&argc, argv);
    // macro
    return RUN_ALL_TESTS();
}