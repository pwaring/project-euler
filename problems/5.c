#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <stdbool.h>

#include <math.h>

int main(void)
{
  // Any number of which N is factor will also have N/2 as a factor, therefore
  // we only need to check top half of the list of factors (e.g. for 1..20 we
  // can get away with only checking 11..20).
  const uint8_t highest_factor = 20;
  const uint8_t lowest_factor = floor(highest_factor / 2) + 1;
  const uint8_t factor_count = (highest_factor - lowest_factor) + 1;

  uint8_t factors[factor_count];
  uint64_t highest_evenly_divisible = 1;
  uint64_t lowest_evenly_divisible = 0;

  for (uint8_t i = 0, current_factor = highest_factor; current_factor >= lowest_factor && i < factor_count; i++, current_factor--)
  {
    factors[i] = current_factor;
    highest_evenly_divisible *= current_factor;
  }

  // Start with highest factor H and use that as the step, as any number smaller
  // than H will not have H as a factor
  for (uint64_t candidate_evenly_divisible = highest_factor; candidate_evenly_divisible <= highest_evenly_divisible && !lowest_evenly_divisible; candidate_evenly_divisible += highest_factor)
  {
    printf("Checking %" PRIu64 "\n", candidate_evenly_divisible);
    bool evenly_divisible = true;

    // Start at position 1 because we know the number will be divisible by factor[0]
    // as it is our step
    for (uint8_t i = 1; i < factor_count; i++)
    {
      if (candidate_evenly_divisible % factors[i] != 0)
      {
        evenly_divisible = false;
      }
    }

    if (evenly_divisible)
    {
      lowest_evenly_divisible = candidate_evenly_divisible;
    }
  }

  // We know that we will have the lowest evenly divisible number by this point,
  // as the worse case is that the loop ends with it set to highest_evenly_divisible
  printf("Lowest evenly divisible: %" PRIu64 "\n", lowest_evenly_divisible);
}
