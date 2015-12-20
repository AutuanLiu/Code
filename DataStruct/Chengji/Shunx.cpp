#include "stdio.h"
#include "stdlib.h"
#define size 100

struct student
{
	int MAXNUM;
	int n;
	int *sno;
	float *score;
};
typedef struct student *STUD;
STUD create(int m)
{
    STUD stu=(STUD)malloc(sizeof(struct student));
    if(stu!=NULL)
	{
        stu->sno=(int*)malloc(sizeof(int)*m);
		stu->score=(float*)malloc(sizeof(float)*m);
        if(stu->sno||stu->score)
		{
            stu->MAXNUM=m;
            stu->n=0;
            return stu;
        }
        else free(stu);
    }
    printf("Out of space!\n");
    return NULL;
}

void add(STUD stu)
{
	int i,n;
	printf("����ѧ����������: ");
	scanf("%d",&n);
	printf("������ѧ�źͳɼ����м��ÿո����:\n");
	for(i=0;i<n;i++)
	{
		printf("��%dλѧ����Ϣ: ",i+1);
		scanf("%d %f",&stu->sno[i],&stu->score[i]);
	}
	stu->n=n;
}
void output(STUD stu)
{
	for(int j=0;j<stu->n;j++)
	{
		printf("��%dλѧ����Ϣ: ",j+1);
		printf("%d %f\n",stu->sno[j],stu->score[j]);
	}
}
void search(STUD stu)
{
	int i,sno;
	printf("������Ҫ��ѯѧ����ѧ��: ");
	scanf("%d",&sno);
	for(i=0;i<stu->n;i++)
		if(sno==stu->sno[i])
			printf("ѧ�� �ɼ�\n");
		printf("%4d %4d\n",stu->sno[i],stu->score[i]);
}
void update(STUD stu)
{
	int i,sno,score;
	printf("������Ҫ����ѧ����ѧ��: ");
	scanf("%d",&sno);
	for(i=0;i<stu->n;i++)
		if(sno==stu->sno[i])
		{
			printf("�������µĳɼ�: ");
			scanf("%d",&score);
			stu->score[i]=score;
		}
}
void insert(STUD stu)
{
	int sno,score;
	printf("������Ҫ����ѧ����ѧ�źͳɼ�: ");
	scanf("%d %d",&sno,&score);
	stu->sno[stu->n]=sno;
	stu->score[stu->n]=score;
	stu->n=stu->n+1;
	printf("��¼����ɹ���\n");
}

void Delete(STUD stu)
{
	int i,sno;
	printf("������Ҫɾ��ѧ����ѧ��: ");
	scanf("%d",&sno);
	for(i=0;i<stu->n;i++)
		if(stu->sno[i]==sno)
		{
			stu->sno[i]=stu->sno[i+1];
			stu->score[i]=stu->score[i+1];
		}
		printf("�Ѿ��ɹ�ɾ��!");
}

int select()
{
	int n;
    do
	{
        printf("�������ѡ��(1~7): ");
        scanf("%d",&n);
    }
	while(n<1||n>7);
    return(n);
}

void main()
{
	STUD st;
	st=create(size);
	printf("\t\t*************   �˵�    **************\n\n");
    printf("\t\t******** 1. ����ѧ����¼ *************\n");
    printf("\t\t******** 2. ���ѧ����¼ *************\n"); 
	printf("\t\t******** 3. ����ѧ����¼ *************\n");
	printf("\t\t******** 4. ����ѧ����¼ *************\n");
    printf("\t\t******** 5. ����ѧ����¼ *************\n");
    printf("\t\t******** 6. ɾ��ѧ����¼ *************\n");
	printf("\t\t********   7. �˳�ϵͳ   *************\n");
	while(1)
	{
		switch(select())
		{
			case 1:		add(st);			break;
			case 2:     output(st);			break;
			case 3:		search(st);			break;
			case 4:		update(st);			break;
			case 5:		insert(st);			break;
			case 6:		Delete(st);			break;
			case 7:		exit(0);
		}
		printf("\n");
	}
}
