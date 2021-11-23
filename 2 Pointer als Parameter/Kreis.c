/*
    Name: Elia Karrer
    Datum: 27.09.2021
    Titel: Kreis
*/

#include <stdio.h>
#include <stdlib.h>

#define PI 3.14159265

void circle(float *);

int main()
{
    float input = 0;
    float *fptr = &input;

    printf("Radius: ");
    scanf("%f", fptr);
    circle(fptr);
    printf("Area = %.2f", *fptr);
}

void circle(float *p)
{
    *p = (*p)*(*p)*PI;
}