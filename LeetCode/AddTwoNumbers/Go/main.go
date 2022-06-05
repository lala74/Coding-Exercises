package main

/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */

type ListNode struct {
	Val  int
	Next *ListNode
}

func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
	tail := &ListNode{}
	head := tail
	remainer, sum := 0, 0

	for l1 != nil || l2 != nil {
		sum = remainer
		if l1 != nil {
			sum += l1.Val
			l1 = l1.Next
		}
		if l2 != nil {
			sum += l2.Val
			l2 = l2.Next
		}
		tail.Next = &ListNode{Val: sum % 10}
		tail = tail.Next

		if sum > 9 {
			remainer = 1
		} else {
			remainer = 0
		}
	}
	if remainer == 1 {
		tail.Next = &ListNode{Val: 1}
	}
	return head.Next
}

func main() {

}
