//振兴中华

//解析：一看这题比较爽，这几天做了不少这种题目了，很明显就是树的深度遍历嘛哈哈！
//把每个格子都换成一个数字，从0算起，这样，题目就变成了从0格跳到第7格的路线数目。

#include <stdio.h>
/*
从我做起振 01234
我做起振兴 12345
做起振兴中 23456
起振兴中华 34567
*/
int a[4][5];
int sum;
void dfs(int row,int col,int index)
{
	//if(a[row][col]!=index)  这两句话其实没必要，感谢 hzylmf 提的意见?
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
