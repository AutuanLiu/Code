
#include <stdio.h>
int months[]={31,28,31,30,31,30,31,31,30,31,30,31};
int isLeap(int year)
{
	if((year%400==0)||(year%4==0&&year%100!=0))
		return 1;
	else
		return 0;
}
int main()
{
	int days = 8113-1;//������������Ϊ��һ�죬����������Ҫ��ȥһ
	int year = 1777,i;
	//printf("%d\n",isLeap(1778));
	for(i=4;i<12;i++)
	{
		if(days>months[i])
		{
			days -= months[i];
			if(i==11)
				year++;
		}
	}
	//1777��
	while(days>364+isLeap(year+1))
        //��1778�꿪ʼ
	{
		year++;
		if(isLeap(year))
			days--;

		days -= 365;
	}
	for(i=0;i<12;i++)
	{
		if(days>months[i])
		{
			days-=months[i];

		} else {
			break;
		}

	}

	if(days==0)//���days��Ϊ0����˵��days������һ���µ����һ��
	{
		i--;
		if(i==-1)
		{
			i=11;
		}
		days = months[i];

	}
	int month = i+1;
	if(isLeap(year)&& month>2)
		days--;
	printf("%d-%d-%d\n",year,month,days);
	return 1;
}
