package linkedlist_test

import (
	// "fmt"
	"github.com/stretchr/testify/assert"
	"testing"
	ll "../linkedlist"
)

// test suite for mynode API
// must start with captial Test and arg testing.T
func TestCreateNode(t *testing.T) {
	var one *ll.List = ll.CreateNode(1)
	assert.Equal(t, one.Item, ll.ItemType(1))
}

func TestLength(t *testing.T) {
	var one *ll.List = ll.CreateNode(1)
	one = ll.InsertNode(one, 3)
	assert.Equal(t, ll.Len(one), 2)
	assert.Equal(t, ll.Len(nil), 0)
}

func TestReduce(t *testing.T) {
	var one *ll.List = ll.CreateNode(1)
	one = ll.InsertNode(one, 3)

	f := func(a, b ll.ItemType) ll.ItemType { return a+b}
	assert.Equal(t, ll.Reduce(one, f, 0), ll.ItemType(4))

}

func TestToSlice(t *testing.T) {

	lst := ll.MakeList(7,8,9,10)
	arr := ll.ToSlice(lst)
	var answer = []ll.ItemType{7, 8, 9, 10}
	assert.Equal(t, arr, answer)
}

func TestSearch(t *testing.T) {

	lst := ll.MakeList(7,8,9,10)
	a := ll.Search(lst, 10)
	assert.Equal(t, a.Item, ll.ItemType(10))

	a = ll.Search(lst, 11)
	var empty *ll.List
	assert.Equal(t, a, empty)
}


func TestDelete(t *testing.T) {

	lst := ll.MakeList(7,8,9,10)
	ll.DeleteNode(lst, 9)
	ll.DeleteNode(lst, 8)
	lst = ll.DeleteNode(lst, 7)
	arr := ll.ToSlice(lst)
	var answer = []ll.ItemType{10}
	assert.Equal(t, arr, answer)

	// no deletion
	lst = ll.MakeList(7,8,9,10)
	lst = ll.DeleteNode(lst, 19)
	arr = ll.ToSlice(lst)
	answer = []ll.ItemType{7,8,9,10}
	assert.Equal(t, arr, answer)

}

func TestDeleteAll(t *testing.T) {

	lst := ll.MakeList(7,8,9,7)
	// ll.DeleteNode(lst, 9)
	// ll.DeleteNode(lst, 8)
	lst = ll.DeleteAll(lst, 7)
	arr := ll.ToSlice(lst)
	var answer = []ll.ItemType{8, 9}
	assert.Equal(t, arr, answer)

	lst = ll.MakeList(7,8,7,9,7)
	lst = ll.DeleteAll(lst, 7)
	arr = ll.ToSlice(lst)
	answer = []ll.ItemType{8, 9}
	assert.Equal(t, arr, answer)

	lst = ll.MakeList(7,8,7,9,7)
	lst = ll.DeleteAll(lst, 0)
	arr = ll.ToSlice(lst)
	answer = []ll.ItemType{7, 8, 7, 9, 7}
	assert.Equal(t, arr, answer)
}