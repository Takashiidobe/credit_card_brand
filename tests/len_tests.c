#include "card_length/visa_len_tests.c"
#include "card_length/mastercard_len_tests.c"
#include "card_length/diners_len_tests.c"
#include "card_length/jcb_len_tests.c"
#include "card_length/discover_len_tests.c"
#include "card_length/american_express_len_tests.c"

void len_tests()
{
  visa_len_tests();
  mastercard_len_tests();
  diners_len_tests();
  jcb_len_tests();
  discover_len_tests();
  american_express_len_tests();
}
