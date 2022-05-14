package container

// STACK
type Stack []interface{}

func (s *Stack) IsEmpty() bool {
	return len(*s) == 0
}

func (s *Stack) Len() int {
	return len(*s)
}

func (s *Stack) Push(v interface{}) {
	*s = append(*s, v)
}

func (s *Stack) Pop() interface{} {
	if s.IsEmpty() {
		return nil
	}
	index := len(*s) - 1
	value := (*s)[index]
	(*s) = (*s)[:index]
	return value
}

func (s *Stack) Top() interface{} {
	if s.IsEmpty() {
		return nil
	}
	return (*s)[len(*s)-1]
}

// QUEUE
type Queue []interface{}

func (q *Queue) IsEmpty() bool {
	return len(*q) == 0
}

func (q *Queue) Len() int {
	return len(*q)
}

func (q *Queue) Push(v interface{}) {
	*q = append(*q, v)
}

func (q *Queue) Pop() interface{} {
	if q.IsEmpty() {
		return nil
	}
	value := (*q)[0]
	(*q) = (*q)[1:len(*q)]
	return value
}

func (q *Queue) Top() interface{} {
	if q.IsEmpty() {
		return nil
	}
	return (*q)[0]
}
