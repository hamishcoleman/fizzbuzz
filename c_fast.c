
#include <unistd.h>

char outbuf[4096];

const char fizz[] = "fizz";
const char buzz[] = "buzz";

void flush(char *buf, int *buflen, char **bufptr) {
    write(1, buf, *buflen);
    *buflen = 0;
    *bufptr = buf;
}

char *append(const char *buf, int *buflen, char *bufptr) {
    while (*buf) {
        *bufptr++ = *buf++;
        (*buflen)++;
    }
    return bufptr;
}

char _itoabuf[10];
char *itoa(int i, int radix) {
    char *p = _itoabuf + sizeof(_itoabuf);
    *p = 0;
    do {
        *--p = i%radix + '0'; // FIXME radix>10
        i /= radix;
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
            p = append(fizz, &plen, p);

            trigger1 += 3;
            flag = 1;
        }
        if (i == trigger2) {
            p = append(buzz, &plen, p);

            trigger2 += 5;
            flag = 1;
        }
        if (!flag) {
            const char *s = itoa(i, 10);
            p = append(s, &plen, p);
        }

        p = append("\n", &plen, p);
        i++;
    }
    flush(outbuf, &plen, &p);
}
