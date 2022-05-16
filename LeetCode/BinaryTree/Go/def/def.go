package def

import (
	"BinaryTree/container"
)

const NIL = -999

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func BuildTree(nodes []int) *TreeNode {
	qVal := container.Queue{}
	for _, node := range nodes {
		qVal.Push(node)
	}

	rootVal := qVal.Pop().(int)
	root := &TreeNode{Val: rootVal}
	qNode := container.Queue{}
	qNode.Push(root)
	for qNode.Len() != 0 {
		for i := 0; i < qNode.Len(); i++ {
			if qVal.IsEmpty() {
				return root
			}
			leftVal := qVal.Pop().(int)
			rightVal := qVal.Pop().(int)
			leftNode := &TreeNode{Val: leftVal}
			rightNode := &TreeNode{Val: rightVal}

			node := qNode.Pop().(*TreeNode)
			if leftVal != NIL {
				node.Left = leftNode
				qNode.Push(leftNode)
			}
			if rightVal != NIL {
				node.Right = rightNode
				qNode.Push(rightNode)
			}

		}
	}
	return root
}
