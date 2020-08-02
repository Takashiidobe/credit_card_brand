#include "utils/test_utils.h"
#include "../internal/luhn.h"

void luhn_tests()
{
  ASSERT_TRUE(luhn("4111111111111111"));
  ASSERT_FALSE(luhn("4111111111111113"));
}
