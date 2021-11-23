/**
    Name:       Elia Karrer
    Klasse:     2AHELS
    Datum:      18.10.2021
    Programm:   Subset
**/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool check(int *, int *, int, int);

int main()
{
    int arr1[64], arr2[64], len1 = 0, len2 = 0, i;

    printf("Enter -1 to end input\n\n");
    while(1)
    {
        printf("A: Value #%d: ", len1+1);
        scanf("%d", &arr1[len1]);

        if(arr1[len1] == -1 || len1 == 63)
            break;
        len1++;
    }
    printf("\n");
    while(1)
    {
        printf("B: Value #%d: ", len2+1);
        scanf("%d", &arr2[len2]);

        if(arr2[len2] == -1 || len2 == 63)
            break;
        len2++;
    }

    int a1[len1], a2[len2];
    for(i = 0; i < len1; i++)
        a1[i] = arr1[i];
    for(i = 0; i < len2; i++)
        a2[i] = arr2[i];

    printf("B is%sSubset of A", (check(&arr1, &arr2, len1, len2)) ? " " : " not a ");
    getch();
}

bool check(int *a, int *b, int la, int lb)
{
    int tmp1 = 0, tmp2 = 0, i;

    for(i = 0; i < la; i++)
        tmp1 = (a[i] > tmp1) ? a[i] : tmp1;
    for(i = 0; i < lb; i++)
        tmp2 = (b[i] > tmp2) ? b[i] : tmp2;

    return(tmp2 < tmp1);
}