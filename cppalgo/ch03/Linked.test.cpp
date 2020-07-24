#include "Number.hpp"
#include "Linked_List.hpp"
#include "gtest/gtest.h"

namespace Algo {

using ITEM_TYPE = Algo::Number;

template<class T>
Algo::LinkedNode<T> dblnode(Algo::LinkedNode<T>* N) {
    return Algo::LinkedNode<T>(N->item + N->item);
};

template<class T>
T dbl(const T& v) {
    return v + v;
};

class myTest : public testing::Test {
    // must make it protected
    protected:
        // setup will be called for each test
        void SetUp() override {
            N1.set(8);
            N2.set(9);
            N3.set(18);

            L.insert(N1);
            L.insert(N2);
            // LNode1.item = N1;
            // LNode2.item = N2;
            // LinkedNode<ITEM_TYPE> LNode1(N1);
            // LinkedNode<ITEM_TYPE> LNode2(N2);

            // LNode1.item = N1;
            // LNode2.item = N2;
        }

        // declaration and initialization
        Number N1;
        Number N2;
        Number N3;
        Number N10{100.0};

        LinkedNode<ITEM_TYPE> LNode1{N10};
        LinkedNode<ITEM_TYPE> LNode2{N1};

        // LinkedList<ITEM_TYPE> link {N1, N2, N3};
        LinkedList<Number> L;
        LinkedList<Number> L1;


};

TEST_F(myTest, functor) {
    EXPECT_EQ(N1() + 2, 10);
}

TEST_F(myTest, doubleNode) {
    EXPECT_EQ(dblnode(&LNode1).item, 200);
}

TEST_F(myTest, initNode) {
    EXPECT_EQ(LNode1.item, 100);
}

TEST_F(myTest, defaultNode) {
    // it is zero not 8!!
    EXPECT_EQ(LNode2.item, 0);
}

// first and last node items
TEST_F(myTest, first_and_last) {
    EXPECT_EQ(L.first()->item, 8);
    EXPECT_EQ(L.last()->item, 9);
}

TEST_F(myTest, list_removal) {
    L.remove();
    EXPECT_EQ(L.last()->item, 8);
}

TEST_F(myTest, list_empty) {
    L.remove();
    EXPECT_EQ(L.last()->item, 8);
    EXPECT_EQ(L.first()->item, 8);
    L.remove();
    EXPECT_TRUE(L.isEmpty());
    // remove empty list
    L.remove();
    EXPECT_TRUE(L.first() == nullptr);
    EXPECT_TRUE(L.isEmpty());
}

TEST_F(myTest, move_constructor) {
    LinkedList<Number> L_test = move(L);
    EXPECT_TRUE(L.isEmpty());
    EXPECT_EQ(L_test.first()->item, 8);
    EXPECT_EQ(L_test.last()->item, 9);
}

TEST(MoveTest, move_operator) {
    LinkedList<ITEM_TYPE> link {1.0, 2.0, 3.0};
    LinkedList<Number> L1;
    L1 = move(link);
    EXPECT_TRUE(link.isEmpty());
    EXPECT_EQ(L1.last()->item, 3);
}




} // end namespace


int main(int argc, char **argv) {
    // initialize the framework
    testing::InitGoogleTest(&argc, argv);
    // macro
    return RUN_ALL_TESTS();
}