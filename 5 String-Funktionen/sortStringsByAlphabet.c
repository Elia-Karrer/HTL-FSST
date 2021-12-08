/**
    Sorts strings by alphabetical order
    All rights reserved
    Elia Karrer, 2021
**/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 8

typedef unsigned char byte;
typedef struct Name name;

struct Name {
    char content[32];
};


int main()
{
    byte len = 0, i, j, c, tmp, end = 0;
    char temp;
    name names[1<<MAX];

    ///NAME INPUT
    printf("ENTER = New Name\nENTER + ctrl = End input\n\nEnter phrases to sort: \n");
    for(i = 0; i < (1<<MAX); i++)
    {
        for(j = 0; j < 32; j++)
        {
            tmp = getch();
            if(tmp == 8 && j > 1)
            {
                printf("\b \b");
                j -= 2;
            }
            else
            {
                printf("%c", tmp);
                if(tmp == 13)
                {
                    names[i].content[j] = '\0';
                    printf("\n");
                    break;
                }
                if(tmp == 10)
                {
                    names[i].content[j] = '\0';
                    end = 1;
                    break;
                }
                names[i].content[j] = tmp;
            }
        }
        if(end) break;
    }
    len = i+1;

    ///SORT
    for(i = 0; i < len; i++)
        for(j = 0; j < len-1; j++)
        {
            if (strcmp(names[j].content, names[j+1].content) > 0)
            {
                for(c = 0; c < 32; c++)
                {
                    temp = names[j].content[c];
                    names[j].content[c] = names[j+1].content[c];
                    names[j+1].content[c] = temp;
                }
            }
        }

    ///OUTPUT
    printf("\nSorted:\n");
    for(i = 0; i < len; i++)
    {
        for(c = 0; names[i].content[c] != '\0'; c++)
            printf("%c", names[i].content[c]);
        printf("\n");
    }
}
