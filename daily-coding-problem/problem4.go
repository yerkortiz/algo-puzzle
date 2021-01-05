/*
Good morning! Here's your coding interview problem for today.

This problem was asked by Stripe.

Given an array of integers, find the first missing positive integer in linear time and constant space.
In other words, find the lowest positive integer that does not exist in the array.
The array can contain duplicates and negative numbers as well.

For example, the input [3, 4, -1, 1] should give 2. The input [1, 2, 0] should give 3.

You can modify the input array in-place.
*/
package main

import (
	"fmt"
)

func main() {
	var n int
	fmt.Scanf("%d", &n)
	a := make([]int, n, n)
	for i := 0; i < n; i++ {
		fmt.Scanf("%d", &a[i])
	}
	lo := n - 1
	for i := 0; i <= lo; i++ {
		for a[lo] <= 0 && lo >= 0 {
			lo--
		}
		if a[i] <= 0 {
			a[i], a[lo] = a[lo], a[i]
		}
	}
	x := make(map[int]bool)
	for i := 0; i <= lo; i++ {
		x[a[i]] = true
	}
	sol := 0
	for i := 1; i <= lo; i++ {
		if x[i] == false {
			sol = i
		}
	}
	if sol == 0 {
		sol = lo + 1
	}
	fmt.Println(sol)
}
