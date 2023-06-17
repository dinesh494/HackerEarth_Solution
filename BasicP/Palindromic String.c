#include <stdio.h> 
#include<string.h>
 int main()
 {     
    char ch[1000];     
    scanf("%s",ch);     
    int l=strlen(ch);     
    (ch[0]==ch[l-1])?printf("YES"):printf("NO");
    }