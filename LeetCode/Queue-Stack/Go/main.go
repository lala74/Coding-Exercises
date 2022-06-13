package main

import (
	. "Queue-Stack/container"
	"fmt"
	"strconv"
)

type MyCircularQueue struct {
	buffer []int
	size   int
	head   int
	tail   int
}

func Constructor(k int) MyCircularQueue {
	return MyCircularQueue{
		size:   k,
		buffer: make([]int, k),
		head:   -1,
		tail:   -1,
	}
}

func (this *MyCircularQueue) EnQueue(value int) bool {
	if this.IsFull() {
		return false
	}
	if this.IsEmpty() {
		this.head = 0
		this.tail = 0
		this.buffer[this.tail] = value
		return true
	}
	this.tail = this.advance(this.tail)
	this.buffer[this.tail] = value
	return true
}

func (this *MyCircularQueue) DeQueue() bool {
	if this.IsEmpty() {
		return false
	}
	if this.head == this.tail {
		this.head = -1
		this.tail = -1
		return true
	}
	this.head = this.advance(this.head)
	return true
}

func (this *MyCircularQueue) Front() int {
	if this.IsEmpty() {
		return -1
	}
	return this.buffer[this.head]
}

func (this *MyCircularQueue) Rear() int {
	if this.IsEmpty() {
		return -1
	}
	return this.buffer[this.tail]
}

func (this *MyCircularQueue) IsEmpty() bool {
	return this.head == -1 && this.tail == -1
}

func (this *MyCircularQueue) IsFull() bool {
	// fmt.Println("IsFull: ", this.advance(this.tail) == this.head)
	// fmt.Println("head: ", this.head)
	// fmt.Println("tail: ", this.tail)
	return this.advance(this.tail) == this.head
}

func (this *MyCircularQueue) advance(index int) int {
	return (index + 1) % this.size
}

// Number of islands
func numIslands(grid [][]byte) int {
	row, col := len(grid), len(grid[0])
	num := 0

	for r := 0; r < row; r++ {
		for c := 0; c < col; c++ {
			if grid[r][c] == 1 {
				dfs(grid, r, c, row, col)
				num++
			}
		}
	}
	return num
}

func dfs(grid [][]byte, r, c, row, col int) {
	if r < 0 || r >= row || c < 0 || c >= col || grid[r][c] == 0 {
		return
	}
	grid[r][c] = 0
	dfs(grid, r+1, c, row, col)
	dfs(grid, r, c+1, row, col)
	dfs(grid, r-1, c, row, col)
	dfs(grid, r, c-1, row, col)
}

// Open the lock
func openLock(deadends []string, target string) int {
	if isItemInSlice("0000", deadends) {
		return -1
	}

	q := NewQueue(10000)
	visited := make(map[string]bool, 10000)

	q.EnQueue("0000")
	visited["0000"] = true
	count := 0

	for q.Len() != 0 {
		len := q.Len()
		for i := 0; i < len; i++ {
			c := q.Front().(string)
			q.DeQueue()
			coms := generateNextRotateCombinations(c)
			// Add all possible rotations to queue
			for _, com := range coms {
				_, ok := visited[com]
				if !ok && !isItemInSlice(com, deadends) {
					visited[com] = true
					q.EnQueue(com)
				}
			}
			if c == target {
				return count
			}
		}
		count++
	}
	return -1
}

func generateNextRotateCombinations(c string) []string {
	coms := []string{}
	coms = append(coms, rotateUp(c, 0))
	coms = append(coms, rotateUp(c, 1))
	coms = append(coms, rotateUp(c, 2))
	coms = append(coms, rotateUp(c, 3))
	coms = append(coms, rotateDown(c, 0))
	coms = append(coms, rotateDown(c, 1))
	coms = append(coms, rotateDown(c, 2))
	coms = append(coms, rotateDown(c, 3))
	return coms
}

func isItemInSlice(item string, s []string) bool {
	for _, v := range s {
		if v == item {
			return true
		}
	}
	return false
}

func rotateUp(combination string, nth int) string {
	if nth >= len(combination) {
		return ""
	}
	val := combination[nth] + 1
	if val > '9' {
		val = '0'
	}
	combination = combination[:nth] + string(val) + combination[nth+1:]
	return combination
}

func rotateDown(combination string, nth int) string {
	if nth >= len(combination) {
		return ""
	}
	val := combination[nth] - 1
	if val < '0' {
		val = '9'
	}
	combination = combination[:nth] + string(val) + combination[nth+1:]
	return combination
}

// Perfects Squares
func numSquares(n int) int {
	q := []int{}
	visited := make(map[int]bool, 0)

	squares := []int{}
	count := 0

	for i := 1; i*i <= n; i++ {
		squares = append(squares, i*i)
	}
	q = append(q, 0)

	for len(q) != 0 {
		len := len(q)
		for i := 0; i < len; i++ {
			v := q[0]
			q = q[1:]
			// Check for values in nth depth
			if v == n {
				return count
			}
			// Add all possible value to queue
			for _, square := range squares {
				val := v + square
				if !visited[val] && val <= n {
					q = append(q, val)
					visited[val] = true
				}
			}
		}
		count++
	}
	return -1
}

// Min Stack
type MinStack struct {
	buffer []int
	min    []int
}

func ConstructorStack() MinStack {
	return MinStack{
		buffer: make([]int, 0),
		min:    make([]int, 0),
	}
}

func (this *MinStack) Push(val int) {
	(*this).buffer = append((*this).buffer, val)

	lenMin := len(this.min)
	if lenMin == 0 || this.min[lenMin-1] >= val {
		(*this).min = append((*this).min, val)
	}
}

func (this *MinStack) Pop() {
	lenBuf := len(this.buffer)
	val := this.buffer[lenBuf-1]
	(*this).buffer = (*this).buffer[:lenBuf-1]

	lenMin := len(this.min)
	if this.min[lenMin-1] == val {
		(*this).min = (*this).min[:lenMin-1]
	}
}

func (this *MinStack) Top() int {
	lenBuf := len(this.buffer)
	return this.buffer[lenBuf-1]
}

func (this *MinStack) GetMin() int {
	lenMin := len(this.min)
	return this.min[lenMin-1]
}

// Valid Parentheses
func isValid(s string) bool {
	stack := []rune{}
	for _, c := range s {
		if c == '{' || c == '[' || c == '(' {
			stack = append(stack, c)
			continue
		}
		lenStack := len(stack)
		if lenStack == 0 {
			return false
		}
		lastRune := stack[lenStack-1]
		if c == '}' && lastRune == '{' {
			stack = stack[:lenStack-1]
			continue
		}
		if c == ']' && lastRune == '[' {
			stack = stack[:lenStack-1]
			continue
		}
		if c == ')' && lastRune == '(' {
			stack = stack[:lenStack-1]
			continue
		}
		return false
	}

	if len(stack) != 0 {
		return false
	}
	return true
}

// Daily Temperatures
func dailyTemperatures(temperatures []int) []int {
	type node struct {
		temp int
		day  int
	}

	answer := make([]int, len(temperatures))
	stack := []node{}

	for day, temp := range temperatures {
		n := node{temp: temp, day: day}
		if len(stack) == 0 {
			stack = append(stack, n)
			continue
		}

		for len(stack) != 0 && stack[len(stack)-1].temp < n.temp {
			lastNode := stack[len(stack)-1]
			answer[lastNode.day] = n.day - lastNode.day
			stack = stack[:len(stack)-1]
		}
		stack = append(stack, n)
	}

	for _, n := range stack {
		answer[n.day] = 0
	}

	return answer
}

// Evaluate Reverse Polish Notation
func evalRPN(tokens []string) int {
	s := NewStack(len(tokens))
	for _, v := range tokens {
		if v != "+" && v != "-" && v != "*" && v != "/" {
			val, _ := strconv.Atoi(v)
			s.Push(val)
			continue
		}

		value := 0
		v2, _ := s.Top().(int)
		s.Pop()
		v1, _ := s.Top().(int)
		s.Pop()

		switch v {
		case "+":
			value = v1 + v2
		case "-":
			value = v1 - v2
		case "*":
			value = v1 * v2
		case "/":
			value = v1 / v2
		}
		s.Push(value)
	}
	return s.Top().(int)
}

// Clone Graph
type Node struct {
	Val       int
	Neighbors []*Node
}

func cloneGraph(node *Node) *Node {
	if node == nil {
		return nil
	}
	s := NewStack(0)
	nodes := make(map[int]*Node)
	visited := make(map[int]bool)

	s.Push(node)

	for !s.IsEmpty() {
		n := s.Top().(*Node)
		s.Pop()
		if visited[n.Val] {
			continue
		}
		// Not visited
		visited[n.Val] = true
		cloneNode := makeNodeIfNotInMap(n.Val, nodes)
		for _, neighbor := range n.Neighbors {
			s.Push(neighbor)
			cloneNeighbor := makeNodeIfNotInMap(neighbor.Val, nodes)
			cloneNode.Neighbors = append(cloneNode.Neighbors, cloneNeighbor)
		}
	}
	return nodes[node.Val]
}

func makeNode(val int) *Node {
	return &Node{
		Val:       val,
		Neighbors: make([]*Node, 0),
	}
}

func makeNodeIfNotInMap(val int, nodes map[int]*Node) *Node {
	node, ok := nodes[val]
	// this node was not cloned yet, clone it and add it to nodes map
	if !ok {
		node = makeNode(val)
		nodes[node.Val] = node
	}
	return node
}

func main() {
	// fmt.Println(openLock([]string{"0201", "0101", "0102", "1212", "2002"}, "0202")) // 6
	// fmt.Println(numSquares(13)) // 2
	// fmt.Println(isValid("()")) // true
	// fmt.Println(dailyTemperatures([]int{73, 74, 75, 71, 69, 72, 76, 73})) // [1,1,4,2,1,1,0,0]
	fmt.Println(evalRPN([]string{"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"})) // 22

	// value := strconv.Itoa(65536 * 80 / 100)
	// fmt.Println("Value", value)
}
