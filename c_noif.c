/*
 * FizzBuzz implemented in standard C but with "no if statements"
 * (Though I feel that the while loops are cheating)
 *
 * SPDX-License-Identifier: GPL-2.0-only
 */

#include <stdio.h>

int main(int argc, char **argv) {
    int i = 0;
    int next_fizz = 3;
    int next_buzz = 5;

    while(i < 100) {
        i++;

        while ((i < next_fizz) && (i < next_buzz)) {
            printf("%i\n",i);
            i++;
        }

        while (i == next_fizz) {
            printf("fizz");
            next_fizz += 3;
        }

        while (i == next_buzz) {
            printf("buzz");
            next_buzz += 5;
        }

        printf("\n");
    }
}
