package container

// STACK
type Stack struct {
	buf []interface{}
	top int
}

func NewStack(size int) Stack {
	return Stack{
		buf: make([]interface{}, size),
		top: -1,
	}
}

func (s *Stack) IsEmpty() bool {
	return s.top == -1
}

func (s *Stack) Len() int {
	return s.top + 1
}

func (s *Stack) Push(v interface{}) {
	if s.top+1 > len(s.buf)-1 {
		s.buf = append(s.buf, v)
	} else {
		s.buf[s.top+1] = v
	}
	s.top++
}

func (s *Stack) Pop() {
	if s.IsEmpty() {
		return
	}
	s.top--
	return
}

func (s *Stack) Top() interface{} {
	if s.IsEmpty() {
		return nil
	}
	return s.buf[s.top]
}

// QUEUE
type Queue struct {
	buf  []interface{}
	head int
	tail int
}

func NewQueue(size int) Queue {
	return Queue{
		buf:  make([]interface{}, size),
		head: -1,
		tail: -1,
	}
}

// func (q *Queue) EnQueue(value int) bool {
// }
//
// func (q *Queue) DeQueue() bool {
// }
//
// func (q *Queue) Front() int {
// }
//
// func (q *Queue) Rear() int {
// }
//
// func (q *Queue) IsEmpty() bool {
//     return q.head == -1 && q.tail == -1
// }
//
// func (q *Queue) IsFull() bool {
// }

func (q *Queue) advance(index int) int {
	return (index + 1) % cap(q.buf)
}
