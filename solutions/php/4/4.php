<?php

declare(strict_types=1);
error_reporting(E_ALL);

function is_palindrome(int $number) : bool
{
    // A number is a palindrome if its string representation
    // is the same when reversed
    $str = strval($number);
    return ($str === strrev($str));
}

$longest_palindrome = 0;

for ($i = 100; $i <= 999; $i++)
{
    for ($j = 100; $j <= 999; $j++)
    {
        $product = $i * $j;

        if (is_palindrome($product) && $product > $longest_palindrome)
        {
            $longest_palindrome = $product;
        }
    }
}

print("$longest_palindrome\n");
