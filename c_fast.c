
#include <unistd.h>

#define BUFLEN 4096
struct buffer {
    int pos;
    char data[BUFLEN];
};

const char fizz[] = "fizz";
const char buzz[] = "buzz";

void flush(struct buffer *buf) {
    write(1, buf->data, buf->pos);
    buf->pos = 0;
}

void append(struct buffer *buf, const char *data) {
    while (*data) {
        // FIXME - should cmp pos with sizeof(data) and flush() if needed
        buf->data[ buf->pos++ ] = *data++;
    }
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
    struct buffer outbuf;
    outbuf.pos = 0;

    int trigger1 = 3;
    int trigger2 = 5;
    int i = 0;

    while(i <= 101) {
        int flag = 0;

        if (i == trigger1) {
            append(&outbuf, fizz);

            trigger1 += 3;
            flag = 1;
        }
        if (i == trigger2) {
            append(&outbuf, buzz);

            trigger2 += 5;
            flag = 1;
        }
        if (!flag) {
            const char *s = itoa(i, 10);
            append(&outbuf, s);
        }

        append(&outbuf, "\n");
        i++;
    }
    flush(&outbuf);
}
