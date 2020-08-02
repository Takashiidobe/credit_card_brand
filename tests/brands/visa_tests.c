#include "../utils/test_utils.h"

#include "../../internal/card_checker.h"

void visa_tests()
{
  ASSERT_TRUE(is_visa("4111111111111111"));

  ASSERT_FALSE(is_visa("41111111111111111"));

  ASSERT_FALSE(is_visa("1111111111111111"));
}
