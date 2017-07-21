#pragma once

#include <glib.h>

GSList* get_prime_numbers(uint32_t max_prime_candidate)
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
      // Prepending is faster than appending as we do not need to traverse the list
      primes = g_slist_prepend(primes, GUINT_TO_POINTER(i));
    }
  }

  // Reverse the list as we have prepended primes so they are in descending order
  primes = g_slist_reverse(primes);

  free(sieve);

  return primes;
}
