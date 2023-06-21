#include<stdio.h>
 #include<stdbool.h> 
  #include<malloc.h> 
   #include <string.h>  
    int solve (char* S, char k)    {   
         int count=0;       
         int i=0;       
         while(1){               
            if(S[i]==k){                       
                count++;       
                }                      
            if(i>=strlen(S)){                            
                break;       
            }                        
            i++;   
            }                          
            return count;
            }      
            
            int main()       {     
                int T;           
                scanf("%d", &T);            
                int i=1;             
                while(i<=T)         {         
                    char* S = (char*)malloc(200000 * sizeof(char));                  
                    scanf("\n%[^\n]s", S);                       
                    char k;                        
                    scanf(" %c", &k);                             
                    int out_ = solve(S, k);                             
                    printf("%d \n", out_);                                
                    free(S);                                   
                    i++;    
                    }                             
            }