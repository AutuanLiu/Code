//�����л�

//������һ������Ƚ�ˬ���⼸�����˲���������Ŀ�ˣ������Ծ���������ȱ����������
//��ÿ�����Ӷ�����һ�����֣���0������������Ŀ�ͱ���˴�0��������7���·����Ŀ��

#include <stdio.h>
/*
���������� 01234
���������� 12345
���������� 23456
�������л� 34567
*/
int a[4][5];
int sum;
void dfs(int row,int col,int index)
{
	//if(a[row][col]!=index)  �����仰��ʵû��Ҫ����л hzylmf ������?
	//	return ;
	if(a[row][col]==index && index==7)
		sum++;
	else {
		if(row+1<4)
				dfs(row+1,col,index+1);
		if(col+1<5)
				dfs(row,col+1,index+1);
	}
}
int main()
{
	int row,col;
	for(row=0;row<4;row++)
		for(col=0;col<5;col++)
			a[row][col]=row+col;
	dfs(0,0,0);
	printf("sum = %d\n",sum);
	return 0;
}
