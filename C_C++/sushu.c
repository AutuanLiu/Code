#include <stdio.h>
#define N 10000*1000*10
//#define x 100001
int fun(int y)
{
    int i,k,m=0;
    int a[N]={0};
    for (i=2;i<N/2;i++) //ɸ��
    {
        if(a[i]==1)
        continue;
        //������������������λ�� 1
        for (k=2;k<=N/i;k++ )
        {if (i*k<N)   a[i*k]=1;}
    }
    //���� �� x ��0����λ�õ��±꼴Ϊ����
    for (i=2;i<N;i++ )
    {
        if (a[i]==0)
        {
            m++;
            if (m==y)
            return i;
        }
    }
}
int main()
{
    printf("%d",fun(100001));
	return 0;
}

