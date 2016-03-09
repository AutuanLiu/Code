#include <stdio.h>
int m,n,a[10][10];
int sum=0;
bool visited[10][10]={{true}};
int move[][2]={{1,0},{0,1},{-1,0},{0,-1}};
int pre(){
	int f;
	int i,j;
	scanf("%d%d",&m,&n);
	for(i=0;i<n;i++)
		for(j=0;j<m;j++){
			scanf("%d",&a[i][j]);
			sum+=a[i][j];
		}
	f=sum%2;
	sum/=2;
	return f;
}
int dfs(int i,int j,int temp)
{
	if(temp==sum)
		return 1;
	int ii,jj,k,result=0;
	for(k=0;k<4;k++){
		ii=i+move[k][0];
		jj=j+move[k][1];
		if(ii>=0&&ii<n&&jj>=0&&jj<m)
			if(!visited[ii][jj]&&temp+a[ii][jj]<=sum)
			{
				visited[ii][jj]=true;
				result=dfs(ii,jj,temp+a[ii][jj]);
				if(result>0)
					return result+1;
				visited[ii][jj]=false;
			}
	}
	return 0;
}
int main(){
//	freopen("D:/in.txt","r",stdin);
	if(pre())
	{
		printf("0\n");
	} else {
		int k=dfs(0,0,a[0][0]);
		printf("%d\n",k);
	}
	
	return 0;
}
