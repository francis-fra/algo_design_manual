package main

import (
	"fmt"
	ll "../linkedlist"
	bst "../bst"
)

// use testing instead
func main() {
	// var lst ll.List
	// fmt.Println(lst)
	var one *ll.List = ll.CreateNode(1)

	one = ll.InsertNode(one, 3)
	fmt.Println(*one)
	fmt.Println(one.Item)

	// ll.ForEach(one, func(item ll.ItemType) { fmt.Println(item)} )

	fmt.Println(ll.ToString(one))

	var lst = ll.ToList([]ll.ItemType{1,2,4})
	fmt.Println(ll.ToString(lst))


	lst = ll.MakeList(7,8,9,10)
	fmt.Println(ll.ToString(lst))

	ll.DeleteNode(lst, 9)
	fmt.Println(ll.ToString(lst))


	// BST
	// var tree *bst.Bst = bst.CreateNode(9)
	// bst.InsertNode(tree, 3)
	// bst.InsertNode(tree, 13)
	// bst.ForEach(tree, func(item bst.ItemType) { fmt.Println(item)})

	var tree *bst.Bst = bst.CreateNode(2)
	bst.InsertNode(tree, 1)
	bst.InsertNode(tree, 7)
	bst.InsertNode(tree, 8)
	bst.InsertNode(tree, 4)
	bst.InsertNode(tree, 6)
	bst.InsertNode(tree, 3)
	bst.InsertNode(tree, 5)
	fmt.Println(bst.ToSlice(tree))
	// 6 has changed position
	bst.DeleteNode(tree, 6)
	bst.InsertNode(tree, 6)
	fmt.Println(bst.ToSlice(tree))

	bst.DeleteNode(tree, 4)
	fmt.Println(bst.ToSlice(tree))

	tree = bst.CreateNode(2)
	bst.InsertNode(tree, 1)
	fmt.Println(bst.ToSlice(tree))

	tree = bst.DeleteNode(tree, 1)
	fmt.Println(bst.ToSlice(tree))

}