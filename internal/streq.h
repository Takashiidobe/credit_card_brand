#ifndef __STR_EQ_H__
#define __STR_EQ_H__

#include <string.h>
#include <stdbool.h>

bool streq(const char *str1, const char *str2)
{
  return strcmp(str1, str2) == 0;
}

#endif
