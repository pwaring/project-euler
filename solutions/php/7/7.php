<?php

declare(strict_types=1);
error_reporting(E_ALL);

require_once __DIR__ . '/../primes.php';

$prime_count_target = 10001;

// Assume at least 1 prime per 100 numbers
$max_prime_candidate = $prime_count_target * 100;

$primes = prime_numbers($max_prime_candidate);

print($primes[$prime_count_target - 1] . "\n");