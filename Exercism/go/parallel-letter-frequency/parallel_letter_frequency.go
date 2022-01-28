package letter

// FreqMap records the frequency of each rune in a given text.
type FreqMap map[rune]int

// Frequency counts the frequency of each rune in a given text and returns this
// data as a FreqMap.
func Frequency(s string) FreqMap {
	m := FreqMap{}
	for _, r := range s {
		m[r]++
	}
	return m
}

// ConcurrentFrequency counts the frequency of each rune in the given strings,
// by making use of concurrency.
func ConcurrentFrequency(texts []string) FreqMap {
	output := FreqMap{}
	results := make(chan FreqMap)
	for _, text := range texts {
		go func(text string) {
			results <- Frequency(text)
		}(text)
	}

	output = <-results

	for i := 0; i < len(texts)-1; i++ {
		for r, frequence := range <-results {
			output[r] += frequence
		}
	}
	return output
}
