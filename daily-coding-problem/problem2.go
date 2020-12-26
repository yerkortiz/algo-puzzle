/*
 * Good morning! Here's your coding interview problem for today.
 *
 * This problem was asked by Uber.
 *
 * Given an array of integers, return a new array such
 * that each element at index i of the new array is the
 * product of all the numbers in the original array except
 * the one at i.
 *
 * For example, if our input was [1, 2, 3, 4, 5], the expected
 * output would be [120, 60, 40, 30, 24].
 * If our input was [3, 2, 1], the expected output would be [2, 3, 6].
 *
 * Follow-up: what if you can't use division?
 */
package main

import (
	"fmt"
)

func memset(a []int, v int) {
	for i := range a {
		a[i] = v
	}
}
func solution(arr []int) []int {
	answer, mirror := make([]int, len(arr)), make([]int, len(arr))
	n := len(arr)
	memset(answer, arr[n-1])
	memset(mirror, arr[0])
	for i := 1; i < n; i++ {
		answer[i] = answer[i-1] * arr[n-i-1]
	}
	for i := 1; i < n; i++ {
		mirror[i] = mirror[i-1] * arr[i]
	}
	for i := 2; i < n; i++ {
		answer[n-i-1] = mirror[i-2] * answer[n-i-1]
	}
	answer[n-1] = mirror[n-2]
	for i := 0; i < n; i++ {
		answer[i], answer[n-1] = answer[n-1], answer[i]
	}
	return answer
}
func main() {
	arr := []int{1, 2, 3, 4, 5}
	answer := solution(arr)
	for _, element := range answer {
		fmt.Printf("%d ", element)
	}
}
