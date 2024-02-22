/*
 * FizzBuzz implemented in standard C using simple accumulators and no
 * division
 *
 * SPDX-License-Identifier: GPL-2.0-only
 */

#include <stdio.h>

int main(int argc, char **argv) {
    int i;
    int next_fizz = 3;
    int next_buzz = 5;

    for(i=1; i<=100; i++) {
        int flag = 0;

        if (i == next_fizz) {
            printf("fizz");
            next_fizz += 3;
            flag = 1;
        }

        if (i == next_buzz) {
            printf("buzz");
            next_buzz += 5;
            flag = 1;
        }

        if (!flag) {
            printf("%i",i);
        }

        printf("\n");
    }
}
