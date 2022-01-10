package main

import (
	. "ducla/react"
)

func main() {
	r := New()

	i := r.CreateInput(1)
	c := r.CreateCompute1(i, func(v int) int { return v + 1 })
}
