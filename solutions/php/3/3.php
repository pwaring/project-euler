<?php

declare(strict_types=1);
error_reporting(E_ALL);

require_once __DIR__ . '/../primes.php';

define('FACTORISE_TARGET', 600851475143);

// Highest possible factor at the start is the square root of the target
$highest_possible_factor = intval(floor(sqrt(FACTORISE_TARGET)));

// Build list of factors from 2 to the highest possible factor
$factors = [];

for ($candidate_factor = 2; $candidate_factor < $highest_possible_factor; $candidate_factor++)
{
    if (FACTORISE_TARGET % $candidate_factor === 0)
    {
        $other_factor = FACTORISE_TARGET / $candidate_factor;
        $factors[] = $candidate_factor;
        $factors[] = $other_factor;

        // Because we check factors from the lowest value, the other factor is
        // potentially the new highest possible factor
        if ($highest_possible_factor > $other_factor)
        {
            $highest_possible_factor = $other_factor;
        }
    }
}

// If we have found no factors, the target is prime and therefore has
// no highest prime factor
if (count($factors) === 0)
{
    die("No prime factors found\n");
}

// Sort factors
sort($factors, SORT_NUMERIC);

// Which of the factors are prime? First build an array of primes up to the
// square root of the highest factor.
// The alternative is to build an array of primes up to the highest factor, as
// that would allow us to do a lookup instead of multiple divisions, however
// that would also increase the memory requirements for the array by an order
// of highest_factor (which could be >1m).
$highest_factor = $factors[count($factors) - 1];
$max_prime_candidate = intval(floor(sqrt($highest_factor)));
$primes = prime_numbers($max_prime_candidate);

$highest_prime_factor = 0;

$factors_count = count($factors);
$primes_count = count($primes);

// Check each factor for primeness by dividing it by our primes. All composite
// numbers have at least one prime factor.
for ($i = 0; $i < $factors_count; $i++)
{
    // Assume a target is prime until we successfully factorise it
    $target_factor = $factors[$i];
    $is_prime = true;

    for ($j = 0; $is_prime && $j < $primes_count && $primes[$j] < $target_factor; $j++)
    {
        if ($target_factor % $primes[$j] === 0)
        {
            $is_prime = false;
        }
    }

    if ($is_prime)
    {
        $highest_prime_factor = $target_factor;
    }
}

print("$highest_prime_factor\n");
