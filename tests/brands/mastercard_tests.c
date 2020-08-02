#include "../utils/test_utils.h"

#include "../../internal/card_checker.h"

void mastercard_tests()
{
  ASSERT_TRUE(is_mastercard("5555555555554444"));
}
