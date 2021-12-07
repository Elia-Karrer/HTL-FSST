#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define MAX 12

typedef unsigned char byte;

bool isDiv(char *, const char *);

int main()
{
    int i, j, f = 0, t = 0;
    float sum = 0;
    int len[(1<<MAX)>>1];
    char buf[1<<MAX];

    gets(buf);
    ///End string with divider
    if(isDiv(buf[strlen(buf)-1], " ,.") == 0)
    {
        buf[strlen(buf)] = '.';
        buf[strlen(buf)+1] = '\0';
    }
    ///COPY
    char str[strlen(buf)];
    for(i = 0; i < strlen(buf); i++)
        str[i] = buf[i];

    ///CORE
    for(i = 0; i < strlen(str)+1; i++)
    {
        if(i != strlen(str))
            if(isDiv(str[i], " ,."))
            {
                len[f] = t;
                t = 0;
                f++;
            }
            else
                t++;
    }
    len[f] = 0;

    t = 0;
    for(i = 0; len[i] != 0; i++)
    {
        sum += len[i];
        t++;
    }
    sum /= t;

    printf("%d words and %.2f chars in average", t, sum);
}

bool isDiv(char * chr, const char *key)
{
    for(int i = 0; i < strlen(key); i++)
        if(chr == key[i])
            return 1;
    return 0;
}
