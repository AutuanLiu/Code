#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#define N 2
#define LEN sizeof(STUD)
typedef struct student
{
	int num;
    char name[20];
	float score;  //����к����������ݣ�һ��ָ��   �ݹ鶨���
	struct student *next;
}STUD;
STUD *creat()
{
STUD *head,*p,*q;
int i;
p=(STUD *)malloc(LEN);
printf("�������¼:(ѧ��,����,�ɼ�,����%d����¼����!ѧ����С��������)\n",N);
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

//��������
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


//�������ɾ��
STUD *del(STUD *head,int num)
{
  STUD *p,*q;
  p=head;
  if(p->next==NULL)
  {
   printf("����Ϊ��!");
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
   printf("�Ѿ�ɾ�� : %d����Ӧ�ļ�¼!\n",p->num);
  }
  else
  {
	  printf("%dû���ҵ�!\n",num);
  }
  return(head);
  }

//����Ľ�����
STUD *insert(STUD *head,STUD *stud)  //Ҫ�������ָ���Լ�ͷָ��
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
   while((p0->num>p->num)&&(p->next!=NULL))  //����ѧ�Ű�����С�����˳�����е�
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
 printf("\t\t***************   ��������   ***************\n");
 head=creat();
 printf("��ǰ��������м�¼Ϊ:\n\n");
 outlist(head);
	while(choice)
 {
	printf("\t\t***************       �˵�     ***************\n\n");
	printf("\t\t*************** 1   ��������   ***************\n");
	printf("\t\t*************** 2   ɾ������   ***************\n");
	printf("\t\t*************** 3   ��������   ***************\n");
    printf("\t\t*************** 4   �˳�ϵͳ   ***************\n");
	printf("��������Ҫ���в�������Ӧ����ţ�\n");
	scanf("%d",&choice);
	switch(choice)
	{
	case 1:  
		{
			printf("��������Ҫ���������(������֮����,����,����0�������빦��):");
			stu=(STUD*)malloc(LEN);
			scanf("%d,%s,%f",&stu->num,&stu->name,&stu->score);
			while(stu->num!=0)
			{
			head=insert(head,stu);
			printf("�޸ĺ����������Ϊ:\n");
			outlist(head);
			break;//scanf("%d",&stu->num);
			}
			break;
	  }
  case 2:
	  {
		    printf("����Ҫɾ��ѧ����Ϣ��ѧ��,����0�������빦��:");
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
			printf("�����е�������������:\n");
			outlist(head);
		    break;
	  }
  case 4:
		    exit(0);
	}
 }
}
