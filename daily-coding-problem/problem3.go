/*
Good morning! Here's your coding interview problem for today.

This problem was asked by Google.

Given the root to a binary tree, implement serialize(root), which serializes the tree into a string, and deserialize(s), which deserializes the string back into the tree.

For example, given the following Node class

class Node:
    def __init__(self, val, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
The following test should pass:

node = Node('root', Node('left', Node('left.left')), Node('right'))
assert deserialize(serialize(node)).left.left.val == 'left.left'
*/
package main

import (
	"fmt"
)

type Node struct {
	val   string
	left  *Node
	right *Node
}

type Queue []*Node

func (q *Queue) Push(n *Node) {
	*q = append(*q, n)
}

func (q *Queue) Pop() (n *Node) {
	n = (*q)[0]
	*q = (*q)[1:]
	return
}

func (q *Queue) Len() int {
	return len(*q)
}

func (q *Queue) Empty() bool {
	return len(*q) == 0
}

func serialize(n *Node, height uint) []*Node {
	bfs_tree := make([]*Node, 0, (1 << height))
	q := make(Queue, 0, (1 << height))
	q.Push(n)
	for !q.Empty() {
		c := q.Pop()
		if c == nil || c.val == "nil" {
			bfs_tree = append(bfs_tree, &Node{"nil", nil, nil})
			continue
		}
		q.Push(c.left)
		q.Push(c.right)
		bfs_tree = append(bfs_tree, c)
	}
	return bfs_tree
}
func deserialize(bfs_tree []*Node, height uint) *Node {
	if len(bfs_tree) == 0 {
		return nil
	}
	q := make(Queue, 0, (1 << height))
	tree := bfs_tree[0]
	q.Push(tree)
	for j := 1; !q.Empty() && j < len(bfs_tree); j += 2 {
		c := q.Pop()
		if c == nil {
			continue
		}
		c.left = bfs_tree[j]
		c.right = bfs_tree[j+1]
		q.Push(c.left)
		q.Push(c.right)
	}
	return tree
}
func main() {
	fmt.Println("Problema 3")
	n := Node{"R", &Node{"l", &Node{"ll", nil, nil}, nil}, &Node{"r", nil, nil}}
	bfs_tree := serialize(&n, 3)
	for x := range bfs_tree {
		fmt.Println(bfs_tree[x].val)
	}
	bfs_tree = serialize(deserialize(bfs_tree, 3), 3)
	for x := range bfs_tree {
		fmt.Println(bfs_tree[x].val)
	}

	equal := (deserialize(serialize(&n, 3), 3).left.left.val == "ll")
	fmt.Println(equal)
}
