import {LinkedNode} from "./ListNode"

// FILO
class Stack<T> {

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
    pop(): T {
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

    // push at the front 
    push(x: T) : void {
        let node = this.root

        let newNode = new LinkedNode<T>(x)
        newNode.next = node.next
        this.root.next = newNode
        this.size++
    }

    isEmpty(): boolean {
        return this.size == 0
    }

}

export {Stack}