/*
   Autor: Elia Karrer
   Datum: 20.09.2021
   Titel: Pointer_1 
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
   int var = 200;
   int *ptr;
   ptr = &var;

   printf("Variable Adresse:       %p\n", &var);
   printf("Variable Wert:          %d\n", var);
   printf("Pointer Adresse:        %p\n", &ptr);
   printf("Pointer Wert:           %p\n", ptr);
   printf("Variable per Pointer:   %d\n", *ptr);

   return(0);
}