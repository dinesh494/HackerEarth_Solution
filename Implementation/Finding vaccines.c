#include <stdio.h>

 

int main(){

 

        int no_of_vaccines;

        

        int len;

        scanf("%d\n%d\n", &no_of_vaccines,&len);

 

        char virus[1000];

        scanf("%s\n",&virus);

        int g_v = 0, c_v = 0;

 

        for(int i = 0; i < len; i++)

        {

            if(virus[i] == 'G') c_v++;

            else if(virus[i] == 'C')    g_v++;

 

        }

 

        int itr[no_of_vaccines];

        int max_idx = 1, max = 0;

        for(int i = 0; i < no_of_vaccines; i++)

        {

            int interactions = 0;

            int m;

            scanf("%d\n", &m);

            char vaccine[1000];

            scanf("%s\n", &vaccine);

 

            int g_vc = 0, c_vc = 0;

 

            for(int i = 0; i < m; i++)

            {

                if(vaccine[i] == 'G')   g_vc++;

                else if(vaccine[i] == 'C')  c_vc++;

 

            }

 

            interactions = (c_v*c_vc) + (g_v*g_vc);

            // printf("%d\n",interactions);

            itr[i] = interactions;

 

            if(itr[i]>max)

            {

                max = itr[i];

                max_idx = i+1;

            }

        }

 

        printf("%d\n",max_idx);

        

    

}