package main

import (
	"fmt"
	"strconv"
)

func isPalindrome(n int) bool {
	isPalindrome := true
	str := strconv.Itoa(n)

	for startDigit, endDigit := 0, len(str)-1; startDigit <= endDigit && isPalindrome; startDigit, endDigit = startDigit+1, endDigit-1 {
		if str[startDigit] != str[endDigit] {
			isPalindrome = false
		}
	}

	return isPalindrome
}

func main() {
	longestPalindrome := 0

	for i := 100; i <= 999; i++ {
		for j := 100; j <= 999; j++ {
			product := i * j
			if product > longestPalindrome && isPalindrome(product) {
				longestPalindrome = product
			}
		}
	}

	fmt.Println(longestPalindrome)
}
