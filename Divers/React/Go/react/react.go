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
		cc.compute()
	}
}

func (r *reactor) CreateInput(value int) InputCell {
	ic := &inputCell{}
	ic.id = "input"
	ic.value = value
	ic.reactor = r
	return ic
}

func (r *reactor) CreateCompute1(c Cell, f func(int) int) ComputeCell {
	cc := &computeCell{}
	cc.makeCell(func() int {
		return f(c.Value())
	})
	r.cells = append(r.cells, cc)
	r.update()
	return cc
}

func (r *reactor) CreateCompute2(c1 Cell, c2 Cell, f func(int, int) int) ComputeCell {
	cc := &computeCell{}
	cc.makeCell(func() int {
		return f(c1.Value(), c2.Value())
	})
	r.cells = append(r.cells, cc)
	r.update()
	return cc
}

type inputCell struct {
	id      string
	value   int
	reactor *reactor
}

func (c *inputCell) Value() int {
	return c.value
}

func (c *inputCell) SetValue(value int) {
	c.value = value
	c.reactor.update()
}

type computeCell struct {
	id      string
	value   int
	compute func()
	cbs     map[string]func(int)
}

func (c *computeCell) makeCell(f func() int) {
	c.cbs = make(map[string]func(int))
	c.compute = func() {
		oldVal := c.value
		c.value = f()
		if oldVal != c.value {
			for _, cb := range c.cbs {
				cb(c.value)
			}
		}
	}
}

func (c *computeCell) Value() int {
	return c.value
}

func (c *computeCell) AddCallback(f func(int)) Canceler {
	id := strconv.Itoa(len(c.cbs))
	c.cbs[id] = f
	return &canceler{computeCell: c, id: id}
}

type canceler struct {
	id          string
	computeCell *computeCell
}

func (c *canceler) Cancel() {
	delete(c.computeCell.cbs, c.id)
}
