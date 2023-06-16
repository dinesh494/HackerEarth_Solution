#include<bits/stdc++.h>
using namespace std;
int main()
{
  int t;      //t=no. of test cases
  cin>>t;
  while(t--)          
{
  int n,g,p,f=0,s=0;  
//n=no. of participants, g=green balloon cost, p=purple balloon cost
//f will count no. of participants who solved first question 
//s will count no. of participants who solved second question 
  cin>>g>>p;          
  cin>>n;             
  for(int i=0;i<n;i++)
{
  int l,m;  //l:1 or 0, m:1 or 0(as per question)
  cin>>l>>m;
  if(l==1)
  f++;
  if(m==1)
  s++;
}
  int price1=0,price2=0;
  price1=f*g+s*p;      //see note below
  price2=f*p+s*g;
  if(price1<price2)
{
  cout<<price1<<endl;
}
  else
{
  cout<<price2<<endl;
}
}
}