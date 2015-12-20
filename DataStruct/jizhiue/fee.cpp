#include"stdio.h"
#include"stdlib.h"
#include"string.h"

struct student
{
	int num;
	char name[10];
	float score;
	struct student *next;
};
//结构体声明

struct student *h;
struct student *create()

{
	int i;
	struct student *h,*p,*q;
	p=(struct student*)malloc(sizeof(struct student));
	h=p;
	p->next=NULL;
	q=p;
	for(i=1;i<3;i++)
	{
		p=(struct student *)malloc(sizeof(struct student));
		printf("请输入一个整型数以接受为学生学号:");
		scanf("%d",&p->num);
		printf("请输入一组字符以接受为学生姓名:");
		scanf("%s",p->name);
		printf("请输入一个浮点数以接受为学生成绩:");
		scanf("%f",&p->score);
		q->next=p;
		q=p;
	}
	return(h);
}//1-创建
struct student *bianli(struct student *head,char name[])
{
	struct student *p;
	p=head->next;
	while(strcmp(p->name,name)&&p->next!=NULL)
	{
		p=p->next;
	}
	if(!strcmp(p->name,name))
	{
		printf("%d,%s,%f\n",p->num,p->name,p->score);
	}
	return(p);
}//2-遍历


void print(struct student *head)
{
	struct student *p;
	p=head->next;
	while(p!=NULL)
	{
		printf("%d,%s,%f\n",p->num,p->name,p->score);
		p=p->next;
	}
}//5-输出
void diaoyong(struct student *h)
{
	int c;
	char name[10];//呼应c==2
	/*struct    student   *jiedian=(struct student*)malloc(sizeof(struct student));//呼应c==3
	int num;//呼应c==4*/
	printf("请选择一项操作:2-遍历;3-插入;4-删除;5-输入;6-退出\n");
    scanf("%d",&c);
	if(c==2)
	{
		char name[10];
		printf("请输入要查询的学生姓名:\n");
		scanf("%s",name);
		bianli(h,name);

	}
	  if(c==5)
	  {
		  print(h);
	  }
	  else if(c==6)
		  exit(0);
}

void main()
{
	h=create();
	for(;;)diaoyong(h);
}
