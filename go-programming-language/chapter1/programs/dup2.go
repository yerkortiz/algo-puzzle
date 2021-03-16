/*Modify dup2 to print the names of all files in which each dup lic ated line occurs.*/
package programs

import (
	"bufio"
	"fmt"
	"os"
)

type lineData struct {
	repetitions int
	filename    string
}

func Dup2(files []string) {
	counts := make(map[string]lineData)
	if len(files) == 0 {
		CountLines(os.Stdin, counts)
	} else {
		for _, arg := range files {
			f, err := os.Open(arg)
			if err != nil {
				fmt.Fprintf(os.Stderr, "dup2: %v\n", err)
				continue
			}
			CountLines(f, counts)
			f.Close()
		}
	}
	for line, n := range counts {
		if n.repetitions > 1 {
			fmt.Printf("%d\t%s\t%s\n", n.repetitions, line, n.filename)
		}
	}
}
func CountLines(f *os.File, counts map[string]lineData) {
	input := bufio.NewScanner(f)
	for input.Scan() {
		temp := counts[input.Text()]
		temp.repetitions++
		temp.filename = f.Name()
		counts[input.Text()] = temp
	}
}
