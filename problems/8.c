#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <string.h>

int main(void)
{
  const char digits[] = "73167176531330624919225119674426574742355349194934"
                  "96983520312774506326239578318016984801869478851843"
                  "85861560789112949495459501737958331952853208805511"
                  "12540698747158523863050715693290963295227443043557"
                  "66896648950445244523161731856403098711121722383113"
                  "62229893423380308135336276614282806444486645238749"
                  "30358907296290491560440772390713810515859307960866"
                  "70172427121883998797908792274921901699720888093776"
                  "65727333001053367881220235421809751254540594752243"
                  "52584907711670556013604839586446706324415722155397"
                  "53697817977846174064955149290862569321978468622482"
                  "83972241375657056057490261407972968652414535100474"
                  "82166370484403199890008895243450658541227588666881"
                  "16427171479924442928230863465674813919123162824586"
                  "17866458359124566529476545682848912883142607690042"
                  "24219022671055626321111109370544217506941658960408"
                  "07198403850962455444362981230987879927244284909188"
                  "84580156166097919133875499200524063689912560717606"
                  "05886116467109405077541002256983155200055935729725"
                  "71636269561882670428252483600823257530420752963450";

  const uint16_t digit_count = strlen(digits);
  const uint8_t step = 12;
  const uint16_t stop_digit = (digit_count - 1) - step;
  uint64_t largest_product = 0;

  for (uint16_t i = 0; i <= stop_digit; i++)
  {
    // Easier to turn current digit into a 'string' consisting of one character
    // (plus NUL terminator) than to try and manipulate a char variable
    char current_digit[2];
    current_digit[0] = digits[i];
    current_digit[1] = '\0';

    uint8_t current_number = atoi(current_digit);
    uint64_t current_product = current_number;

    printf("Current digit: %s\n", current_digit);
    printf("Current digit as number: %" PRIu8 "\n", current_number);
    printf("Current product: %" PRIu64 "\n", current_product);

    for (uint16_t j = i + 1; j <= (i + step); j++)
    {
      current_digit[0] = digits[j];
      current_number = atoi(current_digit);
      current_product *= current_number;
      printf("Current digit: %s\n", current_digit);
      printf("Current digit as number: %" PRIu8 "\n", current_number);
      printf("Current product: %" PRIu64 "\n", current_product);
    }

    if (current_product > largest_product)
    {
      largest_product = current_product;
    }
  }

  printf("Largest product of %" PRIu8 " digits is: %" PRIu64 "\n", step, largest_product);

  return EXIT_SUCCESS;
}
