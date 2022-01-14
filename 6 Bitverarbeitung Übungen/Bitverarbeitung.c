#include <stdio.h>
#include <stdbool.h>

typedef unsigned char byte;
typedef bool bit;

void to_binary(byte x)
{
    bit values[8];
    byte i;

    for(i = 0; i < 8; i++)
        values[7-i] = x & (1 << i);

    for(i = 0; i < 8; i++)
        printf("%d%s", values[i], i == 7 ? "\n" : "");
}

void to_hex(void)
{
    byte i, num = 0;
    char t;

    for(i = 0; i < 8; i++)
    {
        t = getch();
        printf("%c", t);
        if(t == '1')
            num += (1 << i);
    }

    printf(" -> %u\n", num);
}


int main(void)
{
    byte z = 39;
    z >>= 2;
    to_binary(z);
}
