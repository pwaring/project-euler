package main

import (
	"fmt"
)

func main() {
	var sum int = 0

	for num := 1; num < 1000; num++ {
		if num%3 == 0 || num%5 == 0 {
			sum += num
		}
	}

	fmt.Println(sum)
}
