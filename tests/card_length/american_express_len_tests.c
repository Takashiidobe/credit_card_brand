#include "../../internal/card_len.h"
#include "../utils/test_utils.h"

void american_express_len_tests()
{
  // return true if length of 15
  ASSERT_TRUE(is_american_express_len("111111111111111"));

  // return false length < 15
  ASSERT_FALSE(is_american_express_len("36111111111111"));

  // return false if length > 15
  ASSERT_FALSE(is_american_express_len("1111111111111111"));
}
