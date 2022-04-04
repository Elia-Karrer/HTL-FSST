#include <stdio.h>
#include <malloc.h>
#include <stdint.h>
#define BLOCK 20


int main(void)
{
    char* arr;
    uint32_t ctr = 0, sz, i, sum;

    printf("Enter text, end with ENTER: ");

    while(1)
    {
        if(ctr >= sz-1)
        {
            sz += 5;
            arr = realloc(arr, sz * sizeof(char));
            if(!arr)
                return -1;
        }

        if(!ctr)
        {
            arr = malloc(BLOCK * sizeof(char));
            if(!arr)
                return -1;
            sz = BLOCK;
        }

        arr[ctr] = getch();

        if(arr[ctr] == 13)
        {
            arr[ctr] = 0;
            break;
        }

        printf("%c", arr[ctr]);
        ctr++;
    }

    printf("\nYou entered: %s\n", arr);
}
