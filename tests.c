#include "tests/luhn_tests.c"
#include "tests/brand_tests.c"
#include "tests/len_tests.c"
#include "tests/get_brand_tests.c"

int main()
{
  luhn_tests();
  mastercard_tests();
  visa_tests();
  len_tests();
  get_brand_tests();
}
