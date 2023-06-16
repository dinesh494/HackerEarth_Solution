#include <stdio.h>

 

int main()

{

int num; // number of testcases

scanf("%d", &num);

for (int i = 0; i < num; i++)

{

int count, len, max_bor = 0;

scanf("%d %d", &count, &len);

for (int j = 0; j < count; j++)

{

char str[len];

scanf("%s", &str);

int bor = 0;

for (int k = 0; k < len; k++)

{

if (str[k] == '#')

bor++;

}

if (bor > max_bor)

max_bor = bor;

}

printf("%d\n", max_bor);

}

}