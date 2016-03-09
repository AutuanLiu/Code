#include <stdio.h>
#define infinity -10000
typedef struct pos
{
    int low,high,sum;
}*info;
info crossingsub(int *a,int low,int high)
//返回下标跨越中点的最大子数组的边界下标和最大子数组的和
{
    info pos;
    int leftsum=infinity,rightsum=infinity,sum1=0,sum2=0;
    int mid=(low+high)/2;
    int i,j;
    for(i=mid;i>=0;i--)
    {
        sum1=sum1+a[i];
        if(sum1>leftsum)
        {
            leftsum=sum1;
            pos->low=i;
        }
    }
    for(j=mid+1;j<=high;j++)
    {
        sum2=sum2+a[j];
        if(sum2>rightsum)
        {
            rightsum=sum2;
            pos->high=j;
        }
    }
    pos->sum=leftsum+rightsum;
    return pos;
}

info subarray(int *a,int low,int high)
{
    info pos,pos1,pos2,pos3;int mid;
    if(high==low)
       {
           pos->low=low;
           pos->high=high;
           pos->sum=a[low];
           return pos;
       }
    else
    {
        mid=(low+high)/2;
        int b[high],c[high];
        pos1=subarray(a,low,mid);
        pos2=subarray(a,mid+1,high);
        pos3=crossingsub(a,low,high);
        if(pos1->sum>=pos2->sum && pos1->sum>=pos3->sum)
            return pos1;
        else if(pos2->sum>=pos1->sum&&pos2->sum>=pos3->sum)
            return pos2;
        else
            return pos3;
    }
}
int main()
{
    int a[10]={13,-3,-25,20,-3,16,-23,18};
    info pos;
    pos=subarray(a,0,7);
    printf("最大子数组的下标:%d，上标:%d,和为:%d",pos->low,pos->high,pos->sum);
    return 0;
}
