// binary tree structure

class BinaryTree<T> {
    protected _left: BinaryTree<T>
    protected _right: BinaryTree<T>

    constructor(protected _data?: T, protected _parent?: BinaryTree<T>) {
        this._parent = _parent
        this._left = null
        this._right = null
        this._data = _data
    }

    get parent(): BinaryTree<T> {
        return this._parent
    }
    set parent(parent: BinaryTree<T>) {
        this._parent = parent
    }

    get data(): T {
        return this._data
    }
    set data(x: T) {
        this._data = x
    }

    get left(): BinaryTree<T> {
        return this._left
    }
    get right(): BinaryTree<T> {
        return this._right
    }

    set left(n: BinaryTree<T>) {
        this._left = n
    }
    set right(n: BinaryTree<T>) {
        this._right = n
    }

    toString() {
        return this._data + " ( " + "left -> " + this._left + ", right -> " + this._right + " )"
        // return this._left + " -> " + this._data + " -> " + this._right
    }


}

// return the updated node
function insert_tree<T>(root: BinaryTree<T>, data: T, parent: BinaryTree<T>) : BinaryTree<T> {
    if (root == null) {
        let node = new BinaryTree<T>(data, parent)
        root = node
    } else {
        if (root.data > data) {
            let left_node = insert_tree(root.left, data, root)
            // IMPORTANT: update the branch
            root.left = left_node
        } else {
            let right_node = insert_tree(root.right, data, root)
            // IMPORTANT: update the branch
            root.right = right_node
        }
    }
    return root
}

// return the node of the leftmost branch
function find_min<T>(root: BinaryTree<T>): BinaryTree<T> {
    if (root == null) {
        return null
    }
    else if (root.left == null) {
        return root
    } else {
        return find_min(root.left)
    }
}

function find_max<T>(root: BinaryTree<T>): BinaryTree<T> {
    if (root.right == null) {
        return root
    } else {
        return find_min(root.right)
    }
}

// FIXME: remove root required
// if leftmost is not null: move the leftmost descendent from the right subtree
// if leftmost if null: move the rightmost descendent from the left subtree
function delete_tree<T>(root: BinaryTree<T>, data: T) : BinaryTree<T> {
    let node = search_tree(root, data)
    // no such node
    if (node == null) {
        // do nothing
    } else if (node.right == null && node.left == null) {
        // this is a leaf node
        remove_parent_link(node)
        // let parent = node.parent
        // if (parent.left == node) {
        //     parent.left = null
        // } else {
        //     parent.right = null
        // }
        // return root
    } else if (node.left != null) {
        // find the rightmost of the left
        let replacement = find_max(node.left)
        replace_node(node, replacement)
    } else {
        // find the leftmost of the right
        let replacement = find_min(node.right)
        replace_node(node, replacement)
    }
    return root
}

// the parent of 'node' has a child of 'replacement'
function steal_parent<T>(node: BinaryTree<T>, replacement: BinaryTree<T>) {
    let parent = node.parent
    if (parent.left == node) {
        parent.left = replacement
    } else {
        parent.right = replacement
    }
}

// replacement's parent lost replacement as child
function remove_parent_link<T>(replacement: BinaryTree<T>) {
     let replacement_parent = replacement.parent
    // delete link of replacement and its parent
    if (replacement_parent.left == replacement) {
        replacement_parent.left = null
    } else {
        replacement_parent.right = null
    }
}

function clone_child_links<T>(node: BinaryTree<T>, replacement: BinaryTree<T>) {
    // get also node's children
    if (node.left != replacement)
        replacement.left = node.left
    if (node.right != replacement)
        replacement.right = node.right
}

function assign_parent<T>(node: BinaryTree<T>, parent: BinaryTree<T>) {
    node.parent = parent
}

function replace_node<T>(node: BinaryTree<T>, replacement: BinaryTree<T>) {

    // establish new_parent -> child link
    steal_parent(node, replacement)
    // remove parent -> child link
    remove_parent_link(replacement)
    // re-establish child -> parent link
    assign_parent(replacement, node.parent)
    // get all child from node
    clone_child_links(node, replacement)
}

// return the tree node which contain the data
function search_tree<T>(root: BinaryTree<T>, data: T): BinaryTree<T> {
    if (root == null) {
        return null
    } else if (root.data == data) {
        return root
    } else if (data < root.data) {
       return search_tree(root.left, data) 
    } else {
        return search_tree(root.right, data)
    }
}


// process the tree with the supplied function (wihtout side effec  t)
function traverse_tree<T>(tree: BinaryTree<T>, processor: (data: T) => void) {
    if (tree != null) {
        traverse_tree(tree.left, processor)
        processor(tree.data)
        traverse_tree(tree.right, processor)
    }
}


export {BinaryTree, insert_tree, traverse_tree, search_tree, find_min,
            delete_tree}