package bst_test

import (
	// "fmt"
	"github.com/stretchr/testify/assert"
	"testing"
	bst "../bst"
)

func TestCreateNode(t *testing.T) {
	var one *bst.Bst = bst.CreateNode(1)
	assert.Equal(t, one.Item, bst.ItemType(1))
}

func TestInsertNode(t *testing.T) {
	var tree *bst.Bst
	tree = bst.InsertNode(tree, 9)
	// var node *bst.Bst = bst.CreateNode(9)
	// var tree *bst.Bst = bst.CreateNode(9)
	// fmt.Println(*tree)
	tree = bst.InsertNode(tree, 3)
	// fmt.Println(*tree)
	assert.Equal(t, bst.GetLeft(tree), bst.ItemType(3))
}

func TestToSlice(t *testing.T) {
	var tree *bst.Bst = bst.CreateNode(9)
	bst.InsertNode(tree, 3)
	bst.InsertNode(tree, 1)
	s := bst.ToSlice(tree)
	assert.Equal(t, s, []bst.ItemType{1, 3, 9})
}

func TestLength(t *testing.T) {
	assert.Equal(t, bst.Len(nil), 0)
	var tree *bst.Bst = bst.CreateNode(9)
	assert.Equal(t, bst.Len(tree), 1)
	bst.InsertNode(tree, 3)
	bst.InsertNode(tree, 1)
	assert.Equal(t, bst.Len(tree), 3)
}

// see page 81 Design Manual
func TestDelete(t *testing.T) {
	var tree *bst.Bst = bst.CreateNode(2)
	bst.InsertNode(tree, 1)
	bst.InsertNode(tree, 7)
	bst.InsertNode(tree, 8)
	bst.InsertNode(tree, 4)
	bst.InsertNode(tree, 6)
	bst.InsertNode(tree, 3)
	bst.InsertNode(tree, 5)
	s := bst.ToSlice(tree)
	assert.Equal(t, s, []bst.ItemType{1, 2, 3, 4, 5, 6, 7, 8})

	bst.DeleteNode(tree, 3)
	s = bst.ToSlice(tree)
	assert.Equal(t, s, []bst.ItemType{1, 2, 4, 5, 6, 7, 8})

	// revert
	bst.InsertNode(tree, 3)
	bst.DeleteNode(tree, 6)
	s = bst.ToSlice(tree)
	// assert.Equal(t, s, []bst.ItemType{1, 2, 3, 4, 5, 6, 7, 8})
	assert.Equal(t, s, []bst.ItemType{1, 2, 3, 4, 5, 7, 8})

	// revert
	bst.InsertNode(tree, 6)
	s = bst.ToSlice(tree)
	assert.Equal(t, s, []bst.ItemType{1, 2, 3, 4, 5, 6, 7, 8})
	bst.DeleteNode(tree, 4)
	s = bst.ToSlice(tree)
	assert.Equal(t, s, []bst.ItemType{1, 2, 3, 5, 6, 7, 8})
}

func TestMoreDelete(t *testing.T) {
	var tree *bst.Bst = bst.CreateNode(2)
	bst.InsertNode(tree, 1)
	bst.InsertNode(tree, 7)
	bst.InsertNode(tree, 8)
	bst.InsertNode(tree, 4)
	bst.InsertNode(tree, 6)
	bst.InsertNode(tree, 3)
	bst.InsertNode(tree, 5)
	s := bst.ToSlice(tree)
	assert.Equal(t, s, []bst.ItemType{1, 2, 3, 4, 5, 6, 7, 8})

	bst.DeleteNode(tree, 4)
	s = bst.ToSlice(tree)
	assert.Equal(t, s, []bst.ItemType{1, 2, 3, 5, 6, 7, 8})
}

func TestRootDelete(t *testing.T) {
	var tree *bst.Bst = bst.CreateNode(2)
	tree = bst.DeleteNode(tree, 2)
	s := bst.ToSlice(tree)
	assert.Equal(t, s, []bst.ItemType{})

	tree = nil
	tree = bst.DeleteNode(tree, 2)
	assert.Equal(t, s, []bst.ItemType{})

	tree = bst.InsertNode(tree, 2)
	bst.InsertNode(tree, 1)
	s = bst.ToSlice(tree)
	assert.Equal(t, s, []bst.ItemType{1, 2})

	tree = bst.DeleteNode(tree, 1)
	s = bst.ToSlice(tree)
	assert.Equal(t, s, []bst.ItemType{2})

}

// func TestRootDelete(t *testing.T) {

// }