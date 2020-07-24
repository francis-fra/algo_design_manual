package com.fra.jalgo.ch03;

public class LinkedList<T> {
    private LinkedNode<T> head;

    public LinkedList() {
        head = null;
    }

    // insert a node at the end
    public void insert(T value) {
        if (head == null) {
            head = new LinkedNode<T>(value);
        } else {
            LinkedNode<T> node = head;
            while (node.next_node() != null) {
                node = node.next_node();
            }
            // add at the end of the list
            node.set_next_node(new LinkedNode<T> (value));
        }
    }

    // method P
    public void traverse(NodeMethod<T> P) {
        LinkedNode<T> node = head;
        while(node != null) {
            P.execute(node);
            node = node.next_node();
        }

    }

    // remove item from the head
    public T delete() {
        if (head == null) {
            return null;
        } else {
            T item = head.get();
            LinkedNode<T> node = head.next_node();
            if (node != null) {
                node.set_next_node(node.next_node());
                head = node;
            } else {
                head = null;
            }
            return item;
        }

    }

    public static void main(String[] argv) {
        LinkedList<Integer> linked_list = new LinkedList<Integer>();
        linked_list.insert(1);
        linked_list.insert(2);
        linked_list.insert(3);

        PrintNode<Integer> P = new PrintNode<Integer>();
        int value = linked_list.delete();
        System.out.printf("deleted...%d\n", value);
        value = linked_list.delete();
        System.out.printf("deleted...%d\n", value);

        linked_list.traverse(P);
    }
}