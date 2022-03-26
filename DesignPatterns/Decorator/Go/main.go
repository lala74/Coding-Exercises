package main

import "fmt"

type Size int

const (
	Small Size = iota
	Medium
	Large
)

type Beverage interface {
	Cost() float32
	GetDescription() string
	Size() Size
}

type ConcreteBeverage struct {
	Beverage
	description string
	cost        float32
	size        Size
}

func (cb *ConcreteBeverage) GetDescription() string {
	return cb.description
}

func (cd *ConcreteBeverage) Cost() float32 {
	return cd.cost
}

func (cd *ConcreteBeverage) Size() Size {
	return cd.size
}

type HouseBlend struct {
	ConcreteBeverage
}

func NewHouseBlend(size Size) Beverage {
	return &HouseBlend{
		ConcreteBeverage: ConcreteBeverage{
			description: "HouseBlend",
			cost:        1,
			size:        size,
		},
	}
}

type DarkRoast struct {
	ConcreteBeverage
}

func NewDarkRoast(size Size) Beverage {
	return &DarkRoast{
		ConcreteBeverage: ConcreteBeverage{
			description: "DarkRoast",
			cost:        2,
			size:        size,
		},
	}
}

type CondimentDecorator struct {
	Beverage
	description string
	cost        float32
}

func (cd *CondimentDecorator) GetDescription() string {
	return cd.Beverage.GetDescription() + ", " + cd.description
}

func (cd *CondimentDecorator) Cost() float32 {
	cost := cd.cost
	switch cd.Beverage.Size() {
	case Medium:
		cost *= 2
	case Large:
		cost *= 3
	}
	return cd.Beverage.Cost() + cost
}

type Milk struct {
	CondimentDecorator
}

func AddMilk(b Beverage) Beverage {
	return &Milk{
		CondimentDecorator: CondimentDecorator{
			Beverage:    b,
			description: "Milk",
			cost:        0.2,
		},
	}
}

type Chocolate struct {
	CondimentDecorator
}

func AddChocolate(b Beverage) Beverage {
	return &Chocolate{
		CondimentDecorator: CondimentDecorator{
			Beverage:    b,
			description: "Chocolate",
			cost:        0.3,
		},
	}
}

func main() {
	beverage := NewDarkRoast(Medium)
	fmt.Println("Size", beverage.Size())
	beverage = AddMilk(beverage)
	beverage = AddMilk(beverage)
	beverage = AddChocolate(beverage)
	fmt.Println("Description", beverage.GetDescription())
	fmt.Println("Cost", beverage.Cost())

	b1 := AddMilk(AddMilk(AddChocolate(NewDarkRoast(Large))))
	fmt.Println("Description", b1.GetDescription())
	fmt.Println("Cost", b1.Cost())
}
