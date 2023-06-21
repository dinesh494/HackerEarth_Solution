#include <stdio.h>

 

int main(){

    char s[100];

    scanf("%s",&s);

 

    int ssd[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

    int sum = 0;

    for(int i = 0; s[i] != '\0'; i++)

    {

        sum += ssd[s[i] - 48];

    }

 

    printf("%d",sum);

}