package main

import (
	. "BinaryTree/def"
	"BinaryTree/property"
	"BinaryTree/traversal"
	"fmt"
)

func main() {
	root := BuildTree([]int{5, 4, 8, 11, NIL, 13, 4, 7, 2, NIL, NIL, NIL, 1})

	order := traversal.LevelOrder(root)
	fmt.Println(order)
	fmt.Println("MaxDepth", property.MaxDepth(root))
	fmt.Println("IsSymmetric", property.IsSymmetric(root))
	fmt.Println("HasPathSum", property.HasPathSum(root, 2))
}
