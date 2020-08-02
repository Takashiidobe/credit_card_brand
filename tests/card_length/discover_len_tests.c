#include "../../internal/card_len.h"
#include "../utils/test_utils.h"

void discover_len_tests()
{
  // Any string length 16 - 19 should return true
  ASSERT_TRUE(is_discover_len("1111111111111111"));
  ASSERT_TRUE(is_discover_len("11111111111111111"));
  ASSERT_TRUE(is_discover_len("111111111111111111"));
  ASSERT_TRUE(is_discover_len("1111111111111111111"));

  // Any string length > 19 should return false
  ASSERT_FALSE(is_discover_len("11111111111111111111"));
}
