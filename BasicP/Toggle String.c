#include <stdio.h>

char s[100], *p;

int main()
{
    scanf("%s", s);

    for (p = s; *p != '\0'; p++)
    {
        *p += (*p < 'a') ? 'a' - 'A' : 'A' - 'a';
    }

    printf("%s", s);

    return 0;
}