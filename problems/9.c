#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

int main(void)
{
  const uint16_t target_sum = 1000;

  const uint16_t max_a = target_sum / 3;
  const uint16_t max_b = target_sum / 2;
  const uint16_t max_c = target_sum - 2;

  for (uint16_t a = 1; a <= max_a; a++)
  {
    for (uint16_t b = a; b <= max_b; b++)
    {
      for (uint16_t c = b; c <= max_c; c++)
      {
        if (a + b + c == target_sum && ((a * a) + (b * b) == (c * c)))
        {
          uint64_t product = a * b * c;
          printf("Triplet found\n");
          printf("a: %" PRIu16 "\n", a);
          printf("b: %" PRIu16 "\n", b);
          printf("c: %" PRIu16 "\n", c);
          printf("abc: %" PRIu64 "\n", product);
          return EXIT_SUCCESS;
        }
      }
    }
  }

  // If we get this far, we have not found a triplet
  fprintf(stderr, "Failed to find a triplet\n");
  return EXIT_FAILURE;
}
