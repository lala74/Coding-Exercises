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

func (s *Stack) Top() interface{} {
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
	// root.Left = &TreeNode{Val: 3}
	root.Right = &TreeNode{Val: 2}
	// root.Left.Left = &TreeNode{Val: 4}
	// root.Left.Right = &TreeNode{Val: 5}
	root.Right.Left = &TreeNode{Val: 3}
	order := postorderTraversal(root)
	fmt.Println(order)
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
	s.Push(root)
	// *result = append(*result, root.Val)
	lastPop := root
	for s.Len() != 0 {
		top := s.Top().(*TreeNode)
		if top.Left != nil && top.Left != lastPop && top.Right != lastPop { // push left
			s.Push(top.Left)
			continue
		}
		if top.Right != nil && top.Right != lastPop { // push right
			s.Push(top.Right)
			continue
		}
		lastPop = s.Pop().(*TreeNode)
		*result = append(*result, lastPop.Val) // visit pop
	}
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
	// inorderRecursion(root, &result)
	preorderInteration(root, &result)
	return result
}

func preorderInteration(root *TreeNode, result *[]int) {
	if root == nil {
		return
	}
	s := Stack{}
	s.Push(root)
	*result = append(*result, root.Val)
	lastPop := root
	for s.Len() != 0 {
		top := s.Top().(*TreeNode)
		if top.Left != nil && top.Left != lastPop && top.Right != lastPop { // push left
			s.Push(top.Left)
			*result = append(*result, top.Left.Val) // visit left
			continue
		}
		if top.Right != nil && top.Right != lastPop { // push right
			s.Push(top.Right)
			*result = append(*result, top.Right.Val) // visit left
			continue
		}
		lastPop = s.Pop().(*TreeNode)
	}
}

// INORDER
func inorderTraversal(root *TreeNode) []int {
	result := []int{}
	if root == nil {
		return nil
	}
	// inorderRecursion(root, &result)
	inorderInteration(root, &result)
	return result
}

func inorderInteration(root *TreeNode, result *[]int) {
	if root == nil {
		return
	}
	s := Stack{}
	s.Push(root)
	// *result = append(*result, root.Val)
	lastPop := root
	for s.Len() != 0 {
		top := s.Top().(*TreeNode)
		if top.Left != nil && top.Left != lastPop && top.Right != lastPop { // push left
			s.Push(top.Left)
			continue
		}
		if top.Right != nil && top.Right != lastPop { // push right
			s.Push(top.Right)
			*result = append(*result, top.Val) // visit top
			continue
		}
		lastPop = s.Pop().(*TreeNode)
		if top.Right == nil {
			*result = append(*result, top.Val) // visit top
		}
	}
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
