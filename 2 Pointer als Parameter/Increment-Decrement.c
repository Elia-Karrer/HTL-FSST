/*
    Name: Elia Karrer
    Datum: 27.09.2021
    Titel: IncrementDecrement
*/

#include <stdio.h>
#include <stdlib.h>

void increm(int *);
void decrem(int *);

int main()
{
    int x = 0;
    increm(&x);
    printf("0++ = %d\n", x);
    decrem(&x);
    printf("1-- = %d", x);
}

void increm(int *p)
{
    (*p) += 1;
}

void decrem(int *p)
{
    (*p) -= 1;
}
