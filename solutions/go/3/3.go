package main

import (
	"fmt"
	"math"
	"os"
	"sort"
)

func getPrimes(maxNumber int) []int {
	const UNKNOWN = 0
	const NOT_PRIME = 1
	const IS_PRIME = 2
	const FIRST_PRIME = 2

	primes := []int{}

	// Use make for the sieve because we know the size and everything should
	// be populated with zero
	sieve := make([]int, maxNumber+1)
	sieve[FIRST_PRIME] = IS_PRIME

	for sieveIndex, currentPrime := FIRST_PRIME, FIRST_PRIME; currentPrime != 0 && sieveIndex <= maxNumber; sieveIndex++ {
		// Assume this prime will be the last
		nextPrime := 0
		step := currentPrime

		// Mark all multiples of current prime as non-prime
		for j := currentPrime + step; j <= maxNumber; j += step {
			sieve[j] = NOT_PRIME
		}

		// Find the next unknown element after the current prime
		// This will be the next prime
		for k := currentPrime + 1; nextPrime == 0 && k <= maxNumber; k++ {
			if sieve[k] == UNKNOWN {
				sieve[k] = IS_PRIME
				nextPrime = k
			}
		}

		// Set current prime to be the next prime
		// If there is no next prime (nextPrime == 0), this will end
		// the for loop as currentPrime != 0 will be false
		currentPrime = nextPrime
	}

	// We now have a sieve with all the numbers flagged as prime/not prime
	// Extract just the primes and return as a slice
	for s := FIRST_PRIME; s <= maxNumber; s++ {
		if sieve[s] == IS_PRIME {
			primes = append(primes, s)
		}
	}

	return primes
}

func main() {
	const TARGET = 600851475143

	highestPossibleFactor := int(math.Floor(math.Sqrt(TARGET)))

	// Build list of factors from 2 to the highest possible factor
	factors := []int{}

	for candidateFactor := 2; candidateFactor < highestPossibleFactor; candidateFactor++ {
		remainder := TARGET % candidateFactor
		if remainder == 0 {
			// candidateFactor is a factor, so find its other side
			otherFactor := TARGET / candidateFactor
			factors = append(factors, candidateFactor, otherFactor)
		}
	}

	// Bail out if we do not have any factors, i.e. TARGET is itself prime
	if len(factors) == 0 {
		fmt.Println("Target number is prime and therefore has no factors")
		os.Exit(1)
	}

	// Sort factors so we can process them from highest to lowest
	sort.Slice(factors, func(a, b int) bool {
		return factors[a] > factors[b]
	})

	// To find whether a factor is prime, we divide it by all the prime numbers
	// less than its square root
	highestFactor := factors[0]
	maxPrimeCandidate := int(math.Floor(math.Sqrt(float64(highestFactor))))
	primes := getPrimes(maxPrimeCandidate)

	for f := range factors {
		// Assume a factor is prime until we factorise it
		isPrime := true

		for p := 0; isPrime && p < len(primes) && primes[p] < factors[f]; p++ {
			remainder := factors[f] % primes[p]
			if remainder == 0 {
				isPrime = false
			}
		}

		if isPrime {
			// This must be the highest prime factor as we process the factors
			// in descending order, therefore we can print it and exit
			fmt.Println(factors[f])
			os.Exit(0)
		}
	}

	// If we get this far, no prime factor was found - i.e. all the factors
	// of the target are composite numbers
	fmt.Println("Target number has no prime factors")
	os.Exit(1)
}
