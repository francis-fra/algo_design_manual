// Chapter 3 Data Structures
// queue and stack
// import * from "./ListNode"
import {LinkedNode, search_item, insert_item, delete_item} from "./ListNode"
import {Queue} from "./queue"
import {Stack} from "./stack"
import {BinaryTree, insert_tree, traverse_tree, search_tree, 
    find_min, delete_tree} from "./btree"
import * as fs from "fs"
import {sprintf} from "sprintf-js"
import * as sp from "sprintf-js"
// import sprintf from "sprintf-js"
// import fs = require('fs')

// var fs = require("fs");

function testCode() {

    // root
    let root = new LinkedNode<number>()

    console.log("Before...")
    console.log("Node: " + root)
    // console.log("Data: " + node.data)
    // console.log("Next: " + node.next)

    let node2 = new LinkedNode<number>(10)
    let node3 = new LinkedNode<number>(1)

    // joining the nodes
    root.next = node2
    node2.next = node3

    console.log("After...")
    console.log("Node: " + root)

    console.log("Insert data...")
    root = insert_item(root, 8)
    console.log("Node: " + root)

    let foundNode = search_item(root, 1)
    console.log("Found: " + foundNode)

    // foundNode = search_item(root, 100)
    // console.log("Found: " + foundNode)

    // let newroot = delete_item(root, 10)
    // console.log("New List: " + newroot)

    // delete node

}

// testCode()


function testQueue() {
    let queue = new Queue<number>()

    console.log("Init Queue: " + queue)
    console.log(queue.peek())

    queue.enqueue(10)
    queue.enqueue(5)
    console.log("after... " + queue)

    console.log("Popped: " + queue.dequeue())
    console.log("after... " + queue)
}

// testQueue()

function testStack() {
    let stack = new Stack<number>()

    console.log("init stack: " + stack)
    console.log(stack.peek())

    stack.push(10)
    stack.push(5)
    console.log("after... " + stack)

    console.log("popped: " + stack.pop())
    console.log("after... " + stack)
}

// testStack()

function testBTree() {

    let btree : BinaryTree<number> = null
    // let btree = new BinaryTree<number>(20)

    console.log("init tree: " + btree)
    btree = insert_tree(btree, 10, btree)

    console.log("after... " + btree)
    btree = insert_tree(btree, 1, btree)
    btree = insert_tree(btree, 20, btree)
    // console.log(btree == null)
    console.log("after... " + btree)

    // console.log("popped: " + stack.pop())
    // console.log("after... " + stack)
}
  
function readTest() : number[] {
    let rawdata = fs.readFileSync("../data/numbers.txt", "utf8")
    let data : number[] = rawdata.split(' ').map(function (x) { 
                                                    return parseInt(x, 10)} )
    return data
}

let data = readTest()

function StackTest(data: number[]) {

    let stack = new Stack<number>()
    for (var num of data) {
        stack.push(num)
    }
    while (! stack.isEmpty()) {
        let value = stack.pop() 
        console.log(value)
    }
}

function QueueTest(data: number[]) {

    let queue = new Queue<number>()
    for (var num of data) {
        queue.enqueue(num)
    }
    while (! queue.isEmpty()) {
        let value = queue.dequeue() 
        console.log(value)
    }
}

// do some test here
// console.log("Stack Test:")
// StackTest(data)
// console.log("Queue Test:")
// QueueTest(data)

function TreeTest(data: number[]) {

    let btree : BinaryTree<number> = null
    for (var num of data) {
        btree = insert_tree(btree, num, btree)
    }

    console.log(btree.toString())
    let show_data = function(data: number) {
        console.log(sprintf("%d", data))
    }
    traverse_tree(btree, show_data) 

    // search tree
    let outcome = search_tree(btree, 1);
    // let outcome = search_tree(btree, 7);
    console.log(outcome.toString())

    console.log("Deleting node... ")
    // FIXME: delete root
    // outcome = delete_tree(btree, 4)
    outcome = delete_tree(btree, 9)
    outcome = delete_tree(outcome, 3)
    outcome = delete_tree(outcome, 5)
    traverse_tree(outcome, show_data) 

    // let notree = search_tree(btree, 50);
    // console.log(notree)

    // find min
    // outcome = find_min(btree)
    // console.log("min = " + outcome.data)

}

TreeTest(data)
// console.log(sprintf("%1$s", "hello"))
// testBTree()