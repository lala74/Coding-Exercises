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

// Reverse Linked List
func reverseList(head *ListNode) *ListNode {
	if head == nil || head.Next == nil {
		return head
	}
	// tail, head := reverseListRecursion(head)
	// tail.Next = nil
	// return head

	newHead := reverseListInterative(head)
	head.Next = nil
	return newHead
}

func reverseListRecursion(head *ListNode) (*ListNode, *ListNode) {
	if head.Next == nil {
		return head, head
	}
	subHead, realHead := reverseListRecursion(head.Next)
	subHead.Next = head
	return head, realHead
}

func reverseListInterative(head *ListNode) *ListNode {
	l, m, r := head, head.Next, head.Next.Next
	for r != nil {
		m.Next = l
		l = m
		m = r
		r = r.Next
	}
	m.Next = l
	return m
}

// Search in a Binary Search Tree
type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func searchBST(root *TreeNode, val int) *TreeNode {
	if root == nil {
		return root
	}
	if root.Val == val {
		return root
	}
	left := searchBST(root.Left, val)
	if left != nil {
		return left
	}
	right := searchBST(root.Right, val)
	if right != nil {
		return right
	}
	return nil
}

// Pascal's Triangle II
func getRow(rowIndex int) []int {
	return getRowOneSlice(rowIndex)
	// return getRowTwoSlice(rowIndex)
}

func getRowTwoSlice(rowIndex int) []int {
	row1 := make([]int, rowIndex+1)
	row2 := make([]int, rowIndex+1)

	for i := 0; i < rowIndex+1; i++ {
		row1[i] = 1
		row2[i] = 1
	}

	for i := 2; i <= rowIndex; i++ {
		// calculate row2 based on row1
		for j := 1; j < i; j++ {
			row2[j] = row1[j-1] + row1[j]
		}
		// copy row2 to row 1
		for index := 0; index < i+1; index++ {
			row1[index] = row2[index]
		}
	}
	return row2
}

func getRowOneSlice(rowIndex int) []int {
	row := make([]int, rowIndex+1)
	for i := 0; i < rowIndex+1; i++ {
		row[i] = 1
	}

	for i := 2; i <= rowIndex; i++ {
		for j := i - 1; j > 0; j-- {
			row[j] = row[j] + row[j-1]
		}
	}
	return row
}

// Fibonacci Number
func fib(n int) int {
	cache := make(map[int]int)
	return fibRecursion(n, cache)
}

func fibRecursion(n int, cache map[int]int) int {
	v, ok := cache[n]
	if ok {
		return v
	}

	result := 0
	if n < 2 {
		result = n
	} else {
		result = fibRecursion(n-1, cache) + fibRecursion(n-2, cache)
	}
	cache[n] = result
	return result
}

// Climb Stairs
func climbStairs(n int) int {
	// return climbStairsRecursion(n, make(map[int]int))
	return climbStairsDP(n)
}

func climbStairsRecursion(n int, cache map[int]int) int {
	result, ok := cache[n]
	if ok {
		return result
	}

	if n < 3 {
		result = n
	} else {
		result = climbStairs(n-1) + climbStairs(n-2)
	}
	cache[n] = result
	return result
}

func climbStairsDP(n int) int {
	if n < 3 {
		return n
	}
	array := make([]int, n+1)
	array[1] = 1
	array[2] = 2
	for i := 3; i <= n; i++ {
		array[i] = array[i-1] + array[i-2]
	}
	return array[n]
}

// Revert string
func reverseString(s []byte) {
	for i := 0; i < len(s)/2; i++ {
		tmp := s[i]
		s[i] = s[len(s)-1-i]
		s[len(s)-1-i] = tmp
	}
}

// Pow
func myPow(x float64, n int) float64 {
	if n < 0 {
		n = -n
		x = 1 / x
	}
	return myPowHelper(x, n)
}

func myPowHelper(x float64, n int) float64 {
	if n == 0 {
		return 1
	}
	if n == 1 {
		return x
	}
	if n%2 == 0 {
		return myPowHelper(x*x, n/2)
	}
	return x * myPowHelper(x*x, n/2)
}

// Merge two sorted lists
func mergeTwoLists(l1 *ListNode, l2 *ListNode) *ListNode {
	if l1 == nil {
		return l2
	}
	if l2 == nil {
		return l1
	}
	if l1.Val <= l2.Val {
		l1.Next = mergeTwoLists(l1.Next, l2)
		return l1
	}
	l2.Next = mergeTwoLists(l1, l2.Next)
	return l2
}

//K-th Symbol in Grammar
func kthGrammar(n int, k int) int {
	// return kthGrammarRecursion(n, k)
	return kthGrammarInterative(n, k)
}

func kthGrammarRecursion(n int, k int) int {
	if n == 1 {
		return 0
	}
	val := kthGrammar(n-1, (k+1)/2)
	if val%2 == k%2 {
		return 1
	}
	return 0
}

// base on binary system
// Ex: k = 7, n = 4
// Change to 0-indexed: k = 6, n = 2 (skip the first row, which is 0)
// k = 6 ~ 0b110
// 		this ^   indicate value of row 0
// 		this  ^  indicate value of row 1
// 		this   ^ indicate value of row 2
func kthGrammarInterative(n int, k int) int {
	//0-indexed
	k = k - 1
	n = n - 2

	val := 0
	for i := n; i >= 0; i-- {
		index := (k & (1 << i)) >> i
		if val == index {
			val = 0
		} else {
			val = 1
		}
		// switch {
		// case val == 0 && index == 0:
		//     val = 0
		// case val == 0 && index == 1:
		//     val = 1
		// case val == 1 && index == 0:
		//     val = 1
		// case val == 1 && index == 1:
		//     val = 0
		// }
	}
	return val
}

func main() {
	s := NewStack(5)
	s.Push(4)
	// val := []byte{'a', 'b', 'c', 'd', 'e'}
	// reverseString(val)
	// fmt.Println("ReverseString:", val)
	// fmt.Println("Stack:", s.Top())
	// fmt.Println("Pascal:", getRow(5))
	// fmt.Println("ClimbStairs:", climbStairs(5))
	// fmt.Println("Pow:", myPow(2, 7))
	fmt.Println("kthGrammar", kthGrammar(3, 2))
}
