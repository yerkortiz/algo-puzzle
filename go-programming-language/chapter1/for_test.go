package main

import (
	"testing"
)

const (
	N = 100000000
)

var intSlice []int

func BenchmarkSlice(b *testing.B) {
	for i := 0; i < N; i++ {
		intSlice = append(intSlice, i)
	}
}
func BenchmarkFor(b *testing.B) {
	sum := 0
	for i := 0; i < N; i++ {
		sum += intSlice[i]
	}
}
func BenchmarkRange(b *testing.B) {
	sum := 0
	for _, element := range intSlice {
		sum += element
	}
}
