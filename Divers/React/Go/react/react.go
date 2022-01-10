package react

import "strconv"

func New() Reactor {
	return &reactor{}
}

type reactor struct {
	cells []*computeCell
}

func (r *reactor) update() {
	for _, cc := range r.cells {
		cc.f()
	}
}

func (r *reactor) CreateInput(value int) InputCell {
	ic := &inputCell{}
	ic.id = "input"
	ic.value = value
	ic.r = r
	return ic
}

func (r *reactor) CreateCompute1(c Cell, f func(int) int) ComputeCell {
	cc := &computeCell{}
	cc.cbs = make(map[string]func(int))
	// cc.id = "compute1"
	cc.f = func() {
		oldVal := cc.value
		cc.value = f(c.Value())
		if oldVal != cc.value {
			for _, cb := range cc.cbs {
				cb(cc.value)
			}
		}
	}
	r.cells = append(r.cells, cc)
	r.update()
	return cc
}

func (r *reactor) CreateCompute2(c1 Cell, c2 Cell, f func(int, int) int) ComputeCell {
	cc := &computeCell{}
	cc.cbs = make(map[string]func(int))
	cc.f = func() {
		oldVal := cc.value
		cc.value = f(c1.Value(), c2.Value())
		if oldVal != cc.value {
			for _, cb := range cc.cbs {
				cb(cc.value)
			}
		}
	}
	r.cells = append(r.cells, cc)
	r.update()
	return cc
}

type inputCell struct {
	id    string
	value int
	r     *reactor
}

func (c *inputCell) Value() int {
	return c.value
}

func (c *inputCell) SetValue(value int) {
	c.value = value
	c.r.update()
}

type computeCell struct {
	id    string
	value int
	f     func()
	cbs   map[string]func(int)
}

func (c *computeCell) Value() int {
	return c.value
}

func (c *computeCell) AddCallback(f func(int)) Canceler {
	id := strconv.Itoa(len(c.cbs))
	c.cbs[id] = f
	return &canceler{cc: c, id: id}
}

type canceler struct {
	id string
	cc *computeCell
}

func (c *canceler) Cancel() {
	delete(c.cc.cbs, c.id)
}
