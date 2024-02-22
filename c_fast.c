
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
        buf->data[ buf->pos++ ] = *data++;
        // FIXME - should flush() if pos == sizeof(data)
    }
}

struct istr {
    int msd;
    char data[10];
};

void istr_init(struct istr *buf) {
    int msd = sizeof(buf->data);
    buf->data[ --msd ] = 0;
    while(msd) {
        buf->data[ --msd ] = '0';
    }
    buf->msd = sizeof(buf->data)-2;
}

void istr_inc(struct istr *buf) {
    int digit = sizeof(buf->data)-2;
    while (buf->data[digit] == '9') {
        buf->data[digit] = '0';
        digit--; // FIXME - should handle underflow
        buf->msd = digit;
    }
    buf->data[digit] ++;
}

const char *istr_str(struct istr *buf) {
    return &buf->data[ buf->msd ];
}

int main(int argc, char **argv) {
    struct buffer outbuf;
    outbuf.pos = 0;

    struct istr itoa;
    istr_init(&itoa);
    istr_inc(&itoa);

    int trigger1 = 3;
    int trigger2 = 5;
    int i = 1;

    while(i <= 100) {
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
            append(&outbuf, istr_str(&itoa));
        }

        append(&outbuf, "\n");

        istr_inc(&itoa);
        i++;
    }
    flush(&outbuf);
}
