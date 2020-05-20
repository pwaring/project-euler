<?php

declare(strict_types=1);
error_reporting(E_ALL);

$sum = 0;

for ($num = 1; $num < 1000; $num++)
{
    if ($num % 3 === 0 || $num % 5 === 0)
    {
        $sum += $num;
    }
}

print("$sum\n");
