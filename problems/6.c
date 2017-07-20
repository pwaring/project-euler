#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

int main(void)
{
  const uint8_t start_number = 1;
  const uint8_t end_number = 100;
  uint64_t sum_squares = 0;
  uint64_t square_sum = 0;
  uint32_t sum = 0;
  uint64_t difference = 0;

  for (uint8_t i = start_number; i <= end_number; i++)
  {
    sum += i;
    sum_squares += (i * i);
  }

  square_sum = sum * sum;

  difference = (sum_squares > square_sum) ? sum_squares - square_sum : square_sum - sum_squares;

  printf("Difference between sum of squares and square of sum is: %" PRIu64 "\n", difference);

  return EXIT_SUCCESS;
}
