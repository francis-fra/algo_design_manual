#include <iostream>
using namespace std;
#include "linkedlist.h"

int main() {

    //lst = new LinkedList(9);
    // Node *node = new Node();
    /*
    Node *node = new Node(10);
    node->show();
    delete node;
    */

    LinkedList *lst = new LinkedList(10);
    lst->insert(20);
    lst->insert(40);

    // assign (the address) of show to f (a pointer function)
    NodeFunc show = &Node::show;
    lst->traverse_list(show);

    cout << "Add one..." << endl;
    lst->traverse_list(&addOne);
    lst->traverse_list(show);

    // find predecessor
    itemType item = 21;
    Node *parent = lst->predecessor(item);
    cout << "Parent of " << item << " = " << parent->getItem() << endl;

    delete lst;
}
