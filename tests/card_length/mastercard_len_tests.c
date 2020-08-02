#include "../../internal/card_len.h"
#include "../utils/test_utils.h"

void mastercard_len_tests()
{
  // Return true for length 16
  ASSERT_TRUE(is_mastercard_len("1111111111111111"));

  // Any string length < 16 should return false
  ASSERT_FALSE(is_mastercard_len("111111111111111"));

  // Any string length > 16 should return false
  ASSERT_FALSE(is_mastercard_len("11111111111111111"));
}
