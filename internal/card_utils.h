#ifndef __CARD_UTILS_H__
#define __CARD_UTILS_H__

#include <string.h>
#include <stdint.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>

bool streq(const char *str1, const char *str2)
{
  return strcmp(str1, str2) == 0;
}

size_t max(size_t a, size_t b)
{
  return a > b ? a : b;
}

size_t min(size_t a, size_t b)
{
  return a < b ? a : b;
}

bool in_range(const char *cc, uint32_t lower, uint32_t upper)
{
  uint8_t lower_len = (lower == 0) ? 1 : (log10(lower) + 1);
  uint8_t higher_len = (lower == 0) ? 1 : (log10(lower) + 1);

  uint8_t max_len = max(lower_len, higher_len);

  char buf[max_len + 1];
  for (uint8_t i = 0; i < max_len; i++)
  {
    buf[i] = cc[i];
  }
  buf[max_len] = '\0';

  uint64_t uint_buf = atoi(buf);

  return uint_buf >= lower && uint_buf <= upper;
}

bool starts_with(const char *str, const char *cmp)
{
  size_t string_length = strlen(str);
  size_t cmp_length = strlen(cmp);
  size_t len_to_cmp = min(string_length, cmp_length);

  for (size_t i = 0; i < len_to_cmp; i++)
  {
    if (str[i] != cmp[i])
      return false;
  }

  return true;
}

#endif
