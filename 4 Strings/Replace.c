/**
    Replaces chosen character in string with another chosen character 
    All rights reserved
    Elia Karrer, 2021
**/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    char buf[256];
    int i;
    char a, b;

    gets(buf);

    printf("Replace ");
    a = getch();
    printf("%c", a);

    printf(" with ");
    b = getch();
    printf("%c", b);

    if(strlen(buf) < 256)
    {
        for(i = 0; i < strlen(buf); i++)
            buf[i] = (buf[i] == a) ? b : buf[i];
        printf("\n%s", buf);
    } else
        printf("String too long!");
}
