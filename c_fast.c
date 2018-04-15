
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

const char fizz[] = "fizz";
const char buzz[] = "buzz";
const char nl[] = "\n";

int itoa(int i, char *buf, int radix) {
    int digits = 0;
    do {
        *buf++ = i%radix + '0';
        i /= radix;
        digits ++;
    } while(i);
    *buf = 0;
    return digits;
}

int main(int argc, char **argv) {
    int trigger1 = 3;
    int trigger2 = 5;
    int i = 0;

    while(i <= 100) {
        int flag = 0;
        if (i == trigger1) {
            write(1,fizz,sizeof(fizz)-1);
            trigger1 += 3;
            flag = 1;
        }
        if (i == trigger2) {
            write(1,buzz,sizeof(buzz)-1);
            trigger2 += 5;
            flag = 1;
        }
        if (!flag) {
            char buf[10];
            int digits = itoa(i,buf,10);
            write(1,buf,digits);
        }
        write(1,nl,sizeof(nl)-1);
        i++;
    }
}
