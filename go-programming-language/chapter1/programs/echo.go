package programs

import (
	"strconv"
	"strings"
)

func EchoV1(args []string) string {
	s := ""
	for i, word := range args {
		s += (strconv.Itoa(i) + " " + word + " ")
	}
	return s
}

func EchoV2(args []string) string {
	s := strings.Join(args, " ")
	return s
}

func EchoV3(args []string) string {
	s := ""
	for _, word := range args {
		s += (word + " ")
	}
	return s
}
