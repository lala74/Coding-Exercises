package main

import (
	"fmt"
)

// Longest Substring Without Repeating Characters
func lengthOfLongestSubstring(s string) int {
	if len(s) == 0 {
		return 0
	}
	left, maxLen := 0, 0
	m := make(map[rune]int)
	for pos, c := range s {
		if lastPos, ok := m[c]; ok {
			left = max(lastPos+1, left)
		}
		maxLen = max(maxLen, pos-left+1)
		m[c] = pos
	}
	return maxLen
}

func max(a int, b int) int {
	if a > b {
		return a
	}
	return b
}

func main() {
	s := "pwwkew"
	result := lengthOfLongestSubstring(s)
	fmt.Println("results", result)
}
