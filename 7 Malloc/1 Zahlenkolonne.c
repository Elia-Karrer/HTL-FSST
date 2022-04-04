#include <stdio.h>
#include <malloc.h>
#include <stdint.h>
#define BLOCK 5


int main(void)
{
    uint32_t* arr, ctr = 0, sz, i, sum;

    printf("Enter positive numbers, end with -1:\n");
    while(1)
    {
        if(ctr >= sz-1)
        {
            sz += BLOCK;
            arr = realloc(arr, sz * sizeof(uint32_t));
            if(!arr)
                return -1;
        }

        if(!ctr)
        {
            arr = malloc(BLOCK * sizeof(uint32_t));
            if(!arr)
                return -1;
            sz = BLOCK;
        }

        scanf("%d", arr + ctr);

        if(arr[ctr] == -1)
            break;

        ctr++;
    }

    sum = 0;
    for(i = 0; i < ctr; i++)
        sum += arr[i];

    printf("sum = %u\naverage = %u\n", sum, sum / ctr);
}
