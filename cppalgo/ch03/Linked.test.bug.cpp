#include "Number.hpp"
// #include "Linked_List.hpp"
#include "gtest/gtest.h"

namespace Algo {

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


} // end namespace


int main(int argc, char **argv) {
    // initialize the framework
    testing::InitGoogleTest(&argc, argv);
    // macro
    return RUN_ALL_TESTS();
}