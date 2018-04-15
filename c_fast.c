
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

const char fizz[] = "fizz";
const char buzz[] = "buzz";
const char nl[] = "\n";

int main(int argc, char **argv) {
    int trigger1 = 3;
    int trigger2 = 5;
    int i = 1;

    while(i <= 100) {
        int flag = 0;
        if (i == trigger1) {
            write(1,fizz,sizeof(fizz));
            trigger1 += 3;
            flag = 1;
        }
        if (i == trigger2) {
            write(1,buzz,sizeof(buzz));
            trigger2 += 5;
            flag = 1;
        }
        if (!flag) {
            write(1,"xxx",3);
        }
        write(1,nl,sizeof(nl));
        i++;
    }
}
