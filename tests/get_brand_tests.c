#include <stdint.h>

#include "utils/test_utils.h"
#include "../card.h"
#include "test_cards.h"

void get_brand_tests()
{
  for (uint16_t i = 0; i < visa_cards_len; i++)
    ASSERT_EQ(VISA, get_brand(visa_cards[i]));

  for (uint16_t i = 0; i < mastercard_cards_len; i++)
    ASSERT_EQ(MASTERCARD, get_brand(mastercard_cards[i]));

  for (uint16_t i = 0; i < amex_cards_len; i++)
    ASSERT_EQ(AMERICAN_EXPRESS, get_brand(amex_cards[i]));

  for (uint16_t i = 0; i < diners_cards_len; i++)
    ASSERT_EQ(DINERS, get_brand(diners_cards[i]));

  for (uint16_t i = 0; i < discover_cards_len; i++)
    ASSERT_EQ(DISCOVER, get_brand(discover_cards[i]));

  for (uint16_t i = 0; i < jcb_cards_len; i++)
    ASSERT_EQ(JCB, get_brand(jcb_cards[i]));

  for (uint16_t i = 0; i < unknown_cards_len; i++)
    ASSERT_EQ(UNKNOWN, get_brand(unknown_cards[i]));
}
