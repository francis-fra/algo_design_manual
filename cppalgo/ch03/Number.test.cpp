#include "Number.hpp"
#include "Linked_List.hpp"
#include "gtest/gtest.h"

namespace Algo {

// fixture
class NumberTest : public testing::Test {
    // must make it protected
    protected:
        // setup will be called for each test
        void SetUp() override {
            N01.set(8);
            N02.set(8);
            N03.set(18);
        }

        Number N01;
        Number N02;
        Number N03;

};

// fixture test
TEST_F(NumberTest, Cmp) {
    EXPECT_EQ(N01, N02);
}

TEST_F(NumberTest, Explicit) {
    EXPECT_EQ(N01, 8);
}

TEST_F(NumberTest, functor) {
    EXPECT_EQ(N01() + 2, 10);
}

// non-fixture tests
TEST(NumberClass, gt) {
    Number N1(2.0);
    Number N2(20.0);
    EXPECT_GT(N2, N1);
}

TEST(NumberClass, doubletest) {
    Number N1(40);
    Number N2(20);
    EXPECT_EQ(N2 + N2, 40);
    EXPECT_EQ(N2 + N2, N1);
}


// using ITEM_TYPE = Algo::Number;

class LinkedNodeTest : public testing::Test {
    // must make it protected
    protected:
        // setup will be called for each test
        void SetUp() override {
            N1.set(8);
            N2.set(8);
            N3.set(18);
            // LNode1.item = N1;
            // LNode2.item = N2;
        }

        // declaration
        // Algo::LinkedNode<Algo::Number> LNode1;
        // Algo::LinkedNode<Algo::Number> LNode2;
        Number N1;
        Number N2;
        Number N3;

};

TEST_F(LinkedNodeTest, functor) {
    EXPECT_EQ(N1() + 2, 10);
}

// TEST_F(NumberTest, functor) {
//     EXPECT_EQ(N01() + 2, 10);
// }

}


int main(int argc, char **argv) {
    // initialize the framework
    testing::InitGoogleTest(&argc, argv);
    // macro
    return RUN_ALL_TESTS();
}