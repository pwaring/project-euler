#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <inttypes.h>

#include <math.h>

#include <glib.h>

#include "primes.h"

int main(void)
{
  const uint16_t nth_prime = 10001;
  const uint32_t max_prime_candidate = 400000000;
  GSList* primes = get_prime_numbers(max_prime_candidate);
  guint primes_count = g_slist_length(primes);

  printf("Total number of primes up to %" PRIu32 ": %u\n", max_prime_candidate, primes_count);

  if (primes_count >= nth_prime)
  {
    // We now have sufficient primes, so count along to the nth prime
    uint16_t current_prime_count;
    GSList* current_prime;

    for (current_prime = primes, current_prime_count = 1; current_prime != NULL && current_prime_count < nth_prime; current_prime = current_prime->next, current_prime_count++)
    {
      // Intentionally empty body as all we care about is moving forwards in the
      // list of primes
    }

    printf("Prime number %" PRIu16 ": %" PRIu32 "\n", nth_prime, GPOINTER_TO_UINT(current_prime->data));

    free(primes);

    return EXIT_SUCCESS;
  }
  else
  {
    fprintf(stderr, "Could not find prime number %" PRIu16 " in first %" PRIu32 " numbers\n", nth_prime, max_prime_candidate);
    free(primes);
    return EXIT_FAILURE;
  }
}
