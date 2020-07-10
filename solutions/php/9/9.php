<?php

declare(strict_types=1);
error_reporting(E_ALL);

define('TARGET_SUM', 1000);

$max_a = intval(ceil(TARGET_SUM / 3));
$max_b = intval(ceil(TARGET_SUM / 2));
$max_c = TARGET_SUM - 3;

for ($a = 1; $a <= $max_a; $a++)
{
    for ($b = $a + 1; $b <= $max_b; $b++)
    {
        for ($c = $b + 1; $c <= $max_c; $c++)
        {
            if ($a + $b + $c == TARGET_SUM && (($a * $a) + ($b * $b)) == ($c * $c))
            {
                $product = $a * $b * $c;
                print("$product\n");
                exit;
            }
        }
    }
}
