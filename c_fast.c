
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

char outbuf[4096];

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

    char *p = outbuf;
    int plen = 0;

    while(i <= 101) {
        int flag = 0;
        if (i == trigger1) {
            memcpy(p, fizz, sizeof(fizz)-1);
            p += sizeof(fizz)-1;
            plen += sizeof(fizz)-1;

            trigger1 += 3;
            flag = 1;
        }
        if (i == trigger2) {
            memcpy(p, buzz, sizeof(buzz)-1);
            p += sizeof(buzz)-1;
            plen += sizeof(buzz)-1;

            trigger2 += 5;
            flag = 1;
        }
        if (!flag) {
            int digits;
            char *a = itoa(i,&digits,10);

            memcpy(p, a, digits);
            p += digits;
            plen += digits;
        }
        *p++ = '\n';
        plen++;
        i++;
    }
    write(1, outbuf, plen);
}
