#ifndef __TEST_CARDS_H__
#define __TEST_CARDS_H__

#include <stdint.h>

static const char *amex_cards[] = {
    "379536705041370",
    "376315739368627",
    "345472335786393",
    "372846067062139",
    "370206877857750",
    "373079374993965",
    "344199529260098",
    "349993123259273",
    "372020994863510",
};

static const uint16_t amex_cards_len = sizeof(amex_cards) / sizeof(amex_cards[0]);

static const char *discover_cards[] = {
    "6011349729298823",
    "6011775950152943",
    "6011002725579112443",
};

static const uint16_t discover_cards_len = sizeof(discover_cards) / sizeof(discover_cards[0]);

static const char *mastercard_cards[] = {
    "5555555555554444",
    "2221007468426642",
    "2720991434480682",
};

static const uint16_t mastercard_cards_len = sizeof(mastercard_cards) / sizeof(mastercard_cards[0]);

static const char *visa_cards[] = {
    "4111111111111111",
    "4485143149119962",
    "4962540678128557",
};

static const uint16_t visa_cards_len = sizeof(visa_cards) / sizeof(visa_cards[0]);

static const char *jcb_cards[] = {
    "3588253162611965",
    "3558853527872792",
    "3579094220125973",
    "3589311203854082",
    "3569812614290604",
};

static const uint16_t jcb_cards_len = sizeof(jcb_cards) / sizeof(jcb_cards[0]);

static const char *diners_cards[] = {
    "36164620709776",
    "3647654070411744953",
    "3616422661883471541",
    "36341190171260",
};

static const uint16_t diners_cards_len = sizeof(diners_cards) / sizeof(diners_cards[0]);

static const char *unknown_cards[] = {
    "10",
    "1",
    "1111111111111111111",
    "2020202020202002020",
    "4141414141414141414",
};

static const uint16_t unknown_cards_len = sizeof(unknown_cards) / sizeof(unknown_cards[0]);
#endif
