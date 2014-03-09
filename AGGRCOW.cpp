#include<iostream>
#include<stdio.h>
#include<algorithm>
int a[100001];
int nc;
using namespace std;
// here high is forced to come at pos of ( last yes.. ) thus in the end situation id like (yes yes) so we shift mid to upper bounds i.e. towards high by adding one in line 24.
// situation is like :  yes yes yes yes no no no no ..... no    for the min dist ....
int main()
{
	int ns;
	int t,i,cnt,lo,hi,x,pos,n;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&ns,&nc);
		for(i=0;i<ns;i++)
			scanf("%d",&a[i]);
		sort(a,a+ns);
		lo = 0 ; hi = a[ns-1]+1 ;
		while(lo < hi)
		{
			cnt = 1;   // cnt 1 because at initial pos there is a cow
			x = lo + (hi - lo + 1 )/2 ;
			pos = a[0];
			for(i = 1 ; i < ns ;i++)
			{
				if((a[i] - pos) >= x )  // now the min dist sud be atleast x .
				{
					cnt++;
					pos = a[i] ;
				}
				if(cnt == nc)    // just for efficiency..
					break ;
			}
			if(cnt >=  nc) 
				lo  = x ;
			else
				hi = (x-1) ;
		}
		printf("%d\n",lo);
	}
	return 0;
}
