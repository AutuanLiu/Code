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
	printf("输入学生的总人数: ");
	scanf("%d",&n);
	printf("请输入学号和成绩，中间用空格隔开:\n");
	for(i=0;i<n;i++)
	{
		printf("第%d位学生信息: ",i+1);
		scanf("%d %f",&stu->sno[i],&stu->score[i]);
	}
	stu->n=n;
}
void output(STUD stu)
{
	for(int j=0;j<stu->n;j++)
	{
		printf("第%d位学生信息: ",j+1);
		printf("%d %f\n",stu->sno[j],stu->score[j]);
	}
}
void search(STUD stu)
{
	int i,sno;
	printf("请输入要查询学生的学号: ");
	scanf("%d",&sno);
	for(i=0;i<stu->n;i++)
		if(sno==stu->sno[i])
			printf("学号 成绩\n");
		printf("%4d %4d\n",stu->sno[i],stu->score[i]);
}
void update(STUD stu)
{
	int i,sno,score;
	printf("请输入要更改学生的学号: ");
	scanf("%d",&sno);
	for(i=0;i<stu->n;i++)
		if(sno==stu->sno[i])
		{
			printf("请输入新的成绩: ");
			scanf("%d",&score);
			stu->score[i]=score;
		}
}
void insert(STUD stu)
{
	int sno,score;
	printf("请输入要插入学生的学号和成绩: ");
	scanf("%d %d",&sno,&score);
	stu->sno[stu->n]=sno;
	stu->score[stu->n]=score;
	stu->n=stu->n+1;
	printf("记录插入成功！\n");
}

void Delete(STUD stu)
{
	int i,sno;
	printf("请输入要删除学生的学号: ");
	scanf("%d",&sno);
	for(i=0;i<stu->n;i++)
		if(stu->sno[i]==sno)
		{
			stu->sno[i]=stu->sno[i+1];
			stu->score[i]=stu->score[i+1];
		}
		printf("已经成功删除!");
}

int select()
{
	int n;
    do
	{
        printf("输入你的选择(1~7): ");
        scanf("%d",&n);
    }
	while(n<1||n>7);
    return(n);
}

void main()
{
	STUD st;
	st=create(size);
	printf("\t\t*************   菜单    **************\n\n");
    printf("\t\t******** 1. 输入学生记录 *************\n");
    printf("\t\t******** 2. 输出学生记录 *************\n"); 
	printf("\t\t******** 3. 查找学生记录 *************\n");
	printf("\t\t******** 4. 更改学生记录 *************\n");
    printf("\t\t******** 5. 插入学生记录 *************\n");
    printf("\t\t******** 6. 删除学生记录 *************\n");
	printf("\t\t********   7. 退出系统   *************\n");
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
