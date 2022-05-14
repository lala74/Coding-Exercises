package main

import (
	"BinaryTree/def"
	"BinaryTree/property"
	"BinaryTree/traversal"
	"fmt"
)

func main() {
	root := &def.TreeNode{Val: 1}
	root.Left = &def.TreeNode{Val: 3}
	root.Right = &def.TreeNode{Val: 2}
	root.Left.Left = &def.TreeNode{Val: 4}
	root.Left.Right = &def.TreeNode{Val: 5}
	root.Right.Left = &def.TreeNode{Val: 3}
	order := traversal.LevelOrder(root)
	fmt.Println(order)
	fmt.Println("MaxDepth", property.MaxDepth(root))
}
