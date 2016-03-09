// 错误票据

//解析：这题貌似又是一道水题，这里用一个数组a[10000]代表id号出现的次数，
//每读入一个id时，执行a[id]++操作。
//我用了一个小技巧，在读入时保存下id号的最大值与最小值，
//这样可以为后面判断那个id遗漏（即a[id]==0）哪个id重复（即a[id]==2）提供一个范围控制。

#include <stdio.h>
int a[100000];
int main()
{
	//freopen("D:/in.txt","r",stdin);
	int n;
	scanf("%d",&n);
	int max=0,min=0;
	int tmp,i;
	for(i=0;i<n;i++)
	{
		while(scanf(" %d",&tmp)==1)
		{
			if(min>tmp)
				min=tmp;
			if(max<tmp)
				max=tmp;
			a[tmp]++;
		}
	}
	int missing,repeat;
	for(i=min;i<=max;i++)
	{
		if(a[i]==0)
			missing = i;
		if(a[i]==2)
			repeat = i;
	}
	printf("%d  %d\n",missing,repeat);
}
//PS：当测试数据比较多时，建议用freopen进行输入输出的重定向。很是方便。
