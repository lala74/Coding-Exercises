package main

import "fmt"

type Args struct {
	temp     int
	hum      int
	pressure int
}

type Subject interface {
	AddObserver(o Observer)
	RemoveObserver(o Observer)
	Notify()
}

type Observer interface {
	Update(args Args)
}

type WeatherStation struct {
	observers map[Observer]struct{}
	args      Args
}

func (ws *WeatherStation) AddObserver(o Observer) {
	if _, ok := ws.observers[o]; !ok {
		ws.observers[o] = struct{}{}
	}
}

func (ws *WeatherStation) RemoveObserver(o Observer) {
	delete(ws.observers, o)
}

func (ws *WeatherStation) Notify() {
	for o := range ws.observers {
		o.Update(ws.args)
	}
}

func (ws *WeatherStation) ValueChanged() {
	ws.args.hum++
	ws.args.temp++
	ws.args.pressure++
	ws.Notify()
}

type Display struct {
	id string
}

func (d *Display) Update(args Args) {
	fmt.Println(d.id, ":", args.temp, args.hum, args.pressure)
}

func main() {
	ws := WeatherStation{
		observers: make(map[Observer]struct{}),
	}
	d1 := &Display{id: "1"}
	d2 := &Display{id: "2"}
	d3 := &Display{id: "3"}

	fmt.Println("----- Add d1 d2")
	ws.AddObserver(d1)
	ws.AddObserver(d2)
	fmt.Println("----- Update value")
	ws.ValueChanged()
	fmt.Println("----- Update value")
	ws.ValueChanged()
	fmt.Println("----- Add d3")
	ws.AddObserver(d3)
	fmt.Println("----- Update value")
	ws.ValueChanged()
	fmt.Println("----- Add d3")
	ws.AddObserver(d3)
	fmt.Println("----- Update value")
	ws.ValueChanged()
	fmt.Println("----- Remove d2")
	ws.RemoveObserver(d2)
	fmt.Println("----- Update value")
	ws.ValueChanged()
}
