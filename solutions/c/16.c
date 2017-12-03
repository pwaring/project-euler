#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>
#include <gmp.h>

#include "convert.h"

int main(void)
{
  mpz_t result;
  mpz_init(result);

  const unsigned long int base = 2;
  const unsigned long int exponent = 1000;

  mpz_ui_pow_ui(result, base, exponent);

  gmp_printf("%d^%d = %Zd\n", base, exponent, result);

  char *result_string = mpz_get_str(NULL, 10, result);

  uint32_t result_sum = sum_str_digits(result_string);

  printf("Sum of the digits in %lu^%lu = %" PRIu32 "\n", base, exponent, result_sum);

  mpz_clear(result);

  return EXIT_SUCCESS;
}
