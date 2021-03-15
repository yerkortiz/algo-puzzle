help:
	echo "commands:"
	echo "echo_benchmark -> run benchmark test for echo"
	echo "run -> main program"

echo_benchmark:
	go test -bench=. -benchtime 100x

run:
	go run main.go $(shell cat asdas.txt)