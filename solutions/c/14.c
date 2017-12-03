#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

int main(void)
{
  const uint32_t maximum_sequence_start = 1000000;
  uint32_t longest_sequence_start = 1;
  uint32_t longest_sequence_length = 1;

  for (uint32_t current_sequence_start = 1; current_sequence_start < maximum_sequence_start; current_sequence_start++)
  {
    uint32_t current_sequence_length = 1;
    uint32_t n = current_sequence_start;

    while (n != 1)
    {
      if (n % 2 == 0)
      {
        n = n / 2;
      }
      else
      {
        n = (3 * n) + 1;
      }

      current_sequence_length++;
    }

    if (current_sequence_length > longest_sequence_length)
    {
      longest_sequence_start = current_sequence_start;
      longest_sequence_length = current_sequence_length;
    }
  }

  printf("Longest sequence has %" PRIu32 " steps and starts with %" PRIu32 "\n", longest_sequence_length, longest_sequence_start);

  return EXIT_SUCCESS;
}
