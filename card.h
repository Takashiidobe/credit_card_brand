#ifndef __CARD_H__
#define __CARD_H__

#include <stdio.h>

#include "internal/card_checker.h"
#include "internal/card_enum.h"

Card get_brand(const char *cc)
{
  // filter out nonnumeric characters
  char buf[20];
  int pos = 0;
  for (int i = 0; cc[i] != '\0'; i++)
  {
    if (pos >= 19)
      break;
    if (cc[i] >= '0' && cc[i] <= '9')
    {
      buf[pos] = cc[i];
      pos++;
    }
  }
  buf[pos] = '\0';

  if (is_visa(buf))
    return VISA;
  else if (is_american_express(buf))
    return AMERICAN_EXPRESS;
  else if (is_mastercard(buf))
    return MASTERCARD;
  else if (is_jcb(buf))
    return JCB;
  else if (is_discover(buf))
    return DISCOVER;
  else if (is_diners(buf))
    return DINERS;

  return UNKNOWN;
}

#endif
