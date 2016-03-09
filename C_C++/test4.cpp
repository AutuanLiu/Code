//颠倒的价牌

//我这里先找出差价在200到300的价格，
//没找到一个就再去找差价在800到900的所有价格，
//两个差价相减，若结果等于558，则得到所要结果。

#include <stdio.h>

int num[7]={1,2,5,6,8,9,0};
int replace[4];
int turn(int n)
{
	if(n==6)
		return 9;
	if(n==9)
		return 6;
	return n;
}
void f(int price1,int money)
{
	int a1,a2,a3,a4,sum1,sum2,tmp;
	for( a1=0;a1<6;a1++)
		for( a2=0;a2<7;a2++)
			for( a3=0;a3<7;a3++)
				for( a4=0;a4<6;a4++)
				{

					 sum1 = num[a1]*1000+num[a2]*100+num[a3]*10+num[a4];
					replace[0] = turn(num[a1]);
					replace[1] = turn(num[a2]);
					replace[2] = turn(num[a3]);
					replace[3] = turn(num[a4]);
					 sum2 = replace[3]*1000+replace[2]*100+replace[1]*10+replace[0];
					 if(sum1-sum2<0)
					 	tmp=sum2-sum1;
					 else
					 	tmp=sum1-sum2;
					if(tmp<900 && tmp > 800)
					{
						if(tmp-price1==558)
						{
							printf("money = %d\n",money);
							return;
						}


					}

				}
}
int main()
{
	int a1,a2,a3,a4,sum1,sum2,tmp;
	for( a1=0;a1<6;a1++)
		for( a2=0;a2<7;a2++)
			for( a3=0;a3<7;a3++)
				for( a4=0;a4<6;a4++)
				{

					 sum1 = num[a1]*1000+num[a2]*100+num[a3]*10+num[a4];
					replace[0] = turn(num[a1]);
					replace[1] = turn(num[a2]);
					replace[2] = turn(num[a3]);
					replace[3] = turn(num[a4]);
					 sum2 = replace[3]*1000+replace[2]*100+replace[1]*10+replace[0];
					 if(sum1-sum2<0)
					 	tmp=sum2-sum1;
					 else
					 	tmp=sum1-sum2;
					if(tmp<300 && tmp > 200)
					{
						f(tmp,sum1);

					}

				}
}

