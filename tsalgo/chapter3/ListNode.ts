// linked list structure

class LinkedNode<T> {

    protected _next: LinkedNode<T>
    // root has no data
    constructor(protected _data?: T) {
        this._next = null
        this._data = _data
    }
    get data(): T {
        return this._data
    }
    set data(x: T) {
        this._data = x
    }
    get next(): LinkedNode<T> {
        return this._next
    }
    set next(n: LinkedNode<T>) {
        this._next = n
    }
    toString() {
        return "Data: " + this._data + " -> " + this._next
    }
}


function search_item<T>(list: LinkedNode<T>, target: T) {
    if (list == null) return null

    if (list.data == target) {
        return list
    } else {
        return search_item(list.next, target)
    }
}

// insert at the front
function insert_item<T>(root: LinkedNode<T>, x: T) : LinkedNode<T> {
    let node = new LinkedNode<T>(x);
    node.next = root.next 
    root.next = node
    return root
}

// remove node which match the data 
function delete_item<T>(root: LinkedNode<T>, x: T) : LinkedNode<T> {
    let parent = root 
    let child = parent.next

    while (child != null) {
        if (child.data == x) {
            parent.next = child.next
            break
        } else {
            parent = child
            child = child.next
        }
    }
    return root
}


export {LinkedNode, search_item, insert_item, delete_item}