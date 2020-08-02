#include "../../internal/card_len.h"
#include "../utils/test_utils.h"

void visa_len_tests()
{
  // Should return true for a card with a length of 16.
  ASSERT_TRUE(is_visa_len("1111111111111111"));

  // Any string length < 16 should return false
  ASSERT_FALSE(is_visa_len("111111111111111"));

  // Any string length > 16 should return false
  ASSERT_FALSE(is_visa_len("11111111111111111"));
}
