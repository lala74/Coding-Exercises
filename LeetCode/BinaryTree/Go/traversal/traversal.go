package traversal

import (
	"BinaryTree/container"
	. "BinaryTree/def"
)

// POSTORDER
func Postorder(root *TreeNode) []int {
	result := []int{}
	postorderIteration(root, &result)
	// postorderRecursion(root, &result)
	return result
}

func postorderIteration(root *TreeNode, result *[]int) {
	if root == nil {
		return
	}
	s := container.Stack{}
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
func Preorder(root *TreeNode) []int {
	result := []int{}
	// inorderRecursion(root, &result)
	preorderInteration(root, &result)
	return result
}

func preorderInteration(root *TreeNode, result *[]int) {
	if root == nil {
		return
	}
	s := container.Stack{}
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
func Inorder(root *TreeNode) []int {
	result := []int{}
	// inorderRecursion(root, &result)
	inorderInteration(root, &result)
	return result
}

func inorderInteration(root *TreeNode, result *[]int) {
	if root == nil {
		return
	}
	s := container.Stack{}
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

// LEVEL ORDER
func LevelOrder(root *TreeNode) [][]int {
	result := [][]int{}
	levelOrderIteration(root, &result)
	return result
}

func levelOrderIteration(root *TreeNode, result *[][]int) {
	if root == nil {
		return
	}
	q := container.Queue{}
	q.Push(root)
	for q.Len() != 0 {
		levelValues := []int{}
		levelLength := q.Len()
		for i := 0; i < levelLength; i++ {
			node := q.Pop().(*TreeNode)
			levelValues = append(levelValues, node.Val)
			if node.Left != nil {
				q.Push(node.Left)
			}
			if node.Right != nil {
				q.Push(node.Right)
			}
		}
		(*result) = append(*result, levelValues)
	}
}
