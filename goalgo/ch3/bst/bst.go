package bst

import (
	// "fmt"
)

type ItemType rune

type Bst struct {
	// public
	Item ItemType
	// private
	parent *Bst
	left *Bst
	right *Bst
}

func CreateNode(item ItemType) *Bst {
	tree := Bst{item, nil, nil, nil}
	return &tree
}

// accessor
func GetLeft(tree *Bst) ItemType {
	if tree.left == nil {
		panic("Empty Node")
	}
	return tree.left.Item
}

func GetRight(tree *Bst) ItemType {
	if tree.right == nil {
		panic("Empty Node")
	}
	return tree.right.Item
}

// return needed in case of nil tree
func InsertNode(tree *Bst, item ItemType) *Bst {
	if tree == nil {
		tree = CreateNode(item)
	} else {
		insert(tree, nil, item)
	}
	return tree
}

func insert(tree, parent *Bst, item ItemType) {
	if item < tree.Item {
		// insert to left
		if tree.left == nil {
			node := CreateNode(item)
			node.parent = tree 
			tree.left = node
		} else {
			insert(tree.left, tree, item)
		}
	} else {
		// insert to right 
		if tree.right == nil {
			node := CreateNode(item)
			node.parent = tree 
			tree.right = node
		} else {
			insert(tree.right, tree, item)
		}
	}
}

func ForEach(tree *Bst, f func(ItemType)) {
	if tree == nil {
		return
	} else {
		ForEach(tree.left, f)
		f(tree.Item)
		ForEach(tree.right, f)
	}
}

func ToSlice(tree *Bst) []ItemType {
	result := []ItemType{}
	result = appendItem(tree, result)
	return result
}

// private
func appendItem(tree *Bst, s []ItemType) []ItemType {

	if tree == nil {
		return s
	} else {
		s = appendItem(tree.left, s)
		s = append(s, tree.Item)
		s = appendItem(tree.right, s)
		return s
	}
}

// private
func attachNodeToGrandparent(grandparent, parent, promotedNode *Bst) {
	// need parent to find if attaching to left or right
	if grandparent == nil {
		return
	} else {
		if isChildOnLeft(grandparent, parent) {
			grandparent.left = promotedNode
		} else {
			grandparent.right = promotedNode
		}
	}
}

func attachGrandParentToNode(grandparent, promotedNode *Bst) {
	promotedNode.parent = grandparent
}

func replaceTreeBranch(source, dest *Bst) {
	// avoid loop
	if dest != source.right {
		dest.right = source.right
	}
	if dest != source.left {
		dest.left = source.left
	}
}

func detachFromParent(node *Bst) {
	parent := node.parent
	if isChildOnLeft(parent, node) {
		parent.left = nil
	} else {
		parent.right = nil
	}
}


// private
func numChild(tree *Bst) int {
	leftChild := 0
	rightChild := 0
	if tree.left != nil {
		leftChild++
	}
	if tree.right !=nil {
		rightChild++
	}
	return leftChild + rightChild
}

// recursion
func DeleteNode(tree *Bst, item ItemType) *Bst {
	if (tree == nil) {
		return tree
	} else if tree.Item == item {
		grandparent := tree.parent
		// check if there is one child, two children or nil
		if numChild(tree) == 0 {
			// DEBUG
			// fmt.Printf("grandparent: %v\n", grandparent)
			// fmt.Printf("tree: %v\n", tree)
			// fmt.Printf("grandparent.parent: %v\n", grandparent.parent)

			if grandparent == nil {
				// this is the root
				return nil
			} else if grandparent.parent != nil {
				// there is a grandparent
				if isChildOnLeft(grandparent.parent, grandparent) {
					grandparent.left = nil
				} else {
					grandparent.right = nil
				}
			} else {
				// only one node above tree
				if grandparent.left == tree {
					grandparent.left = nil
				} else {
					grandparent.right = nil
				}
				return grandparent
			}

			// remove
			tree = nil
		} else if numChild(tree) == 1 {
			// attach grandparent to the promoted grandchild
			if tree.left != nil {
				attachNodeToGrandparent(grandparent, tree, tree.left)
				attachGrandParentToNode(grandparent, tree.left)
			} else {
				// must be on the right
				attachNodeToGrandparent(grandparent, tree, tree.right)
				attachGrandParentToNode(grandparent, tree.right)
			}
			// remove current node
			tree = nil
		} else {
			// two children: promote the leftmost node on the right
			promotedNode := getLeftMostNode(tree.right)

			// downstrams - left/right link
			// update grandparent left/right links
			attachNodeToGrandparent(grandparent, tree, promotedNode)
			// update promoted Node left/right link
			replaceTreeBranch(tree, promotedNode)
			// detach promotedNode parent
			detachFromParent(promotedNode)

			// upstrams - update parent link
			attachGrandParentToNode(grandparent, promotedNode)
			// remove current
			tree = nil

		}
	} else if tree.Item > item {
		// fmt.Printf("%d: route left\n", tree.Item)
		DeleteNode(tree.left, item)
	} else if tree.Item < item {
		// fmt.Printf("%d: route right\n", tree.Item)
		DeleteNode(tree.right, item)
	}
	return tree
}


func isChildOnLeft(parent *Bst, child *Bst) bool {
	return parent.left == child 
}

// private
func getLeftMostNode(tree *Bst) *Bst {
	if tree.left == nil {
		return tree
	} else {
		return getLeftMostNode(tree.left)
	}
}

func Len(tree *Bst) int {
	if tree == nil {
		return 0
	} else {
		return Len(tree.left) + 1 + Len(tree.right)
	}
}

// TODO: map

// TODO: reduce

// TODO: min / max




// func attachNode(tree *Bst, node *Bst) *Bst {
// 	node.parent = tree
// 	return tree
// }
