#ifndef NULL
#define NULL 0
#endif

typedef int itemType;


class Node {

private:
  itemType item;
  Node *next;

public:
  Node();
  Node(itemType item);
  // ~Node();
  void set(itemType item);
  void setNext(Node* node);
  void show();
  Node *getNext();
  itemType getItem();
};

// define NodeFunc as a pointer to a member function of Node
typedef void ( Node::*NodeFunc ) ( );

class LinkedList {
private:
  Node *root;

public:
  LinkedList(itemType item);
  LinkedList();
  ~LinkedList();
  void insert(itemType item);
  // it takes f as a pointer function to a Node method
  void traverse_list(NodeFunc f);
  void traverse_list(itemType (*f) (itemType));
  Node *predecessor(itemType item);
};

itemType addOne(itemType item);

// TODO:
// void free_item(list *lst);
// void delete_list(list **lst, itemType item);
