#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  int sum = 0;

  for (int i = 1; i < 1000; i++)
  {
    if (i % 3 == 0 || i % 5 == 0)
    {
      sum += i;
    }
  }

  printf("Sum of multiples of 3 or 5 below 1000: %d\n", sum);

  return EXIT_SUCCESS;
}
