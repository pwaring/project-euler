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

  const unsigned long int factorial = 100;

  mpz_fac_ui(result, factorial);

  gmp_printf("%d! = %Zd\n", factorial, result);

  char *result_string = mpz_get_str(NULL, 10, result);

  uint32_t result_sum = sum_str_digits(result_string);

  printf("Sum of the digits in %lu! = %" PRIu32 "\n", factorial, result_sum);

  mpz_clear(result);

  return EXIT_SUCCESS;
}
