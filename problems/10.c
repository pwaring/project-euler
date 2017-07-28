#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

#include <glib.h>

#include "primes.h"

int main(void)
{
  const uint32_t max_prime_candidate = 2000000;
  GSList* primes = get_prime_numbers(max_prime_candidate);
  uint64_t primes_sum = 0;

  for (GSList* current_prime = primes; current_prime != NULL; current_prime = current_prime->next)
  {
    primes_sum += GPOINTER_TO_UINT(current_prime->data);
  }

  printf("Sum of the primes up to %" PRIu32 " is: %" PRIu64 "\n", max_prime_candidate, primes_sum);
  return EXIT_SUCCESS;
}
