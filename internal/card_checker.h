#ifndef __CARD_CHECKER_H__
#define __CARD_CHECKER_H__

#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h>

#include "card_len.h"
#include "luhn.h"
#include "card_utils.h"

bool is_visa(const char *cc)
{
  if (!luhn(cc) || !is_visa_len(cc))
    return false;

  if (starts_with(cc, "4"))
    return true;

  return false;
}

bool is_american_express(const char *cc)
{
  if (!luhn(cc) || !is_american_express_len(cc))
    return false;

  if (starts_with(cc, "34") || starts_with(cc, "37"))
    return true;

  return false;
}

bool is_mastercard(const char *cc)
{
  if (!luhn(cc) || !is_mastercard_len(cc))
    return false;

  if (in_range(cc, 51, 55) || in_range(cc, 2221, 2720))
    return true;

  return false;
}

bool is_diners(const char *cc)
{
  if (!luhn(cc) || !is_diners_len(cc))
    return false;

  if (starts_with(cc, "36") || starts_with(cc, "38") || starts_with(cc, "39") || starts_with(cc, "3095"))
    return true;

  if (in_range(cc, 300, 305))
    return true;

  return false;
}

bool is_jcb(const char *cc)
{
  if (!luhn(cc) || !is_jcb_len(cc))
    return false;

  if (in_range(cc, 3528, 3589))
    return true;

  return false;
}

bool is_discover(const char *cc)
{
  if (!luhn(cc) || !is_discover_len(cc))
    return false;

  if (starts_with(cc, "64") || starts_with(cc, "65") || starts_with(cc, "6011"))
    return true;

  if (in_range(cc, 622126, 622925) || in_range(cc, 624000, 626999) || in_range(cc, 628200, 628899))
    return true;

  return false;
}

#endif
