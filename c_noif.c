/*
 * FizzBuzz implemented in standard C but with "no if statements"
 * (since while and for loops are just fancy if statements, I have not used
 * them and either)
 *
 * SPDX-License-Identifier: GPL-2.0-only
 */

#include <stdio.h>

const char *str_fizz[] = {
    "fizz",
    "",
    "",
};
const char *str_buzz[] = {
    "buzz",
    "",
    "",
    "",
    "",
};
const char *str_int[] = {
    "%i\n",
    "\n",
    "\n",
};

int i;

static inline void do_one() {
    i = i + 1;
    int printed = 0;
    printed += printf(str_fizz[i % 3]);
    printed += printf(str_buzz[i % 5]);
    printf(str_int[printed / 4],i);
}

#define DO_TEN() { \
    do_one(); \
    do_one(); \
    do_one(); \
    do_one(); \
    do_one(); \
    do_one(); \
    do_one(); \
    do_one(); \
    do_one(); \
    do_one(); \
} while(0)

int main(int argc, char **argv) {
    i = 0;

    DO_TEN();
    DO_TEN();
    DO_TEN();
    DO_TEN();
    DO_TEN();
    DO_TEN();
    DO_TEN();
    DO_TEN();
    DO_TEN();
    DO_TEN();
}
