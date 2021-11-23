/**
    Name:       Elia Karrer
    Klasse:     2AHELS
    Datum:      18.10.2021
    Programm:   Array kopieren
**/

#include <stdio.h>
#include <stdlib.h>
#define _len 16

void duplicate(int *, int *,  int);

int main()
{
    int arr1[_len], arr2[_len], i;

    printf("Array 1:\n");
    for(i = 0; i < _len; i++)
    {
        arr1[i] = 1 << (i+1);
        printf("%d\n", arr1[i]);
    }


    printf("\nArray 2:\n");
    duplicate(&arr1, &arr2, _len);
    for(i = 0; i < _len; i++)
        printf("%d\n", arr2[i]);


}

void duplicate(int *a, int *b, int l)
{
    for(int i = 0; i < l; i++)
        b[i] = a[i];
}