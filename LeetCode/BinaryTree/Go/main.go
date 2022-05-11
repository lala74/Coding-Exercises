package main

import (
	"fmt"
)

type Stack []interface{}

func (s *Stack) IsEmpty() bool {
	return len(*s) == 0
}

func (s *Stack) Len() int {
	return len(*s)
}

func (s *Stack) Push(v interface{}) {
	*s = append(*s, v)
}

func (s *Stack) Pop() interface{} {
	if s.IsEmpty() {
		return nil
	}
	index := len(*s) - 1
	value := (*s)[index]
	(*s) = (*s)[:index]
	return value
}

func (s *Stack) Peek() interface{} {
	if s.IsEmpty() {
		return nil
	}
	return (*s)[len(*s)-1]
}

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func main() {
	root := &TreeNode{Val: 1}
	root.Left = &TreeNode{Val: 3}
	root.Right = &TreeNode{Val: 2}
	root.Left.Left = &TreeNode{Val: 4}
	root.Left.Right = &TreeNode{Val: 5}
	order := postorderTraversal(root)
	fmt.Println(order)
	// s := Stack{}
	// s.Push(1)
	// s.Push(2)
	// s.Push(3)
	// s.Push(4)
	// s.Push(5)
	// s.Pop()
	// s.Pop()
	// s.Pop()
	// fmt.Println("len", s.Len())
}

// POSTORDER
func postorderTraversal(root *TreeNode) []int {
	result := []int{}
	postorderIteration(root, &result)
	// postorderRecursion(root, &result)
	return result
}

func postorderIteration(root *TreeNode, result *[]int) {
	if root == nil {
		return
	}
	s := Stack{}
	current := root
	s.Push(current)
	for s.Len() != 0 {
		if current != nil {
			s.Push(current)
			current = current.Left
			continue
		}
		node := s.Peek().(*TreeNode)
		current = node.Right
		if current == nil {
			s.Pop()
			*result = append(*result, node.Val)
		}
	}
	*result = (*result)[:len(*result)-1]
}

func postorderRecursion(root *TreeNode, result *[]int) {
	if root == nil {
		return
	}
	postorderRecursion(root.Left, result)
	postorderRecursion(root.Right, result)
	*result = append(*result, root.Val)
}

// PREORDER
func preorderTraversal(root *TreeNode) []int {
	result := []int{}
	if root == nil {
		return nil
	}
	// inorderRecursion(root, &result)
	preorderInteration(root, &result)
	return result
}

func preorderInteration(root *TreeNode, result *[]int) {
	s := Stack{}
	s.Push(root)
	for s.Len() != 0 {
		top := s.Pop().(*TreeNode)
		*result = append(*result, top.Val)
		if top.Right != nil {
			s.Push(top.Right)
		}
		if top.Left != nil {
			s.Push(top.Left)
		}
	}
}

// INORDER
func inorderTraversal(root *TreeNode) []int {
	result := []int{}
	if root == nil {
		return nil
	}
	inorderRecursion(root, &result)
	// inorderInteration(root, &result)
	return result
}

func inorderInteration(root *TreeNode, result *[]int) {
	s := Stack{}
	current := root
	s.Push(current)
	for s.Len() != 0 {
		if current != nil {
			s.Push(current)
			current = current.Left
		} else {
			node := s.Pop().(*TreeNode)
			*result = append(*result, node.Val)
			current = node.Right
		}
	}
	*result = (*result)[:len(*result)-1]
}

func inorderRecursion(root *TreeNode, result *[]int) {
	if root.Left != nil {
		inorderRecursion(root.Left, result)
	}
	*result = append(*result, root.Val)
	if root.Right != nil {
		inorderRecursion(root.Right, result)
	}
}
