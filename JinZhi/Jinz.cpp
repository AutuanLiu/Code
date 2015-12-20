#include "stdio.h"
#include "stdlib.h"
#include "math.h" 
#define MaxSize 100;  
#define Incerment 10;
typedef   struct
{      
    int   *data,*top;   //����//ջ����λ��
    int   stacksize;   //ջ�е����Ԫ�ظ���
}SeqStack;     
int InitStack(SeqStack &S)  //��ʼ��ջ
{      
	S.data=(int *)malloc(sizeof(int)*100);
	if(!S.data)
		exit(0);
    S.top=S.data;
	S.stacksize=MaxSize; 
    return 1;
}  

int IsEmptyStack(SeqStack &S)
{
    if(S.top==S.data)
        return 1;
    else
        return 0;
}

int Push(SeqStack &S,int e)
{      
    if(S.top-S.data >= S.stacksize )     
    {
        S.data=(int *)realloc(S.data,(sizeof(int))*10);
		if(!S.data)  
			exit(0);
			S.top=S.data+S.stacksize;
			S.stacksize+=Incerment;
	}
       *S.top++=e;
	   return 1;
 }         

int Pop(SeqStack &S,int &e)
{      
    if(S.top==S.data)
		return 0;
	e=*--S.top;
	return 1;
}

void XSD_Any(double n,int T)   //�˻�ȡ���� 
    {      
        int i=0;   
        double   a;     
        while(n!=0.0)      
        {         
            a=T*n;         
            n=a-(int)a;            
			if(a>=10)   
			{         
                printf("%c",((int)a-10+'A'));         
                i++;      
            }      
            else
            {            
                printf("%d",(int)(a));        
                 i++;   
            }            
            if(i==10)  //��ౣ��8λС��
                break;   
        }               
}
   void R_R()
   {
        int   i=0,j,T1,T2,k=0,l,N,e,b;      
        double   sum=0,M;               
        char   a[100];   
        getchar();   
        printf("������Ҫ����ת�����������Իس�������"); 
        scanf("%s",a);
		for(i=0;i<100;i++)
		{
		  if(a[i]=='\0')
             l=i;
		}
			for(i=0;i<l;i++)
		{
		if(a[i]=='.')
			 k=i;
		}
		printf("�����������Ľ��ƣ����Իس�������");                     
        scanf("%d",&T1); 
        if(k==0)
		{	
			k=l;
            for(j=0;j<k;j++)         
			{   
            if(a[j]>='A')   
                sum+=((a[j]-'A'+10)*pow(T1,k-j-1));         
            else            
                sum+=(a[j]-48)*pow(T1,k-j-1);      
			} 
		}
		else
		{
			for(j=0;j<k;j++)         
			{    
            if(a[j]>='A')   
                sum+=((a[j]-'A'+10)*pow(T1,k-j-1));         
            else            
                sum+=(a[j]-48)*pow(T1,k-j-1);      
			} 
            for(j=k+1;j<l;j++)         
			{   
            if(a[j]>='A')                     
                sum+=((a[j]-'A'+10)*pow(T1,k-j));         
            else            
                sum+=(a[j]-48)*pow(T1,k-j);   
			}  
		}
        SeqStack    S;     
        InitStack(S);      
		printf("����Ҫת��Ϊ������:���Իس�������");      
        scanf("%d",&T2);  
		if(T2<=1&&T2>37)
		{
			printf("��������\n");
			exit(1);
		}
        N=(int)sum;      
        M=sum-N;     //MΪС������ 
        while(N)     //����ȡ�෨ 
            {         
                if(T2>10)         
                {            
                    b=N%T2;            
                    if(b>=10)            
                    {               
                        b=b-10+'A';                        
                        Push(S,b);   //����������ջ
                    }   
                    else   
                        Push(S,b);   
                }   
                else    
				{
					Push(S,N%T2);                  
				}
			  N=N/T2;
            }   
            printf("ת��Ϊ%d���ƺ���Ϊ:",T2);   
            if(IsEmptyStack(S))
                printf("0\n");    //�ж��Ƿ�Ϊ��ջ  
            while(!IsEmptyStack(S))      
            {         
                Pop(S,e);   
                if(e>=10)   
                    printf("%c",e);         
                else   
                    printf("%d",e);      
            }   
            printf(".");      
            XSD_Any(M,T2); //�˻�ȡ����        
   }       
    void main()   
    {       
			printf("\n���������ʵ��R-R�Ľ���ת����");
			R_R();
			printf("\n\n\n");
            main();
	}
    
