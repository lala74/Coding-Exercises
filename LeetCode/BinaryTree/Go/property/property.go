package property

import . "BinaryTree/def"

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
