#include <stdio.h>
#include <stdlib.h>
double sos(double n);
int main()
{
long long N;
scanf("%lld", &N);
long long *arr = (long long *)malloc(N*sizeof(long long));
for (int i = 0; i < N; i++) {
	scanf("%lld", &arr[i]);
	if (i > 0)
	arr[i] += arr[i-1];
	}
double pos, x, m;

long long sum = 0;

long long res = -999999999;

m = (int)N;

for (int i = 0; i < N; i++) {

x = 1;

while (1) {

pos = (int)sos(x);

if (pos > m) {

pos = (int)sos(x-1);

break;

}

if (pos == m)

break;

x++;

}

if (i > 0)

sum = arr[((int)pos-1)+i]-arr[i-1];

else

sum = arr[(int)pos-1];

if (res < sum)

res = sum;

m--;

}

printf("%lld\n", res);


 

return 0;

}


 

double sos(double n)

{

return (n/2)*(2+(n-1));

}