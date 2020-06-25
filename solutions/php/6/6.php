<?php

declare(strict_types=1);
error_reporting(E_ALL);

$numbers = range(1, 100);
$square_of_sum = array_sum($numbers) ** 2;
$sum_of_squares = array_sum(array_map(function($n) {
    return $n ** 2;
}, $numbers));

$diff = abs($square_of_sum - $sum_of_squares);

print("$diff\n");
