#include "Number.hpp"
#include "Comparator.hpp"
#include "Actor.hpp"
#include "BST.hpp"
// #include <type_traits>
// #include <typeinfo>
#include <string>

using namespace std;
using namespace Algo;

template<class T>
void dbl(T& v) {
    v = v + v;
};

using ITEM_TYPE = Algo::Number;

int main() {
    Algo::Number N1(8);
    Algo::Number N2(9);
    Algo::Number N3(18);
    Algo::Number N4(3);
    Algo::Number N5(30);

    // Comparator<ITEM_TYPE> GT{true};
    // Comparator<ITEM_TYPE> LT{false};

    BST<ITEM_TYPE> btree;
    BST<ITEM_TYPE> rbtree{false};

    cout << rbtree << endl;

    BSTNode<ITEM_TYPE> B{N1};

    // insert test
    btree.insert(N2);
    btree.insert(N1);
    btree.insert(N3);
    btree.insert(N4);
    btree.insert(N5);
    btree.insert(1);

    cout << btree << endl;

    try {
        cout << "Root of btree: " << btree.front() << endl;
        rbtree.front();
    } catch(range_error e)  {
        cout << e.what() << " -- Ok, skip it" << endl;
    }

    try {
        cout << "last of btree: " << btree.last() << endl;
        rbtree.last();
    } catch(range_error e)  {
        cout << e.what() << " -- Ok, skip it" << endl;
    }

    // TODO:
    BSTNode<ITEM_TYPE>* node{btree.search(1)};
    cout << "Found: " << node->item << endl;

    node = btree.search(10);
    if (node != nullptr)
        cout << "Found: " << node->item << endl;
    else
        cout << "Not found" << endl;

    // cout << (nullptr || btree.root()) << endl;
    // cout << btree->root() << endl;

    BST<ITEM_TYPE> copytree{btree};
    // cout << "copytree: " << copytree.root()->item << endl;
    cout << copytree << endl;

    // copy empty tree error
    BST<ITEM_TYPE> copyb{rbtree};
    cout << copyb << endl;

    // test copy op
    copyb = move(btree);
    cout << copyb << endl;

    cout << "moved copyb: " << copyb << endl;
    cout << "moved btree: " << btree << endl;

    BST<ITEM_TYPE> ctree{move(copyb)};
    cout << "ctree: " << ctree << endl;
    cout << "moved copyb: " << copyb << endl;

    btree = ctree;
    cout << "copied btree: " << btree << endl;
    cout << "ctree: " << ctree << endl;

    // auto id = [](Number& x) -> Number& { return x;};
    auto triple = [](Number& x) -> void { x = x+x+x; };
    // cout << id(N1) << endl;

    // test Actor
    Actor<Number> A;

    // cout << A(N1) << endl;
    A.set(triple);
    cout << "before: " << N1 << endl;
    A(N1);
    cout << "after: " << N1 << endl;
    A.set(dbl);
    A(N1);
    cout << "after: " << N1 << endl;

    cout << "before ctree: " << ctree << endl;
    ctree.forEach(A);
    cout << "ctree: " << ctree << endl;

    // remove tests
    // cout << "rbtree: " << rbtree << endl;

    // insert test
    rbtree.insert(10);
    rbtree.insert(9);
    rbtree.insert(12);
    rbtree.insert(14);
    rbtree.insert(11);
    // rbtree.insert(1);
    rbtree.insert(3);
    rbtree.insert(7);
    rbtree.insert(13);
    rbtree.insert(18);

    cout << "rbtree: " << rbtree << endl;

    // rbtree.remove(3);
    rbtree.remove(18);
    rbtree.remove(10);
    // cout << "item: " << node0->left->item << endl;
    // cout << "left most: " << node0->item << endl;
    cout << "rbtree: " << rbtree << endl;

    // btree.free_all();
    // cout << "rbtree: " << rbtree.root()->item << endl;


    // btree.show_leaf(btree.root());

};