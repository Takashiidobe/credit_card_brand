#ifndef __LUNH_H__
#define __LUNH_H__

#include <stdbool.h>
#include <stdint.h>
#include <string.h>

bool luhn(const char *cc)
{
  const int32_t m[] = {0, 2, 4, 6, 8, 1, 3, 5, 7, 9};
  int32_t i;
  int32_t odd = 1;
  int32_t sum = 0;

  for (i = strlen(cc); i--; odd = !odd)
  {
    int32_t digit = cc[i] - '0';
    sum += odd ? digit : m[digit];
  }

  return sum % 10 == 0;
}

#endif
