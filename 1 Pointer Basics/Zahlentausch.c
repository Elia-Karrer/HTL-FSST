#include <stdio.h>
#include <stdlib.h>

void swap(int *x, int *y);

int main()
{
    int a, b;

    printf("Geben sie eine Zahl ein:          ");
    scanf("%d", &a);
    printf("Geben sie eine weitere Zahl ein:  ");
    scanf("%d", &b);
    printf("\nNot swapped:  a == %d, b == %d", a, b);

    swap(&a, &b);
    printf("\nSwapped:      a == %d, b == %d", a, b);

    return(0);
}

void swap(int *x, int *y)
{
    int tmp = *x;
    *x = *y;
    *y = tmp;
}
