#ifndef __CARD_CHECKER_H__
#define __CARD_CHECKER_H__

#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h>

#include "card_len.h"
#include "streq.h"
#include "luhn.h"

bool is_visa(const char *cc)
{
  if (!luhn(cc) || !is_visa_len(cc))
    return false;

  if (cc[0] == '4')
    return true;

  return false;
}

bool is_american_express(const char *cc)
{
  if (!luhn(cc) || !is_american_express_len(cc))
    return false;

  char buf[3];

  for (int32_t i = 0; i < 3; i++)
    buf[i] = cc[i];

  buf[2] = '\0';

  if (streq(buf, "37") || streq(buf, "34"))
    return true;

  return false;
}

bool is_mastercard(const char *cc)
{
  if (!luhn(cc) || !is_mastercard_len(cc))
    return false;

  char buf1[3];
  for (int32_t i = 0; i < 3; i++)
  {
    buf1[i] = cc[i];
  }
  buf1[2] = '\0';

  char buf2[5];
  for (int32_t i = 0; i < 5; i++)
  {
    buf2[i] = cc[i];
  }
  buf2[4] = '\0';

  int32_t int_buf1 = atoi(buf1);
  int32_t int_buf2 = atoi(buf2);

  if (int_buf1 >= 51 && int_buf1 <= 55)
    return true;

  if (int_buf2 >= 2221 && int_buf2 <= 2720)
    return true;

  return false;
}

bool is_diners(const char *cc)
{
  if (!luhn(cc) || !is_diners_len(cc))
    return false;

  char buf[3];

  for (int32_t i = 0; i < 3; i++)
    buf[i] = cc[i];

  buf[2] = '\0';

  if (streq(buf, "36") || streq(buf, "38") || streq(buf, "39"))
    return true;

  char buf1[5];
  for (int32_t i = 0; i < 5; i++)
    buf1[i] = cc[i];

  buf1[4] = '\0';

  char buf2[4];
  for (int32_t i = 0; i < 4; i++)
    buf2[i] = cc[i];

  buf2[3] = '\0';

  int32_t int_buf2 = atoi(buf2);

  if (streq(buf1, "3095"))
    return true;

  if (int_buf2 >= 300 && int_buf2 <= 305)
    return true;

  return false;
}

bool is_jcb(const char *cc)
{
  if (!luhn(cc) || !is_jcb_len(cc))
    return false;

  char buf2[5];
  for (int32_t i = 0; i < 5; i++)
  {
    buf2[i] = cc[i];
  }
  buf2[4] = '\0';

  int32_t int_buf2 = atoi(buf2);

  if (int_buf2 >= 3528 && int_buf2 <= 3589)
    return true;

  return false;
}

bool is_discover(const char *cc)
{
  if (!luhn(cc) || !is_discover_len(cc))
    return false;

  char buf[3];

  for (int32_t i = 0; i < 3; i++)
    buf[i] = cc[i];

  buf[2] = '\0';

  if (streq(buf, "64") || streq(buf, "65"))
    return true;

  char buf1[5];
  for (int32_t i = 0; i < 5; i++)
  {
    buf1[i] = cc[i];
  }
  buf1[4] = '\0';

  if (streq(buf1, "6011"))
    return true;

  char buf2[5];
  for (int32_t i = 0; i < 5; i++)
  {
    buf2[i] = cc[i];
  }
  buf2[4] = '\0';

  int32_t int_buf2 = atoi(buf2);

  if (int_buf2 >= 622126 && int_buf2 <= 622925)
    return true;

  if (int_buf2 >= 624000 && int_buf2 <= 626999)
    return true;

  if (int_buf2 >= 628200 && int_buf2 <= 628899)
    return true;

  return false;
}

#endif
