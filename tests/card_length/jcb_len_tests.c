#include "../../internal/card_len.h"
#include "../utils/test_utils.h"

void jcb_len_tests()
{
  // return false for length < 16
  ASSERT_FALSE(is_jcb_len("111111111111111"));

  // Return true for length 16 - 19
  ASSERT_TRUE(is_jcb_len("1111111111111111"));
  ASSERT_TRUE(is_jcb_len("11111111111111111"));
  ASSERT_TRUE(is_jcb_len("111111111111111111"));
  ASSERT_TRUE(is_jcb_len("1111111111111111111"));

  // return false for length > 19
  ASSERT_FALSE(is_jcb_len("11111111111111111111"));
}
