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
//�ṹ������

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
		printf("������һ���������Խ���Ϊѧ��ѧ��:");
		scanf("%d",&p->num);
		printf("������һ���ַ��Խ���Ϊѧ������:");
		scanf("%s",p->name);
		printf("������һ���������Խ���Ϊѧ���ɼ�:");
		scanf("%f",&p->score);
		q->next=p;
		q=p;
	}
	return(h);
}//1-����
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
}//2-����


void print(struct student *head)
{
	struct student *p;
	p=head->next;
	while(p!=NULL)
	{
		printf("%d,%s,%f\n",p->num,p->name,p->score);
		p=p->next;
	}
}//5-���
void diaoyong(struct student *h)
{
	int c;
	char name[10];//��Ӧc==2
	/*struct    student   *jiedian=(struct student*)malloc(sizeof(struct student));//��Ӧc==3
	int num;//��Ӧc==4*/
	printf("��ѡ��һ�����:2-����;3-����;4-ɾ��;5-����;6-�˳�\n");
    scanf("%d",&c);
	if(c==2)
	{
		char name[10];
		printf("������Ҫ��ѯ��ѧ������:\n");
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
