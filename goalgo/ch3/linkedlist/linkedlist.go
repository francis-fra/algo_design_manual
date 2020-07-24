package linkedlist

import (
	// "fmt"
	"strconv"
)

type ItemType rune

// capitalize the field for export
type List struct {
	Item ItemType 
	next *List 
}


func CreateNode(item ItemType) *List {
	list := List{item, nil}
	return &list
}

// insert at the back
func InsertNode(lst *List, item ItemType) *List {

	newNode := CreateNode(item)
	node := lst
	for node.next != nil {
		node = node.next
	}
	node.next = newNode
	return lst
}

func Search(lst *List, item ItemType ) *List {

	// tail recursive
	if lst == nil {
		return lst
	} else {
		if lst.Item == item {
			return lst
		} else {
			return Search(lst.next, item)
		}
	}
	// node := lst
	// if node.Item == item {
	// 	return node 
	// }

	// for node.next != nil {
	// 	node = node.next
	// 	if node.Item == item {
	// 		return node 
	// 	}
	// }
	// return nil
	
}

func DeleteAll(lst *List, item ItemType) *List {
	// parent of head is nil
	var parent *List
	node := lst
	for node != nil {
		// item found
		if node.Item == item {
			// delete this 
			if parent == nil {
				lst = node.next
			} else {
				parent.next = node.next
			}
		} 
		// advance node
		parent = node
		node = node.next
	}

	return lst

}

// delete the first node found
func DeleteNode(lst *List, item ItemType) *List {

	// parent of head is nil
	var parent *List
	node := lst
	for node != nil {
		// item found
		if node.Item == item {
			// delete this 
			if parent == nil {
				lst = node.next
				break
			} else {
				parent.next = node.next
				break
			}
		} else {
			// advance node
			parent = node
			node = node.next
		}
	}

	return lst
}


// slice to List
func ToList(lst []ItemType) *List {

	if len(lst) == 0 {
		return nil
	} else {
		// insert point
		var result *List
		// head of list (to be returned)
		var head *List
		for _, item := range lst {
			// create node for each item
			node := CreateNode(item)
			if result == nil {
				// init
				result = node
				// pointer to be returned
				head = result
			} else {
				// advancing the insertion point
				result.next = node
				result = result.next
			}
		}
		return head
	}

}

// varidac item to List (similar to ToList())
func MakeList(items... ItemType) *List {

	if len(items) == 0 {
		return nil
	} else {
		// insert point
		var result *List
		// head of list (to be returned)
		var head *List
		for _, item := range items {
			// create node for each item
			node := CreateNode(item)
			if result == nil {
				// init
				result = node
				// pointer to be returned
				head = result
			} else {
				// advancing the insertion point
				result.next = node
				result = result.next
			}
		}
		return head
	}

}



// list to slice
func ToSlice(lst *List) []ItemType {
	var result []ItemType
	var insert func(lst *List)

	// add result as closure to an anonymous function
	insert = func() func(lst *List) {
		return func(lst *List) {
			for lst != nil {
				result = append(result, lst.Item)
				lst = lst.next
			}
		}
	}()
	insert(lst)
	return result
}

// length of list
func Len(lst *List) int {
	length := 0
	for lst != nil {
		length++
		lst = lst.next
	}
	return length

}

// reduce
func Reduce(lst *List, f func(acc, item ItemType) ItemType, init ItemType) ItemType {
	acc := init
	for lst != nil {
		acc = f(acc, lst.Item)
		lst = lst.next
	}
	return acc
}

// in place map
func ForEach(lst *List, f func(item ItemType)) {
	node := lst
	f(node.Item)
	for node.next != nil {
		node = node.next
		f(node.Item)
	}
}

// print list
// func Print(lst *List) {
// 	ForEach(lst, func(item ItemType) { fmt.Printf("%d >> ", item)} )
// 	fmt.Printf("||\n")
// }


// show as string
func ToString(lst *List) string {
	result := ""
	for lst != nil {
		result += (strconv.Itoa(int(lst.Item)) + " >> ")
		lst = lst.next
	}
	result += "||"
	return result
}