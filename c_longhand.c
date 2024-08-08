/*
 * FizzBuzz implemented in standard C using the dumbest algorythm
 *
 * Inspired by https://andreasjhkarlsson.github.io/jekyll/update/2023/12/27/4-billion-if-statements.html
 *
 * SPDX-License-Identifier: GPL-2.0-only
 */

#include <stdio.h>

void print_answer(int i) {
    /* paste ./c_longhand_meta output here */
    // e.g:
    // if (i == 1) printf("1\n");
    // if (i == 2) printf("2\n");
    // if (i == 3) printf("fizz\n");
    // etc
}

int main(int argc, char **argv) {
    int i;

    for(i=1; i<=100; i++) {
        print_answer(i);
    }
}
