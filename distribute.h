#ifndef __CARD_H__
#define __CARD_H__

#ifndef __GET_BRAND_H__
#define __GET_BRAND_H__

#ifndef __CARD_CHECKER_H__
#define __CARD_CHECKER_H__

#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h>

#ifndef __CARD_LEN_H__
#define __CARD_LEN_H__

#include <stdbool.h>
#include <stdint.h>
#include <string.h>

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
  if (cc[0] == '3' && cc[1] == '6')
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

  if (
      starts_with(cc, "36") ||
      starts_with(cc, "38") ||
      starts_with(cc, "39") ||
      starts_with(cc, "3095"))
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

  if (in_range(cc, 622126, 622925) ||
      in_range(cc, 624000, 626999) ||
      in_range(cc, 628200, 628899))
    return true;

  return false;
}

#endif

#ifndef __CARD_ENUM_H__
#define __CARD_ENUM_H__

typedef enum Card
{
  VISA,
  MASTERCARD,
  DINERS,
  JCB,
  AMERICAN_EXPRESS,
  DISCOVER,
  UNKNOWN,
} Card;

#endif

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

#endif
