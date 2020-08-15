# Credit Card Matcher

## This is a Work in Progress

This repo currently checks for a card in these card brands:

- VISA
- MASTERCARD
- DINERS
- JCB
- AMERICAN_EXPRESS
- DISCOVER

When you call the function `get_brand` with a credit card number, it will return either the above if it finds a match or `UNKNOWN`.

The get card brand function will disregard all characters that aren't numeric in the string.

## Makefile

`make all` and `make test` run the tests for this project.

`make release` creates a release header file called `distribute.h` for distribution. This uses quom, which requires python3 and can be installed with pip with `pip3 install quom`.

`make docs` creates the docs, which are under construction.
