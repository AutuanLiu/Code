// ����Ʊ��

//����������ò������һ��ˮ�⣬������һ������a[10000]����id�ų��ֵĴ�����
//ÿ����һ��idʱ��ִ��a[id]++������
//������һ��С���ɣ��ڶ���ʱ������id�ŵ����ֵ����Сֵ��
//��������Ϊ�����ж��Ǹ�id��©����a[id]==0���ĸ�id�ظ�����a[id]==2���ṩһ����Χ���ơ�

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
//PS�����������ݱȽ϶�ʱ��������freopen��������������ض��򡣺��Ƿ��㡣
