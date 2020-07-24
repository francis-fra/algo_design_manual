#include "utility.hpp"
#include "Linked_List.hpp"
#include "Number.hpp"
#include <iostream>

using namespace Algo;
using ITEM_TYPE = Algo::Number;

int main() {

    Algo::Number N1(8);
    Algo::Number N2(9);
    Algo::Number N3(18);
    Algo::Number N4(3);
    Algo::Number N5(30);

    // LinkedList<Number>* L = new LinkedList<Number>();
    LinkedList<ITEM_TYPE> link {N1, N2, N3, N4, N5};

    cout << "list: " << link << endl;;

    LinkedList<ITEM_TYPE>* R = get_reverse_linked_list(link);
    cout << "new list: " << *R << endl;;

    // transform_reverse_linked_list(link);
    link.reverse();
    cout << "list: " << link << endl;

    BST<ITEM_TYPE> btree;

    // insert test
    btree.insert(N2);
    btree.insert(N1);
    btree.insert(N3);
    btree.insert(N4);
    btree.insert(N5);
    btree.insert(1);

    cout << btree << endl;

    LinkedList<ITEM_TYPE>* L = BST_to_LinkedList(btree);
    cout << "bst to link: " << *L << endl;
}