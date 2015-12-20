#include "stdio.h"
#include "stdlib.h"
#include "math.h" 
#define MaxSize 100;  
#define Incerment 10;
typedef   struct
{      
    int   *data,*top;   //数据//栈顶的位置
    int   stacksize;   //栈中的最大元素个数
}SeqStack;     
int InitStack(SeqStack &S)  //初始化栈
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

void XSD_Any(double n,int T)   //乘基取整法 
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
            if(i==10)  //最多保留8位小数
                break;   
        }               
}
   void R_R()
   {
        int   i=0,j,T1,T2,k=0,l,N,e,b;      
        double   sum=0,M;               
        char   a[100];   
        getchar();   
        printf("输入需要进行转换的数：（以回车结束）"); 
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
		printf("输入以上数的进制：（以回车结束）");                     
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
		printf("输入要转换为？进制:（以回车结束）");      
        scanf("%d",&T2);  
		if(T2<=1&&T2>37)
		{
			printf("输入有误！\n");
			exit(1);
		}
        N=(int)sum;      
        M=sum-N;     //M为小数部分 
        while(N)     //除基取余法 
            {         
                if(T2>10)         
                {            
                    b=N%T2;            
                    if(b>=10)            
                    {               
                        b=b-10+'A';                        
                        Push(S,b);   //所得余数进栈
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
            printf("转换为%d进制后结果为:",T2);   
            if(IsEmptyStack(S))
                printf("0\n");    //判断是否为空栈  
            while(!IsEmptyStack(S))      
            {         
                Pop(S,e);   
                if(e>=10)   
                    printf("%c",e);         
                else   
                    printf("%d",e);      
            }   
            printf(".");      
            XSD_Any(M,T2); //乘基取整法        
   }       
    void main()   
    {       
			printf("\n本程序可以实现R-R的进制转换：");
			R_R();
			printf("\n\n\n");
            main();
	}
    
