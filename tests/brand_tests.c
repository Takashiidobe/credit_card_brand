#include "./utils/test_utils.h"
#include "./test_cards.h"
#include "../internal/card_checker.h"

void american_express_tests()
{
  for (uint16_t i = 0; i < amex_cards_len; i++)
    ASSERT_TRUE(is_american_express(amex_cards[i]));

  for (uint16_t i = 0; i < diners_cards_len; i++)
    ASSERT_FALSE(is_american_express(diners_cards[i]));

  for (uint16_t i = 0; i < discover_cards_len; i++)
    ASSERT_FALSE(is_american_express(discover_cards[i]));

  for (uint16_t i = 0; i < jcb_cards_len; i++)
    ASSERT_FALSE(is_american_express(jcb_cards[i]));

  for (uint16_t i = 0; i < mastercard_cards_len; i++)
    ASSERT_FALSE(is_american_express(mastercard_cards[i]));

  for (uint16_t i = 0; i < visa_cards_len; i++)
    ASSERT_FALSE(is_american_express(visa_cards[i]));

  for (uint16_t i = 0; i < unknown_cards_len; i++)
    ASSERT_FALSE(is_american_express(unknown_cards[i]));
}

void diners_tests()
{
  for (uint16_t i = 0; i < amex_cards_len; i++)
    ASSERT_FALSE(is_diners(amex_cards[i]));

  for (uint16_t i = 0; i < diners_cards_len; i++)
    ASSERT_TRUE(is_diners(diners_cards[i]));

  for (uint16_t i = 0; i < discover_cards_len; i++)
    ASSERT_FALSE(is_diners(discover_cards[i]));

  for (uint16_t i = 0; i < jcb_cards_len; i++)
    ASSERT_FALSE(is_diners(jcb_cards[i]));

  for (uint16_t i = 0; i < mastercard_cards_len; i++)
    ASSERT_FALSE(is_diners(mastercard_cards[i]));

  for (uint16_t i = 0; i < visa_cards_len; i++)
    ASSERT_FALSE(is_diners(visa_cards[i]));

  for (uint16_t i = 0; i < unknown_cards_len; i++)
    ASSERT_FALSE(is_diners(unknown_cards[i]));
}

void discover_tests()
{
  for (uint16_t i = 0; i < amex_cards_len; i++)
    ASSERT_FALSE(is_discover(amex_cards[i]));

  for (uint16_t i = 0; i < diners_cards_len; i++)
    ASSERT_FALSE(is_discover(diners_cards[i]));

  for (uint16_t i = 0; i < discover_cards_len; i++)
    ASSERT_TRUE(is_discover(discover_cards[i]));

  for (uint16_t i = 0; i < jcb_cards_len; i++)
    ASSERT_FALSE(is_discover(jcb_cards[i]));

  for (uint16_t i = 0; i < mastercard_cards_len; i++)
    ASSERT_FALSE(is_discover(mastercard_cards[i]));

  for (uint16_t i = 0; i < visa_cards_len; i++)
    ASSERT_FALSE(is_discover(visa_cards[i]));

  for (uint16_t i = 0; i < unknown_cards_len; i++)
    ASSERT_FALSE(is_discover(unknown_cards[i]));
}

void jcb_tests()
{
  for (uint16_t i = 0; i < amex_cards_len; i++)
    ASSERT_FALSE(is_jcb(amex_cards[i]));

  for (uint16_t i = 0; i < diners_cards_len; i++)
    ASSERT_FALSE(is_jcb(diners_cards[i]));

  for (uint16_t i = 0; i < discover_cards_len; i++)
    ASSERT_FALSE(is_jcb(discover_cards[i]));

  for (uint16_t i = 0; i < jcb_cards_len; i++)
    ASSERT_TRUE(is_jcb(jcb_cards[i]));

  for (uint16_t i = 0; i < mastercard_cards_len; i++)
    ASSERT_FALSE(is_jcb(mastercard_cards[i]));

  for (uint16_t i = 0; i < visa_cards_len; i++)
    ASSERT_FALSE(is_jcb(visa_cards[i]));

  for (uint16_t i = 0; i < unknown_cards_len; i++)
    ASSERT_FALSE(is_jcb(unknown_cards[i]));
}

void mastercard_tests()
{
  for (uint16_t i = 0; i < amex_cards_len; i++)
    ASSERT_FALSE(is_mastercard(amex_cards[i]));

  for (uint16_t i = 0; i < diners_cards_len; i++)
    ASSERT_FALSE(is_mastercard(diners_cards[i]));

  for (uint16_t i = 0; i < discover_cards_len; i++)
    ASSERT_FALSE(is_mastercard(discover_cards[i]));

  for (uint16_t i = 0; i < jcb_cards_len; i++)
    ASSERT_FALSE(is_mastercard(jcb_cards[i]));

  for (uint16_t i = 0; i < mastercard_cards_len; i++)
    ASSERT_TRUE(is_mastercard(mastercard_cards[i]));

  for (uint16_t i = 0; i < visa_cards_len; i++)
    ASSERT_FALSE(is_mastercard(visa_cards[i]));

  for (uint16_t i = 0; i < unknown_cards_len; i++)
    ASSERT_FALSE(is_mastercard(unknown_cards[i]));
}

void visa_tests()
{
  for (uint16_t i = 0; i < amex_cards_len; i++)
    ASSERT_FALSE(is_visa(amex_cards[i]));

  for (uint16_t i = 0; i < diners_cards_len; i++)
    ASSERT_FALSE(is_visa(diners_cards[i]));

  for (uint16_t i = 0; i < discover_cards_len; i++)
    ASSERT_FALSE(is_visa(discover_cards[i]));

  for (uint16_t i = 0; i < jcb_cards_len; i++)
    ASSERT_FALSE(is_visa(jcb_cards[i]));

  for (uint16_t i = 0; i < mastercard_cards_len; i++)
    ASSERT_FALSE(is_visa(mastercard_cards[i]));

  for (uint16_t i = 0; i < visa_cards_len; i++)
    ASSERT_TRUE(is_visa(visa_cards[i]));

  for (uint16_t i = 0; i < unknown_cards_len; i++)
    ASSERT_FALSE(is_visa(unknown_cards[i]));
}
