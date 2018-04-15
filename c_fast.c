
#include <stdio.h>

int main(int argc, char **argv) {
    int trigger1 = 3;
    int trigger2 = 5;
    int i = 1;

    while(i <= 100) {
        int flag = 0;
        if (i == trigger1) {
            printf("fizz");
            trigger1 += 3;
            flag = 1;
        }
        if (i == trigger2) {
            printf("buzz");
            trigger2 += 5;
            flag = 1;
        }
        if (!flag) {
            printf("%i",i);
        }
        printf("\n");
        i++;
    }
}
