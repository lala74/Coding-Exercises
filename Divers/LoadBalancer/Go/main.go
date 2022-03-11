package main

import (
	"fmt"
	"math/rand"
	"sync"
	"time"
)

const (
	numWorker  = 5
	numRequest = 50
)

type Request struct {
	id int
	fn func() int
	c  chan int
}

func request(requestsStream chan<- Request) {
	wg := sync.WaitGroup{}
	wg.Add(numRequest)
	for i := 0; i < numRequest; i++ {
		v := i
		request := Request{
			id: v,
			fn: func() int {
				time.Sleep(time.Duration(rand.Int63n(5)*500) * time.Millisecond)
				return v
			},
			c: make(chan int),
		}
		go func() {
			defer wg.Done()
			requestsStream <- request
			fmt.Println(<-request.c)
		}()
	}
	wg.Wait()
}

type Worker struct {
	id             int
	requestsStream chan Request
	numJobs        int
}

func (w *Worker) work(done chan<- *Worker) {
	for {
		r := <-w.requestsStream
		r.c <- r.fn()
		done <- w
	}
}

type Balancer struct {
	doneStream     chan *Worker
	requestsStream chan Request
	workers        []*Worker
	mu             sync.Mutex
}

func (b *Balancer) balance() {
	for {
		select {
		case r := <-b.requestsStream: // incoming requests
			// create a go routine to dispatch request to worker
			// because if send to much request to worker, dispatch func will block
			// because worker is working, can not receive another request -> balancer block
			go b.dispatch(r)
		case w := <-b.doneStream: // worker inform done
			b.complete(w)
		}
	}
}

func (b *Balancer) dispatch(r Request) {
	worker := b.workers[0]
	for _, w := range b.workers {
		if w.numJobs < worker.numJobs {
			worker = w
		}
	}
	worker.numJobs++
	worker.requestsStream <- r
}

func (b *Balancer) complete(w *Worker) {
	w.numJobs--
}

func main() {
	b := Balancer{
		doneStream:     make(chan *Worker),
		requestsStream: make(chan Request),
	}
	for i := 0; i < numWorker; i++ {
		w := &Worker{id: i, requestsStream: make(chan Request, 5)}
		go w.work(b.doneStream)
		b.workers = append(b.workers, w)
	}
	go b.balance()
	request(b.requestsStream)
}
