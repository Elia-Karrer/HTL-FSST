/**
    Name:       Elia Karrer
    Klasse:     2AHELS
    Datum:      19.10.2021
    Programm:   Shuffle Array
**/

#include <stdio.h>
#include <stdlib.h>
#include "time.h"

void shuffle(int *, int);

int main()
{
    srand(time(0));
    int arr[64], len, i;

    printf("Enter -1 to end input\n\n");
    while(1)
    {
        printf("A: Value #%d: ", len+1);
        scanf("%d", &arr[len]);

        if(arr[len] == -1 || len == 63)
            break;
        len++;
    }

    int a[len];
    for(i = 0; i < len; i++)
        a[i] = arr[i];

    shuffle(&a, len);

    printf("\n\nShuffled Array:\n");
    for(i = 0; i < len; i++)
        printf("%d\n", a[i]);
}

void shuffle(int *a, int l)
{
    int t1, t2;
    l *= 2;

    for(int i = 0; i < l; i++)
    {
        do
        {
            t1 = rand() % l;
            t2 = rand() % l;
        } while(t2 == t1);

        a[t1] += a[t2];
        a[t2] = a[t1] - a[t2];
        a[t1] -= a[t2];
    }
}
