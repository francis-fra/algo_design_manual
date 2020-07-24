#include <iostream>
#include "binary_tree.hpp"

using namespace std;

void test_case_01() {
    // btree<int> b(6);
    btree<int>* b = create_btree(6);
    insert_btree(b, 5);
    insert_btree(b, 8);
    insert_btree(b, 2);
    insert_btree(b, 7);
    traverse_btree(b, &print);
    cout << endl;

    delete b;
    // delete_btree(b);

}

void test_case_02() {
    btree<int>* b = create_btree({4,5,7,1});
    // FIXME: must be non-empty list
    // btree<int>* b = create_btree({});
    traverse_btree(b, &print);
    cout << endl;

    // copy constructor (copy the pointers and item)
    btree<int> clone(*b);
    traverse_btree(&clone, &print);
    cout << endl;
    
    // add a node to b and check clone
    insert_btree(b, 10);
    traverse_btree(&clone, &print);
    cout << endl;

    // a pointer
    btree<int> *result;
    // result = search_tree(b, 6);
    result = search_tree(b, 7);
    // result = b;
    if (result != nullptr) {
        cout << "Found " << result->get() << endl;
    } else {
        cout << "Not found" << endl;
    }

    cout << "min of btree = " << min(b) << endl;

}

int main(void) {
    // test_case_01();
    test_case_02();
}