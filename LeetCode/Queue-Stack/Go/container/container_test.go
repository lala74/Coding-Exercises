package container

import (
	"testing"

	"github.com/stretchr/testify/assert"
)

var num = 100

func Test_Stack(t *testing.T) {
	s := NewStack(5)
	assert.Equal(t, 0, s.Len())
	assert.Equal(t, true, s.IsEmpty())

	// Push
	for i := 0; i < num; i++ {
		s.Push(i * 2)
	}
	assert.Equal(t, false, s.IsEmpty())
	// Pop
	for i := num - 1; i >= 0; i-- {
		assert.Equal(t, i*2, s.Top())
		assert.Equal(t, i+1, s.Len())
		s.Pop()
	}
	// Push + Pop
	for i := 0; i < num; i++ {
		s.Push(i * 2)
		assert.Equal(t, i*2, s.Top())
		assert.Equal(t, 1, s.Len())
		s.Pop()
	}
	// Top + Pop empty
	for i := 0; i < num; i++ {
		assert.Equal(t, nil, s.Top())
		s.Pop()
	}
	assert.Equal(t, true, s.IsEmpty())
}

func Test_Queue(t *testing.T) {
	q := NewQueue(num)
	assert.Equal(t, true, q.IsEmpty())

	// EnQueue
	for i := 0; i < num; i++ {
		q.EnQueue(i * 2)
	}
	assert.Equal(t, false, q.IsEmpty())
	assert.Equal(t, (num-1)*2, q.Rear())
	// DeQueue
	for i := 0; i < num; i++ {
		assert.Equal(t, i*2, q.Front())
		assert.Equal(t, num-i, q.Len())
		assert.Equal(t, true, q.DeQueue())
	}
	// EnQueue, DeQueue
	for i := 0; i < num; i++ {
		q.EnQueue(i * 2)
		assert.Equal(t, i*2, q.Front())
		assert.Equal(t, 1, q.Len())
		assert.Equal(t, true, q.DeQueue())
	}
	// Top + Pop empty
	for i := 0; i < num; i++ {
		assert.Equal(t, nil, q.Front())
		assert.Equal(t, false, q.DeQueue())
	}
	assert.Equal(t, true, q.IsEmpty())
}
