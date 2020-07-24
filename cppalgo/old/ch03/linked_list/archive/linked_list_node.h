#ifndef _LINKLIST_H
#define _LINKLIST_H

template <class T> 
class LinkedNode {
    private:
        T item;
        LinkedNode *next;
    public:
        LinkedNode(T value) {
            item = value;
            next = 0;
        }
        // accessors
        T get_item() {
            return item;
        }
        LinkedNode *next_node() {
            return this->next;
        }
        // setter
        void link(LinkedNode* node) {
            this->next = node;
        }
        // TODO: copy/move constructor
        // TODO: initializer list
        
};

#endif