#pragma once

#include <string.h>
#include <inttypes.h>

uint32_t sum_str_digits(const char *str)
{
  uint32_t length = strlen(str);
  uint32_t sum = 0;

  for (uint32_t i = 0; i < length; i++)
  {
    char current_char = str[i];

    if (current_char >= '0' && current_char <= '9')
    {
      // Hacky solution, assumes 0-9 are sequential in character set
      sum += (current_char - '0');
    }
  }

  return sum;
}
