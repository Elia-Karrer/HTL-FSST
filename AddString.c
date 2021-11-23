/**
    Adds 2 Strings
    All rights reserved
    Elia Karrer, 2021
**/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    char buf[2][256];
    int a, b;

    gets(buf[0]);
    gets(buf[1]);
    a = strlen(buf[0]);
    b = strlen(buf[1]);

    char out[a+b];
    for(int i = 0; i < a+b; i++)
        out[i] = (i < a) ? buf[0][i] : buf[1][i-a];
    out[a+b] = NULL;

    printf("\n%s", out);
}
