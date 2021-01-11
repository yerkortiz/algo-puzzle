/*
Good morning! Here's your coding interview problem for today.

This problem was asked by Jane Street.

cons(a, b) constructs a pair, and car(pair) and cdr(pair) returns the first and last element of that pair. For example, car(cons(3, 4)) returns 3, and cdr(cons(3, 4)) returns 4.

Given this implementation of cons:

def cons(a, b):
    def pair(f):
        return f(a, b)
    return pair
Implement car and cdr.
*/
package main

import (
	"fmt"
)

func cons(a int, b int) func(func(int, int) int) int {
	pair := func(f func(int, int) int) int {
		return f(a, b)
	}
	return pair
}

func car(f func(func(int, int) int) int) int {
	first := func(a int, b int) int {
		return a
	}
	return f(first)
}

func cdr(f func(func(int, int) int) int) int {
	second := func(a int, b int) int {
		return b
	}
	return f(second)
}
func main() {
	pair := cons(10, 9)
	first := car(pair)
	second := cdr(pair)
	fmt.Println(pair)
	fmt.Println(first)
	fmt.Println(second)
}
