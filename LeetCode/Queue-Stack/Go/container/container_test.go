package container

import (
	"testing"

	"github.com/stretchr/testify/assert"
)

func Test_Stack(t *testing.T) {
	s := NewStack(5)
	assert.Equal(t, 0, s.Len())

	num := 100

	// Push
	for i := 0; i <= num; i++ {
		s.Push(i * 2)
	}
	// Pop
	for i := num; i >= 0; i-- {
		assert.Equal(t, i*2, s.Top())
		assert.Equal(t, i+1, s.Len())
		s.Pop()
	}
	// Push + Pop
	for i := 0; i <= num; i++ {
		s.Push(i * 2)
		assert.Equal(t, i*2, s.Top())
		assert.Equal(t, 1, s.Len())
		s.Pop()
	}
	// Top + Pop empty
	for i := 0; i <= num; i++ {
		assert.Equal(t, nil, s.Top())
		s.Pop()
	}
}
