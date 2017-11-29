#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <inttypes.h>

int main(void)
{
  uint32_t largest_palindrome = 0;

  for (uint16_t alpha = 999; alpha >= 100; alpha--)
  {
    for (uint16_t beta = 999; beta >= 100; beta--)
    {
      uint32_t product = alpha * beta;
      uint8_t digit_count = product < 100000 ? 5 : 6;
      uint8_t buffer_size = digit_count + 1; // Plus one for the terminating NUL character
      char buffer[buffer_size];

      printf("Checking to see if %" PRIu32 " is a palindrome\n", product);

      // Assume palindrome until proved otherwise
      bool is_palindrome = true;

      int output_length = snprintf(buffer, buffer_size, "%" PRIu32, product);

      if (output_length >= buffer_size)
      {
        fprintf(stderr, "Output length (%" PRIu8 ") is greater than or equal to buffer size (%" PRIu8 ")\n", output_length, buffer_size);
        return EXIT_FAILURE;
      }

      // Check each pair of digits until we cross over (start_digit <= end_digit)
      for (uint8_t start_digit = 0, end_digit = digit_count - 1; start_digit <= end_digit && is_palindrome; start_digit++, end_digit--)
      {
        printf("Comparing %c with %c\n", buffer[start_digit], buffer[end_digit]);
        if (buffer[start_digit] != buffer[end_digit])
        {
          is_palindrome = false;
        }
      }

      if (is_palindrome)
      {
        if (product > largest_palindrome)
        {
          largest_palindrome = product;
        }
      }
    }
  }

  printf("Largest palindrome is: %" PRIu32 "\n", largest_palindrome);

  return EXIT_SUCCESS;
}
