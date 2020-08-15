#ifndef __CARD_LEN_H__
#define __CARD_LEN_H__

#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include "card_utils.h"

bool is_between_digits(const char *cc, uint8_t x, uint8_t y)
{
  return strlen(cc) >= x && strlen(cc) <= y ? true : false;
}

bool is_n_digits(const char *cc, uint8_t n)
{
  return strlen(cc) == n ? true : false;
}

bool is_visa_len(const char *cc)
{
  return is_n_digits(cc, 16);
}

bool is_mastercard_len(const char *cc)
{
  return is_n_digits(cc, 16);
}

bool is_american_express_len(const char *cc)
{
  return is_n_digits(cc, 15);
}

bool is_diners_len(const char *cc)
{
  bool is_36 = false;
  if (starts_with(cc, "36"))
    is_36 = true;

  if (is_36 && is_between_digits(cc, 14, 19))
    return true;

  if (!is_36 && is_between_digits(cc, 16, 19))
    return true;

  return false;
}

bool is_jcb_len(const char *cc)
{
  return is_between_digits(cc, 16, 19);
}

bool is_discover_len(const char *cc)
{
  return is_between_digits(cc, 16, 19);
}

#endif
