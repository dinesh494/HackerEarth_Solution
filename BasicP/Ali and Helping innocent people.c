#include<stdio.h>
int main()
{   
	 char str[10];  
	 gets(str);

 

    if((str[0]+str[1])%2==0&&(str[3]+str[4])%2==0&&(str[4]+str[5])%2==0&&(str[7]+str[8])%2==0)    
	{
		if(str[2]>=65&&str[2]<=90&&str[6]==45)  
		      {            
				 if(str[2]==65||str[2]==69||str[2]==73||str[2]==79||str[2]==85||str[2]==89)            				
				 {                
					 printf("invalid");      
					       }            
						   else
						   {         
							       printf("valid");  
								             }     
											    }

           }
		   else
		   {   
			 printf("invalid");
			 }

 

return 0;
}

 