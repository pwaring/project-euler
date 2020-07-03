<?php

define('SIEVE_UNKNOWN', -1);
define('SIEVE_NOT_PRIME', 0);
define('SIEVE_PRIME', 1);
define('FIRST_PRIME', 2);

function prime_numbers(int $max_prime_candidate) : array
{
    $sieve = array_fill(0, $max_prime_candidate + 1, SIEVE_UNKNOWN);
    $primes = [];

    $sieve[FIRST_PRIME] = SIEVE_PRIME;
    $current_prime = FIRST_PRIME;
    $primes_found = 1;

    for ($i = FIRST_PRIME; $current_prime != 0 && $i <= $max_prime_candidate; $i++)
    {
        $next_prime = 0; // assume this prime will be the last
        $step = $current_prime;

        // Mark all multiples of current prime as non-prime
        for ($j = $current_prime + $step; $j <= $max_prime_candidate; $j += $step)
        {
            $sieve[$j] = SIEVE_NOT_PRIME;
        }

        // Find the next unknown element after the current prime,
        // this is the next prime
        for ($k = $current_prime + 1; $next_prime === 0 && $k <= $max_prime_candidate; $k++)
        {
            if ($sieve[$k] === SIEVE_UNKNOWN)
            {
                $sieve[$k] = SIEVE_PRIME;
                $next_prime = $k;
                $primes_found++;
            }
        }

        // Set current prime to be the next prime.
        // If there is no next prime ($next_prime === 0), this will end the search.
        $current_prime = $next_prime;
    }

    for ($s = FIRST_PRIME; $s <= $max_prime_candidate; $s++)
    {
        if ($sieve[$s] === SIEVE_PRIME)
        {
            $primes[] = $s;
        }
    }

    return $primes;
}