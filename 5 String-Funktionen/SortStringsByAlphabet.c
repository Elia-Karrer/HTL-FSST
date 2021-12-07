#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned char byte;
typedef struct Name name;

struct Name {
    char content[32];
};

int main()
{
    byte len = 0, i, j, c, tmp;
    char temp;

    while(len > 255 || len < 1)
    {
        system("cls");
        printf("How many names do you want to enter? (max. 255): ");
        scanf("%d", &len);
    }
    name names[len];

    ///NAME INPUT
    for(i = 0; i < len; i++)
        for(j = 0; j < 32; j++)
        {
            tmp = getch();
            if(tmp == 8)
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
                names[i].content[j] = tmp;
            }
        }

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
                printf("Switched %d & %d\n", j, j+1);
            }
        }

    ///OUTPUT
    printf("\n");
    for(i = 0; i < len; i++)
    {
        for(c = 0; names[i].content[c] != '\0'; c++)
            printf("%c", names[i].content[c]);
        printf("\n");
    }
}
