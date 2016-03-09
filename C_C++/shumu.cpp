#include<stdio.h>  
int count(int n)
{
int count = 0;
if(n%2==0 && n>0)
{
count = (4+n)/2;
}
else if(n%2==1 && n>0)
{
count = (3-n)/2;
}
else
{
}
return count

}
int main()
{
	count(100);
	return 0;
}
