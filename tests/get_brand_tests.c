#include "utils/test_utils.h"
#include "../card.h"

void get_brand_tests()
{
  ASSERT_EQ(VISA, get_brand("4111111111111111"));
  ASSERT_EQ(MASTERCARD, get_brand("5500000000000004"));
  ASSERT_EQ(AMERICAN_EXPRESS, get_brand("340000000000009"));
  ASSERT_EQ(DINERS, get_brand("3000000000000004"));
  ASSERT_EQ(DISCOVER, get_brand("6011000000000004"));
  ASSERT_EQ(JCB, get_brand("3528057073389113"));
  ASSERT_EQ(UNKNOWN, get_brand("9999999999999999"));
}
