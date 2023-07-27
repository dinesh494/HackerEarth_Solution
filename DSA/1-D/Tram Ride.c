#include<stdio.h>
#include<stdbool.h>
#include<malloc.h>
 
long long solve (int N, int start, int finish, int* Ticket_cost) {
    // Write your code here
    long int Best_price1 = 0;
    long int Best_price2 = 0;
    
     if(start<finish){
      for(int i=start-1 ; i<finish-1 ; i++){
         Best_price1 += Ticket_cost[i];
      }
      
      for(int i=start-1 ; i!=finish-1 ; i--){
          if(i==0){
              if(i==0 && finish-1 == N-1)
              Best_price2 += Ticket_cost[N-1];
              else
              for(int i=N-1 ; i!= finish-2 ; i--){
                  Best_price2 += Ticket_cost[i];
              }
              break;
          }else{
          Best_price2 += Ticket_cost[i];
          }
      }
      
    }else if(finish<start){
          for(int i=start-1 ; i!=finish-1 ; i--){
           Best_price1 += Ticket_cost[i-1];
        }
        for(int i=start-1;i != finish-1 ; i++){
             if(i != N-1){
                 Best_price2 += Ticket_cost[i];
             }
             else if(i==N-1){
                 for(i=0 ; i != finish-1 ; i++){
                       Best_price2 += Ticket_cost[i];
             
             break;
        } 
      }
     }
    }
    
 
    return (Best_price2<Best_price1) ? Best_price2:Best_price1;
    
}
 
 
int main() {
    int N;
    scanf("%d", &N);
    int start;
    scanf("%d", &start);
    int finish;
    scanf("%d", &finish);
    int i_Ticket_cost;
    int *Ticket_cost = (int *)malloc(sizeof(int)*(N));
    for(i_Ticket_cost = 0; i_Ticket_cost < N; i_Ticket_cost++)
    	scanf("%d", &Ticket_cost[i_Ticket_cost]);
 
    long long out_ = solve(N, start, finish, Ticket_cost);
    printf("%lld", out_);
}