/**
    Check if string only contains charcters of specific characterset
    All rights reserved
    Elia Karrer, 2021
**/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    char buf[80];
    char characterset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int i, j, pass = 0;

    gets(buf);

    if(strlen(buf) < 80)
    {
        for(i = 0; i < strlen(buf); i++)
            for(j = 0; j < strlen(characterset); j++)
                if(buf[i] == characterset[j])
                    pass++;
        printf("%snly letters", (pass == strlen(buf)) ? "O" : "Not o");
    } else
        printf("String too long!");
}
