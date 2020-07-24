#include "Number.hpp"
#include "BST.hpp"
#include "Comparator.hpp"
#include "gtest/gtest.h"

namespace Algo {

using ITEM_TYPE = Algo::Number;

// template<class T>
// Algo::LinkedNode<T> dblnode(Algo::LinkedNode<T>* N) {
//     return Algo::LinkedNode<T>(N->item + N->item);
// };

// cannot used??
template<class T>
T dbl(const T& v) {
    return v + v;
};

// class myTest : public testing::Test { }

TEST(ComparatorTest, cmp) {
    Number N1(8);
    Number N2(9);
    Number N3(18);

    Comparator<Number> LT{true};
    Comparator<Number> GT{false};
    // N2 > N1
    EXPECT_TRUE(GT(N2, N1));
    // N3 > N2
    EXPECT_TRUE(GT(N3, N2));
    // reverse the order
    EXPECT_TRUE(LT(N1, N2));
    EXPECT_TRUE(LT(N2, N3));
}

TEST(ComparatorTest, numerical) {
    float N1 = 8.0;
    int N2 = 9;
    Number N3(20);

    Comparator<Number> LT{true};
    Comparator<Number> GT{false};
    // N2 > N1
    EXPECT_TRUE(GT(N2, N1));
    // N3 > N2
    EXPECT_TRUE(GT(N3, N2));
    // reverse the order
    EXPECT_TRUE(LT(N1, N2));
    EXPECT_TRUE(LT(N2, N3));
}

TEST(BSTTest, NodeTest) {
    Number N1(8);
    // Number N2(9);
    // Number N3(18);

    BSTNode<ITEM_TYPE> B{N1};
    EXPECT_EQ(B.left, nullptr);
    EXPECT_EQ(B.right, nullptr);
    EXPECT_EQ(B.item, 8);
}

TEST(BSTTest, cmp) {
    Number N1(8);
    Number N2(9);
    Number N3(18);

    // comparator
    auto lt = [](Number x, Number y) { return x<y;};
    auto gt = [](Number x, Number y) { return x>y;};
    EXPECT_TRUE(lt(N1, N2));
    EXPECT_FALSE(gt(N1, N2));
}

/*
TEST(BSTTest, parent_search) {
    BST<ITEM_TYPE> btree;
    btree.insert(10);
    btree.insert(4);
    btree.insert(12);
    btree.insert(14);
    btree.insert(11);

    BSTNode<ITEM_TYPE>* node1 = btree.parent_search(10);
    BSTNode<ITEM_TYPE>* node2 = btree.parent_search(4);
    BSTNode<ITEM_TYPE>* node3 = btree.parent_search(14);
    BSTNode<ITEM_TYPE>* node4 = btree.parent_search(104);

    EXPECT_EQ(node1, btree.root());
    EXPECT_EQ(node2->left->item, 4);
    EXPECT_EQ(node3->right->item, 14);
    EXPECT_EQ(node4, nullptr);


}
*/

class myTest : public testing::Test {
    // must make it protected
    protected:
        // setup will be called for each test
        void SetUp() override {
            N1.set(8);
            N2.set(9);
            N3.set(18);
        }
        // declaration and initialization
        Number N1;
        Number N2;
        Number N3;

        BST<ITEM_TYPE> btree;
        BST<ITEM_TYPE> rbtree{false};

};

TEST_F(myTest, last) {

    Algo::Number N4(3);
    Algo::Number N5(30);

    btree.insert(N2);
    btree.insert(N1);
    btree.insert(N3);
    btree.insert(N4);

    EXPECT_EQ(btree.last(), N4);
    EXPECT_EQ(btree.front(), N2);

};

TEST_F(myTest, search) {

    btree.insert(N1);
    btree.insert(N2);
    btree.insert(N3);

    BSTNode<ITEM_TYPE>* node1{btree.search(1)};
    BSTNode<ITEM_TYPE>* node2{btree.search(8)};

    EXPECT_EQ(node1, nullptr);
    EXPECT_NE(node2, nullptr);
};

TEST_F(myTest, actor) {

    auto triple = [](Number& x) -> void { x = x+x+x; };
    Actor<Number> A;
    A.set(triple);
    A(N1);
    A(N2);

    EXPECT_EQ(N1, 24);
    EXPECT_EQ(N2, 27);
};

TEST_F(myTest, forEach) {

    auto triple = [](Number& x) -> void { x = x+x+x; };
    Actor<Number> A;
    A.set(triple);

    btree.insert(N1);
    btree.insert(N2);
    btree.insert(N3);

    BSTNode<ITEM_TYPE>* node0{btree.search(N1)};
    EXPECT_EQ(node0->item, N1);

    btree.forEach(A);
    BSTNode<ITEM_TYPE>* node1{btree.search(N1)};
    BSTNode<ITEM_TYPE>* node2{btree.search(54)};

    EXPECT_EQ(node1, nullptr);
    EXPECT_EQ(node2->item, 54);
};

TEST_F(myTest, move) {

    Algo::Number N4(3);
    Algo::Number N5(30);

    btree.insert(N2);
    btree.insert(N1);
    btree.insert(N3);
    btree.insert(N4);
    btree.insert(N5);
    btree.insert(1);

    // test copy op
    rbtree = move(btree);
    EXPECT_TRUE(btree.isEmpty());
    EXPECT_FALSE(rbtree.isEmpty());

    BST<ITEM_TYPE> ctree{move(rbtree)};
    EXPECT_TRUE(rbtree.isEmpty());
    EXPECT_FALSE(ctree.isEmpty());
}

TEST_F(myTest, copy) {

    Algo::Number N4(3);
    Algo::Number N5(30);

    btree.insert(N4);
    btree.insert(N5);

    // copy constructor
    BST<ITEM_TYPE> copytree{btree};

    EXPECT_FALSE(copytree.isEmpty());
    EXPECT_FALSE(btree.isEmpty());
    EXPECT_EQ(btree.root()->item, N4);
    EXPECT_EQ(copytree.root()->item, N4);
}

/*
TEST(FunctorTest, cmp) {
    Number N1(8);
    Number N2(9);
    Number N3(18);

    NumFunctor F;
    // N2 > N1
    EXPECT_TRUE(F(N2, N1));
    // N3 > N2
    EXPECT_TRUE(F(N3, N2));
    // reverse the order
    F.set_descending();
    EXPECT_TRUE(F(N1, N2));
    EXPECT_TRUE(F(N2, N3));
}
*/

} // end namespace


int main(int argc, char **argv) {
    // initialize the framework
    testing::InitGoogleTest(&argc, argv);
    // macro
    return RUN_ALL_TESTS();
}