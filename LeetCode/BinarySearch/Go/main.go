package main

import "fmt"

func search(nums []int, target int) int {
	l, r := 0, len(nums)-1

	for l < r-1 {
		mid := (l + r) / 2
		if nums[mid] > target {
			r = mid
			continue
		}
		if nums[mid] < target {
			l = mid
			continue
		}
		if nums[mid] == target {
			return mid
		}
	}
	return l
}

func main() {
	nums := []int{-1, 0, 3, 5, 9, 12}
	target := 5
	index := search(nums, target)
	fmt.Println(index)
}
