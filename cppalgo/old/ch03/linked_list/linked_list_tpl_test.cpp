#include <iostream>
// #include "linked_list_node.h"
// #include "linked_list.h"
#include "linked_list.hpp"

using namespace std;

void test_case_01() {

    // head is 0 (dummy)
    LinkedNode<int> *head = create_Node(0);
    insert_list(head, 5);
    insert_list(head, 4);
    insert_list(head, 8);
    // head value is ignored
    traverse_list(head, &print_node);
    // traverse_list(head);
    free_list(head);
    delete_Node(head);
}

void test_case_02() {

    LinkedNode<int> *head = create_Node(0);
    insert_list(head, 5);
    insert_list(head, 4);
    traverse_list(head, &print_node);
    free_list(head);
    delete_Node(head);

}

void test_case_03() {

    LinkedNode<int> *head = create_linked_list({5,7,1,2});
    traverse_list(head, &print_node);
    free_list(head);
    delete_Node(head);
}

void test_case_04() {

    LinkedNode<int> *head = create_linked_list({5,7,1,2});
    // clone
    LinkedNode<int> clone(*head);
    traverse_list(&clone, &print_node);

    // insert to head only - check clone again
    insert_list(head, 4);
    // head is different: but the rest should have the same link
    traverse_list(&clone, &print_node);
    traverse_list(head, &print_node);

    // delete node
    remove_node(head);
    remove_node(head);
    cout << "clone: ";
    traverse_list(&clone, &print_node);
    cout << "original: ";
    traverse_list(head, &print_node);

    free_list(head);
    delete_Node(head);
}

void test_case_05() {

    LinkedNode<int> *head = create_Node(0);
    insert_list(head, 8);
    insert_list(head, 4);
    // insert_list(head, 1);
    // insert_list(head, 5);
    cout << "before: ";
    traverse_list(head, &print_node);
    remove_node(head);
    remove_node(head);
    cout << "after: ";
    traverse_list(head, &print_node);
    free_list(head);
    delete_Node(head);
}

int main(void) {
    // test_case_01();
    // test_case_02();
    // test_case_03();
    test_case_04();
    // test_case_05();
}