package property

import (
	. "BinaryTree/container"
	. "BinaryTree/def"
)

// MaxDepth
func MaxDepth(root *TreeNode) int {
	answer := 0
	// maxDepthRecursionTopDown(root, 1, &answer)
	answer = maxDepthRecursionBottomUp(root)
	return answer
}

func maxDepthRecursionTopDown(root *TreeNode, depth int, answer *int) {
	if root == nil {
		return
	}
	if root.Left == nil && root.Right == nil {
		if depth > *answer {
			*answer = depth
		}
	}
	maxDepthRecursionTopDown(root.Left, depth+1, answer)
	maxDepthRecursionTopDown(root.Right, depth+1, answer)
}

func maxDepthRecursionBottomUp(root *TreeNode) int {
	if root == nil {
		return 0
	}
	maxDepthLeft := maxDepthRecursionBottomUp(root.Left)
	maxDepthRight := maxDepthRecursionBottomUp(root.Right)
	if maxDepthLeft > maxDepthRight {
		return maxDepthLeft + 1
	}
	return maxDepthRight + 1
}

// IsSymmetric
func IsSymmetric(root *TreeNode) bool {
	if root == nil {
		return true
	}
	// return isSymmetricRecursion(root.Left, root.Right)
	return isSymmetricIterationStack(root)
}

func isSymmetricRecursion(node1 *TreeNode, node2 *TreeNode) bool {
	if node1 == nil && node2 == nil {
		return true
	}
	if node1 == nil || node2 == nil {
		return false
	}
	if node1.Val != node2.Val {
		return false
	}
	return isSymmetricRecursion(node1.Left, node2.Right) && isSymmetricRecursion(node1.Right, node2.Left)
}

func isSymmetricIterationStack(root *TreeNode) bool {
	if root == nil {
		return true
	}
	s := Stack{}
	s.Push(root.Left)
	s.Push(root.Right)
	for s.Len() != 0 {
		node1 := s.Pop().(*TreeNode)
		node2 := s.Pop().(*TreeNode)
		if node1 == nil && node2 == nil {
			continue
		}
		if node1 == nil || node2 == nil {
			return false
		}
		if node1.Val != node2.Val {
			return false
		}
		s.Push(node1.Left)
		s.Push(node2.Right)

		s.Push(node1.Right)
		s.Push(node2.Left)
	}
	return true
}

// HasPathSum
func HasPathSum(root *TreeNode, targetSum int) bool {
	answer := hasPathSumRecursion(root, targetSum)
	return answer
}

func hasPathSumRecursion(root *TreeNode, targetSum int) bool {
	if root == nil {
		return false
	}
	if root.Left == nil && root.Right == nil { // node if leaf
		return root.Val == targetSum
	}
	return hasPathSumRecursion(root.Left, targetSum-root.Val) || hasPathSumRecursion(root.Right, targetSum-root.Val)
}

// func hasPathSumIteration(root *TreeNode, targetSum int) bool {
//     if root == nil {
//         return false
//     }
//     s := Stack{}
//     sSum := Stack{}
//     s.Push(root)
//     sSum.Push(root.Val)
//     for s.Len() != 0 {
//
//     }
// }
