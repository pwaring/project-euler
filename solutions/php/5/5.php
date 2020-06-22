<?php

declare(strict_types=1);
error_reporting(E_ALL);

$highest_factor = 20;
$lowest_factor = floor($highest_factor / 2) + 1;
$factors = range($lowest_factor, $highest_factor - 1);
$factors_count = count($factors);
$lowest_found = false;
$lowest_factorised = 0;

for ($candidate = $highest_factor; !$lowest_found; $candidate += $highest_factor)
{
    $lowest_found = true;

    for ($i = 0; $i < $factors_count && $lowest_found; $i++)
    {
        if ($candidate % $factors[$i] !== 0)
        {
            $lowest_found = false;
        }
    }

    if ($lowest_found)
    {
        $lowest_factorised = $candidate;
    }
}

print("$lowest_factorised\n");