package main

import (
	"fmt"
	"io/ioutil"
	"os"
	"strings"
	"testing"

	"github.com/yerkortiz/programs"
)

func BenchmarkEchoV2(b *testing.B) {
	fmt.Printf("Join test\n_______________\n")
	fileBytes, err := ioutil.ReadFile("mobydick.txt")
	if err != nil {
		fmt.Println(err)
		os.Exit(1)
	}
	sliceData := strings.Split(string(fileBytes), "\n")
	programs.EchoV2(sliceData)
}
func BenchmarkEchoV3(b *testing.B) {
	fmt.Printf("Concatenation test\n_______________\n")
	fileBytes, err := ioutil.ReadFile("mobydick.txt")
	if err != nil {
		fmt.Println(err)
		os.Exit(1)
	}
	sliceData := strings.Split(string(fileBytes), "\n")
	programs.EchoV3(sliceData)
}
