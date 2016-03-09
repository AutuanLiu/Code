
/*排它平方数*/

//解析：这题说难不难，但就是很难得到正确答案。
//加上当时我考虑问题也不是很全面，就没做出来这道水题。
//先说明一下，i为6位数i*i最多12位，int放不下，
//long也不行，__int64不知道行不，这个数据类型我没怎么用过
//这里就不说了。我这里直接用一个20位的数组来存放i*i的结果，
//算法就是模拟连小学生都会的错位相加法。其次是判断i各个位上的数字是否相同，
//这里我用一个长度为10的数组n，i中出现的数字作为数组下标，
//然后遍历i的每一位wei进行n[wei]++操作，最后判断n中的值是否都为0 或1即可。

#include <stdio.h>
int n[10];
int ch[20];//存放i*i的乘积
int isDifferent(int num)
{
	int ok = 1,i;
	n[num%10] ++;
	while((num/=10)!=0)
	n[num%10] ++; //存在某数字就将其位 置为1
	for(i=0;i<10;i++)
		if(n[i]>1)//若某位超过1，则说明有重复数字存在
		{ok = 0;break;}
		return ok;
}
void init()
{
	int i;
	for( i=0;i<10;i++)
        n[i]=0;
	for(i=0;i<20;i++)
		ch[i]=0;
}
int main()
{
	int i,j;
	for(i=1e5;i<1e6;i++)
	{
		if(isDifferent(i))//将i中有重复数字的排除
		{
			int tmp = i;
			for(j=0;j<6;j++)
			{
				int mul = (tmp%10)*i;
				int index = j;
				do
				{
					ch[index]+= mul%10; //每位数分别相乘i，个位存入，逢十进一
					if(ch[index]>=10)
                    ch[index+1]+=ch[index]/10;
					ch[index]%=10;
					index++;
				}
				while((mul/=10)!=0);
				tmp/=10;
			}
			int ok =1,m,z;
			for(m=20;ch[m]==0;m--)
			;//找到i*i的个位数所在的位置
			for(;m>=0;m--)
				for(z=0;z<10;z++)
					if(ch[m]==z&&n[z]==1)//判断该数字是否i中已有
						ok=0;
					if(ok)
						printf("%d\n",i);
		}
		init();
	}
	return 0;
}

