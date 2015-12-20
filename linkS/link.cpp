#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#define N 2
#define LEN sizeof(STUD)
typedef struct student
{
	int num;
    char name[20];
	float score;  //结点中含有两个数据，一个指针   递归定义的
	struct student *next;
}STUD;
STUD *creat()
{
STUD *head,*p,*q;
int i;
p=(STUD *)malloc(LEN);
printf("请输入记录:(学号,姓名,成绩,输入%d个记录即可!学号由小到大排列)\n",N);
 scanf("%d,%s,%f\n",&p->num,&p->name,&p->score);
p->next=NULL;
head=p;
q=p;
for(i=1;i<N;i++)
{ 
 p=(STUD *)malloc(LEN);
 scanf("%d,%s,%f\n",&p->num,&p->name,&p->score);
 q->next=p;
 q=p;
}
p->next=NULL;
return(head);
}

//链表的输出
void outlist(STUD *head)
{
  STUD *p;
  p=head;
  while(p!=NULL)
  {
    printf("%d,%s,%f\n",p->num,p->name,p->score);
	p=p->next;
  }
}


//链表结点的删除
STUD *del(STUD *head,int num)
{
  STUD *p,*q;
  p=head;
  if(p->next==NULL)
  {
   printf("链表为空!");
   return(NULL);
  }
 while(num!=p->num  &&  p->next!=NULL)
  {
   q=p;p=p->next;
  }
  if(p->num==num)
  {
   if(p==head)
	   head=p->next;
   else if(p->next==NULL)
	   free(p);
   else
   {
    q=p->next;
	free(p);
   }
   printf("已经删除 : %d所对应的记录!\n",p->num);
  }
  else
  {
	  printf("%d没有找到!\n",num);
  }
  return(head);
  }

//链表的结点插入
STUD *insert(STUD *head,STUD *stud)  //要插入结点的指针以及头指针
{
 STUD *p,*q,*p0;
 p=head;
 p0=stud;
 if(head==NULL)
 {
  head=p0;
  p0->next=NULL;
 }
 else
 {
   while((p0->num>p->num)&&(p->next!=NULL))  //假设学号按照由小到大的顺序排列的
   {
     q=p;
	 p=p->next;
   }
   if(p0->num<p->num)
   {
    if(head==p)
		head=p0;
	else
		q->next=p0;
	p0->next=p;
   }
   else
   {
     p->next=p0;
	 p0->next=NULL;
   }
 }
 return(head);
}

void main()
{
 STUD *head,*stu;
 int del_num,choice;
 printf("\t\t***************   建立链表   ***************\n");
 head=creat();
 printf("当前链表的所有记录为:\n\n");
 outlist(head);
	while(choice)
 {
	printf("\t\t***************       菜单     ***************\n\n");
	printf("\t\t*************** 1   插入数据   ***************\n");
	printf("\t\t*************** 2   删除数据   ***************\n");
	printf("\t\t*************** 3   遍历数据   ***************\n");
    printf("\t\t*************** 4   退出系统   ***************\n");
	printf("请输入你要进行操作所对应的序号：\n");
	scanf("%d",&choice);
	switch(choice)
	{
	case 1:  
		{
			printf("请输入你要插入的数据(数据项之间以,隔开,输入0结束插入功能):");
			stu=(STUD*)malloc(LEN);
			scanf("%d,%s,%f",&stu->num,&stu->name,&stu->score);
			while(stu->num!=0)
			{
			head=insert(head,stu);
			printf("修改后的链表数据为:\n");
			outlist(head);
			break;//scanf("%d",&stu->num);
			}
			break;
	  }
  case 2:
	  {
		    printf("输入要删除学生信息的学号,输入0结束插入功能:");
			scanf("%d",&del_num);
			while(del_num!=0)
		{
			head=del(head,del_num);
			outlist(head);
		    break;//scanf("%d",&del_num);
		}
			break;
	  }
  case 3:
	  {
			printf("链表中的所有数据如下:\n");
			outlist(head);
		    break;
	  }
  case 4:
		    exit(0);
	}
 }
}
