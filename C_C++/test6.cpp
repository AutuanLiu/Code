#include <iostream>
using namespace std;
int a[1000000];
int main()
{
	int n, m, num, pm, pn, p;
	while(cin>>m>>n) 
	{	
		if(m>n)
			swap(m, n);
		a[0]=m, a[1]=n;
		pm = pn = 0;
		p=2, num=1;
		if(m+1==n)
			num=2;
		while(num<m)
		{
			if(a[pm]+m>a[pn]+n)
				a[p] = a[pn] + n;
			else
				a[p] = a[pm] + m;
			if(a[pm]+m == a[p])
				pm++;
			if(a[pn]+n == a[p])
				pn++;
			if(a[p]==a[p-1]+1)
				num++;
			else
				num=1;
			p++;
		}
		cout<<a[p-m]-1<<endl;
	}
	return 0;
}
