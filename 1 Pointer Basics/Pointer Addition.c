/*
   Autor: Elia Karrer
   Datum: 20.09.2021
   Titel: Pointer_2 
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
   int zahl1, zahl2;
   int *ptr1, *ptr2;

   ptr1 = &zahl1;
   ptr2 = &zahl2;

   printf("Geben sie die 1. Zahl ein: ");
   scanf("%d", ptr1);
   printf("Geben sie die 2. Zahl ein: ");
   scanf("%d", ptr2);

   printf("Summe: %d", add(ptr1, ptr2));
}

int add(int *p1, int *p2)
{
   return(*p1 + *p2);
}