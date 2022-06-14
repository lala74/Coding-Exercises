package main

import (
	"fmt"

	. "github.com/lala74/Coding-Exercises/Common/Go/container"
)

// Swap Nodes in Pairs
type ListNode struct {
	Val  int
	Next *ListNode
}

func swapPairs(head *ListNode) *ListNode {
	return swap(head)
}

func swap(head *ListNode) *ListNode {
	if head == nil || head.Next == nil {
		return head
	}
	nextHead := head.Next

	head.Next = swap(head.Next.Next)
	nextHead.Next = head
	return nextHead
}

func main() {

	s := NewStack(1)
	s.Push(5)
	fmt.Println(s.Top())
}
