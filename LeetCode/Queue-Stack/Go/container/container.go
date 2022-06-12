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

func (q *Queue) EnQueue(v interface{}) bool {
	if q.IsFull() {
		return false
	}
	if q.IsEmpty() {
		q.head = 0
		q.tail = 0
		q.buf[0] = v
		return true
	}
	q.tail = q.advance(q.tail)
	q.buf[q.tail] = v
	return true
}

func (q *Queue) DeQueue() bool {
	if q.IsEmpty() {
		return false
	}
	if q.head == q.tail {
		q.head = -1
		q.tail = -1
		return true
	}
	q.head = q.advance(q.head)
	return true
}

func (q *Queue) Front() interface{} {
	if q.IsEmpty() {
		return nil
	}
	return q.buf[q.head]
}

func (q *Queue) Rear() interface{} {
	if q.IsEmpty() {
		return nil
	}
	return q.buf[q.tail]
}

func (q *Queue) IsEmpty() bool {
	return q.head == -1 && q.tail == -1
}

func (q *Queue) IsFull() bool {
	return q.advance(q.tail) == q.head
}

func (q *Queue) Len() int {
	if q.tail >= q.head {
		return q.tail - q.head + 1
	}
	return cap(q.buf) - q.head + q.tail + 1
}

func (q *Queue) advance(index int) int {
	return (index + 1) % cap(q.buf)
}
