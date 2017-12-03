#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>
#include <gmp.h>

int main(void)
{
  mpz_t result;
  mpz_init(result);

  const unsigned long int base = 2;
  const unsigned long int exponent = 1000;

  mpz_ui_pow_ui(result, base, exponent);

  gmp_printf("%d^%d = %Zd\n", base, exponent, result);

  char *result_string = mpz_get_str(NULL, 10, result);

  uint32_t result_length = strlen(result_string);
  uint32_t result_sum = 0;

  for (uint32_t i = 0; i < result_length; i++)
  {
    char current_char = result_string[i];

    if (current_char >= '0' && current_char <= '9')
    {
      // Hacky solution, assumes 0-9 are sequential in character set
      result_sum += (current_char - '0');
    }
  }

  printf("Sum of the digits in %lu^%lu = %" PRIu32 "\n", base, exponent, result_sum);

  mpz_clear(result);

  return EXIT_SUCCESS;
}
