<?php

declare(strict_types=1);
error_reporting(E_ALL);

define('MAX_SEQUENCE', 4000000);

// Fibonnaci sequence actually starts 1, 2 but pretending it is 1, 1, 2 allows
// us to use the same logic for every step instead of treating the first one
// as a special case
$sequence = [1, 1, 2];
$sum = 0;

while ($sequence[2] <= MAX_SEQUENCE)
{
    if ($sequence[2] % 2 === 0)
    {
        $sum += $sequence[2];
    }

    // Move all elements back one space, then recalculate current element
    $sequence[0] = $sequence[1];
    $sequence[1] = $sequence[2];
    $sequence[2] = $sequence[0] + $sequence[1];
}

print("$sum\n");
