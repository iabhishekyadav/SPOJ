#include<iostream>
#include<cstdio>
using namespace std;
void multiply(long long int a[][2] , long long int b[][2] , long long int MOD)
{
	//int m[][2] = {{0,0},{0,0}};
	long long int x = ((a[0][0] * b[0][0]) %MOD + (a[0][1] * b [1][0]) %MOD) %MOD ;
	long long int y = ((a[0][0] * b[0][1]) %MOD + (a[0][1] * b [1][1]) %MOD) %MOD ;
	long long int z = ((a[1][0] * b[0][0]) %MOD + (a[1][1] * b [1][0]) %MOD) %MOD ;
	long long int w = ((a[1][0] * b[0][1]) %MOD + (a[1][1] * b [1][1]) %MOD) %MOD ;
	a[0][0] = x;
	a[0][1] = y;
	a[1][0] = z;
	a[1][1] = w;
}
void mod(long long int m[][2] ,long long  int n , long long int MOD)
{    
  // LIKE X =1
	long long int x[][2] = {{1,0},{0,1}};
	long long int y[][2] = {{1,1},{1,0}};
	while(n > 0)
	{
		if(n % 2 == 1)
		{
			multiply(x,y,MOD);
		}
		multiply(y,y,MOD);
		n /= 2 ;
	}
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
			m[i][j] = x[i][j];
	}

}
long long int fib(long long int n , long long int MOD)
{
	if (n == 0)
		return 0;
	long long int xx[2][2] = {{1,1},{1,0}};
	mod(xx, n - 1 , MOD);
	long long int ans = xx[0][0]%MOD ;
	return ans ;
}
int main()
{
	long long int t,n,m;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld %lld",&n,&m);
		m = 1<<m ;
		printf("%lld\n",fib((n + 1),m));
	}
	return 0;
}
