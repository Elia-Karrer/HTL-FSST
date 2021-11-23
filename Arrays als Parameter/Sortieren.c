/**
    Name:       Elia Karrer
    Klasse:     2AHELS
    Datum:      18.10.2021
    Programm:   Zahlen sortieren mit ptr
**/


#include <stdio.h>
#include <stdlib.h>
#define _max 8

void sort(int *, int);

int main()
{
    int buf[1 << _max];
    int i, len = 0;

    printf("Enter -1 to end input\n\n");
    while(1)
    {
        printf("Value #%d: ", len+1);
        scanf("%d", &buf[len]);

        if(buf[len] == -1 || len == 63)
            break;
        len++;
    }

    int values[len];
    for(i = 0; i < len; i++)
        values[i] = buf[i];

    sort(&values[0], len);

    printf("\nSorted:\n");
    for(i = 0; i < len; i++)
        printf("%d\n", values[i]);

}

void sort(int *p, int l)
{
    int i, j;

    for (i = 1; i < l; i++)
        for (j = 0; j < l-1 ; j++)
          if (p[j] > p[j + 1])
          {
              p[j] += p[j + 1];
              p[j + 1] = p[j] - p[j + 1];
              p[j] -= p[j + 1];
          }
}
