/*
    Name: Elia Karrer
    Datum: 27.09.2021
    Titel: Preisnachlass
*/

#include <stdio.h>
#include <stdlib.h>

void sale(float *);

int main()
{
    float input = 0;
    float *fptr = &input;

    printf("Enter Price: ");
    scanf("%f", fptr);
    sale(fptr);
    printf("Price with sale: %.2f", *fptr);
}

void sale(float *p)
{
    *p *= 0.8;
}
