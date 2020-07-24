import {LinkedNode} from "./ListNode"

// FIFO
class Queue<T> {

    private size: number
    private root: LinkedNode<T>

    constructor() {
        this.root = new LinkedNode<T>()
        this.size = 0
    }

    toString() : string {
        return "Data: " + this.root.data + " -> " + this.root.next
    }

    peek(): T {
        if (this.size == 0)
            return null
        else
            return this.root.next.data   // root has not data
    }
    
    // remove at the front
    dequeue(): T {
        let parent = this.root
        let child = this.root.next

        if (this.size == 0)
            return null 
        else {
            this.size--
            parent.next = child.next 
            this.root = parent
            return child.data
        }
    }

    // push at the end
    enqueue(x: T) : void {
        let node = this.root

        while (node.next != null) {
            node = node.next
        }
        let newNode = new LinkedNode<T>(x)
        node.next = newNode
        this.size++
    }

    isEmpty(): boolean {
        return this.size == 0
    }

}

export {Queue}