package main

import (
	"fmt"
	"sync"
	"time"
)

type StatusMap struct {
	m  map[string]bool
	mu sync.RWMutex
}

func (s *StatusMap) SetFetched(url string) {
	s.mu.Lock()
	defer s.mu.Unlock()

	s.m[url] = true
}

func (s *StatusMap) IsFetched(url string) bool {
	s.mu.RLock()
	defer s.mu.RUnlock()

	return s.m[url]
}

type Fetcher interface {
	// Fetch returns the body of URL and
	// a slice of URLs found on that page.
	Fetch(url string) (body string, urls []string, err error)
}

// Crawl uses fetcher to recursively crawl
// pages starting with url, to a maximum of depth.
func Crawl(url string, depth int, fetcher Fetcher) {
	statusMap := &StatusMap{
		m: make(map[string]bool),
	}
	crawl(url, depth, fetcher, statusMap)
}

func crawl(url string, depth int, fetcher Fetcher, status *StatusMap) {
	if depth <= 0 {
		return
	}
	if status.IsFetched(url) {
		return
	}

	body, urls, err := fetcher.Fetch(url)
	if err != nil {
		fmt.Println(err)
		return
	}
	status.SetFetched(url)
	fmt.Printf("found: %s %q\n", url, body)

	wg := sync.WaitGroup{}
	for _, url := range urls {
		wg.Add(1)
		go func(url string) {
			defer wg.Done()
			crawl(url, depth-1, fetcher, status)
		}(url)
	}
	wg.Wait()

	return
}

func main() {
	Crawl("https://golang.org/", 4, fetcher)
}

// fakeFetcher is Fetcher that returns canned results.
type fakeFetcher map[string]*fakeResult

type fakeResult struct {
	body string
	urls []string
}

func (f fakeFetcher) Fetch(url string) (string, []string, error) {
	if res, ok := f[url]; ok {
		time.Sleep(500 * time.Millisecond)
		return res.body, res.urls, nil
	}
	return "", nil, fmt.Errorf("not found: %s", url)
}

// fetcher is a populated fakeFetcher.
var fetcher = fakeFetcher{
	"https://golang.org/": &fakeResult{
		"The Go Programming Language",
		[]string{
			"https://golang.org/pkg/",
			"https://golang.org/cmd/",
		},
	},
	"https://golang.org/pkg/": &fakeResult{
		"Packages",
		[]string{
			"https://golang.org/",
			"https://golang.org/cmd/",
			"https://golang.org/pkg/fmt/",
			"https://golang.org/pkg/os/",
		},
	},
	"https://golang.org/pkg/fmt/": &fakeResult{
		"Package fmt",
		[]string{
			"https://golang.org/",
			"https://golang.org/pkg/",
		},
	},
	"https://golang.org/pkg/os/": &fakeResult{
		"Package os",
		[]string{
			"https://golang.org/",
			"https://golang.org/pkg/",
		},
	},
}
