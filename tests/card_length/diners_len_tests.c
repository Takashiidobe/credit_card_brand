#include "../../internal/card_len.h"
#include "../utils/test_utils.h"

void diners_len_tests()
{
  // return false if not starts with '36' and length < 16
  ASSERT_FALSE(is_diners_len("11111111111111"));
  ASSERT_FALSE(is_diners_len("111111111111111"));

  // return true if starts with '36' and length 14 - 19
  ASSERT_TRUE(is_diners_len("36111111111111"));
  ASSERT_TRUE(is_diners_len("361111111111111"));
  ASSERT_TRUE(is_diners_len("3611111111111111"));
  ASSERT_TRUE(is_diners_len("36111111111111111"));
  ASSERT_TRUE(is_diners_len("361111111111111111"));
  ASSERT_TRUE(is_diners_len("3611111111111111111"));

  // return true if not starts with '36' and length 16 - 19
  ASSERT_TRUE(is_diners_len("1111111111111111"));
  ASSERT_TRUE(is_diners_len("11111111111111111"));
  ASSERT_TRUE(is_diners_len("111111111111111111"));
  ASSERT_TRUE(is_diners_len("1111111111111111111"));
}
