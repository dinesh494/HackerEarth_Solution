#include <stdio.h>

int main()

{

    int t;

    scanf("%d",&t);

    while(t--)

    {

        int n;

        scanf("%d",&n);

        int cur,prev,out=0;

        scanf("%d",&prev);

        for(int i=0;i<n-1;i++)

        {

            scanf("%d",&cur);

            if(prev%2==1)

            {

                if(cur%2==0)

                    out+=2;

                else

                    out+=1;

                prev=0;

                cur=0;

            }

            else

            {

                prev=cur;

            }

        }

        if(cur%2==1)

            out+=2;

        printf("%d\n",out);

    }

}