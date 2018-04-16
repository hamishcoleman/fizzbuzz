
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

const char fizz[] = "fizz";
const char buzz[] = "buzz";
const char nl[] = "\n";

char _itoabuf[10];
char *itoa(int i, int *digits, int radix) {
    char *p = _itoabuf + sizeof(_itoabuf);
    *p = 0;
    *digits = 0;
    do {
        *--p = i%radix + '0'; // FIXME radix>10
        i /= radix;
        (*digits) ++;
    } while(i);
    return p;
}

int main(int argc, char **argv) {
    int trigger1 = 3;
    int trigger2 = 5;
    int i = 0;

    while(i <= 101) {
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
            int digits;
            char *p = itoa(i,&digits,10);
            write(1,p,digits);
        }
        write(1,nl,sizeof(nl)-1);
        i++;
    }
}
