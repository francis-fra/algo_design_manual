package ch03;

public class LinkedList<T> {
    private LinkedNode head;

    public LinkedList() {
        head = null;
    }

    // insert a node at the end
    public void insert(T value) {
        if (head == null) {
            head = new LinkedNode(value);
        } else {
            LinkedNode node = head;
            while (node.next_node() != null) {
                node = node.next_node();
            }
            // add at the end of the list
            node.set_next_node(new LinkedNode(value));
        }
    }

    // TODO: add function
    public void traverse(NodeMethod<T> P) {
        LinkedNode node = head;
        while(node != null) {
            P.execute(node);
            node = node.next_node();
        }

    }

    // remove item from the head
    public void delete() {
        if (head == null) {
            return;
        } else {
            LinkedNode node = head.next_node();
            node.set_next_node(node.next_node());
        }

    }

    public static void main(String[] argv) {
        LinkedList<Integer> linked_list = new LinkedList<Integer>();
        linked_list.insert(5);
        linked_list.insert(8);
        PrintNode<Integer> P = new PrintNode<Integer>();
        linked_list.traverse(P);
    }
}