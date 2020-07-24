#include "linkedlist.h"
#include <iostream>
using namespace std;

Node::Node() {
  this->item = 0;
  this->next = NULL;
};

Node::Node(itemType item) {
  this->item = item;
  this->next = NULL;
};

void Node::set(itemType item) {
  this->item = item;
}

void Node::show() {
  cout << this->item << endl;
}

void Node::setNext(Node* node) {
  this->next = node;
}

Node *Node::getNext() {
  return this->next;
}

itemType Node::getItem() {
  return this->item;
}

// Node::~Node() {
//
// };

itemType addOne(itemType item) {
  return (item + 1);
}

LinkedList::LinkedList() {
  this->root = NULL;
};

LinkedList::LinkedList(itemType item) {
  Node* node = new Node(item);
  this->root = node;
};

LinkedList::~LinkedList() {
  Node *p = this->root;
  Node *next;
  while (p != NULL) {
    next = p->getNext();
    cout << "Deleting " << p->getItem() << endl;
    delete p;
    p = next;
  }
}

void LinkedList::insert(itemType item) {

  // new node will becomes the first node
  Node *node = new Node(item);
  node->setNext(this->root);

  // poin the new node to the root
  this->root = node;
};

// f is a pointer function
void LinkedList::traverse_list(NodeFunc f) {

  Node* node = this->root;
  while (node != NULL) {
    // call the member function of Node (*node)
    (*node.*f) ();
    node = node->getNext();
  }
}

// take a "map" function to change value of the node
void LinkedList::traverse_list(itemType (*f) (itemType)) {

  Node* node = this->root;
  itemType item;
  while (node != NULL) {
    item = f(node->getItem());
    node->set(item);
    node = node->getNext();
  }
}

// find the parent of node containing item
Node *LinkedList::predecessor(itemType item) {
  Node* node = this->root;
  Node* parent = NULL;
  while (node != NULL) {
    if (node->getItem() == item) {
      return parent;
    } else {
      parent = node;
      node = node->getNext();
    }
  }
  return NULL;
}
