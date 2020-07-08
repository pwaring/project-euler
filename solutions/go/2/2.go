package main

import (
	"fmt"
)

const MAX_SEQUENCE = 4000000

func main() {
	sum := 0
	sequence := [3]int{1, 1, 2}

	for ; sequence[2] <= MAX_SEQUENCE; {
		if sequence[2] % 2 == 0 {
			sum += sequence[2]
		}

		// Move all elements back one space, then recalculate current element
		sequence[0] = sequence[1]
		sequence[1] = sequence[2]
		sequence[2] = sequence[0] + sequence[1]
	}

	fmt.Println(sum)
}