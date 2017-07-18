#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <inttypes.h>

#include <math.h>

#include <glib.h>

GSList* prime_numbers(uint32_t max_prime_candidate)
{
  const int8_t SIEVE_UNKNOWN = -1;
  const int8_t SIEVE_NOT_PRIME = 0;
  const int8_t SIEVE_PRIME = 1;

  const uint8_t FIRST_PRIME = 2;

  uint32_t current_prime = 0;
  uint32_t primes_found = 0;

  int8_t* sieve = (int8_t*) calloc(max_prime_candidate + 1, sizeof(int8_t));

  // Set the status of all numbers to unknown
  for (uint32_t i = 0; i <= max_prime_candidate; i++)
  {
    sieve[i] = SIEVE_UNKNOWN;
  }

  sieve[FIRST_PRIME] = SIEVE_PRIME;
  current_prime = FIRST_PRIME;
  primes_found = 1;

  for (uint32_t i = FIRST_PRIME; current_prime != 0 && i <= max_prime_candidate; i++)
  {
    uint32_t next_prime = 0; // assume this prime will be the last
    uint32_t step = current_prime;

    // Mark all multiples of current prime as non-prime
    for (uint32_t j = current_prime + step; j <= max_prime_candidate; j += step)
    {
      sieve[j] = SIEVE_NOT_PRIME;
    }

    // Find the next unknown element after the current prime - this is the next prime
    for (uint32_t k = current_prime + 1; next_prime == 0 && k <= max_prime_candidate; k++)
    {
      if (sieve[k] == SIEVE_UNKNOWN)
      {
        sieve[k] = SIEVE_PRIME;
        next_prime = k;
        primes_found++;
      }
    }

    // Set current prime to be the next prime. If there is no next prime, this
    // will end the search
    current_prime = next_prime;
  }

  // Create a linked list to return to the caller
  GSList* primes = NULL;

  for (uint32_t i = FIRST_PRIME; i <= max_prime_candidate; i++)
  {
    if (sieve[i] == SIEVE_PRIME)
    {
      primes = g_slist_append(primes, GUINT_TO_POINTER(i));
    }
  }

  free(sieve);

  return primes;
}

gint compare_int(gconstpointer a, gconstpointer b)
{
  uint32_t a_comp = GPOINTER_TO_UINT(a);
  uint32_t b_comp = GPOINTER_TO_UINT(b);

  if (a_comp < b_comp)
  {
    return -1;
  }
  else if (a_comp == b_comp)
  {
    return 0;
  }
  else
  {
    return 1;
  }
}

int main(void)
{
  const uint64_t FACTORISE_TARGET = 600851475143;

  // Highest possible factor at the start is the square root of the target
  uint32_t highest_possible_factor = floor(sqrt(FACTORISE_TARGET));

  // Build list of factors from 2 to the highest possible factor
  GSList* factors = NULL;

  for (uint32_t candidate_factor = 2; candidate_factor < highest_possible_factor; candidate_factor++)
  {
    printf("Factorising %lu with %u\n", FACTORISE_TARGET, candidate_factor);

    if (FACTORISE_TARGET % candidate_factor == 0)
    {
      uint32_t other_factor = FACTORISE_TARGET / candidate_factor;

      factors = g_slist_append(factors, GUINT_TO_POINTER(candidate_factor));
      factors = g_slist_append(factors, GUINT_TO_POINTER(other_factor));

      // Because we check candidate factors from the lowest value, the other
      // factor is potentially the highest possible factor
      if (highest_possible_factor > other_factor) {
        highest_possible_factor = other_factor;
      }
    }
  }

  // If we have found no factors, the target is prime and therefore has no
  // highest prime factor
  if (factors == NULL)
  {
    fprintf(stderr, "No prime factors found\n");
    g_slist_free(factors);
    return EXIT_FAILURE;
  }

  // Sort factors
  factors = g_slist_sort(factors, &compare_int);

  // Print list of factors
  for (GSList* current_factor = factors; current_factor != NULL; current_factor = current_factor->next)
  {
    printf("Factor: %u\n", GPOINTER_TO_UINT(current_factor->data));
  }

  // Which of the factors are prime? First build an array of primes up to the
  // square root of the highest factor.
  // The alternative is to build an array of primes up to the highest factor, as
  // that would allow us to do a lookup instead of multiple divisions, however
  // that would also increase the memory requirements for the array by an order
  // of highest_factor (which could be >1m).
  uint32_t highest_factor = GPOINTER_TO_UINT(g_slist_last(factors)->data);
  uint32_t max_prime_candidate = floor(sqrt(highest_factor));
  GSList* primes = prime_numbers(max_prime_candidate);

  for (GSList* current_prime = primes; current_prime != NULL; current_prime = current_prime->next)
  {
    printf("Prime: %u\n", GPOINTER_TO_UINT(current_prime->data));
  }

  uint32_t highest_prime_factor = 0;

  // Check each factor for primeness by dividing it by our primes. All composite
  // numbers have at least one prime factor.
  for (GSList* current_factor = factors; current_factor != NULL; current_factor = current_factor->next)
  {
    // Assume a target is prime unless we successively factorise it
    uint32_t target_factor = GPOINTER_TO_UINT(current_factor->data);
    bool is_prime = true;

    printf("Checking %u for primeness\n", target_factor);

    for (GSList* current_prime = primes; is_prime && current_prime != NULL && GPOINTER_TO_UINT(current_prime->data) < target_factor; current_prime = current_prime->next)
    {
      if (target_factor % GPOINTER_TO_UINT(current_prime->data) == 0)
      {
        is_prime = false;
        printf("%u is not prime, is divisible by: %u\n", target_factor, GPOINTER_TO_UINT(current_prime->data));
      }
    }

    if (is_prime)
    {
      printf("%u is prime\n", target_factor);
      highest_prime_factor = target_factor;
    }
  }

  // We do not have to check for highest prime factor being 0 because all
  // composite numbers have at least one prime factor
  printf("Highest prime factor of %lu is %u\n", FACTORISE_TARGET, highest_prime_factor);

  g_slist_free(primes);
  g_slist_free(factors);

  return EXIT_SUCCESS;
}
