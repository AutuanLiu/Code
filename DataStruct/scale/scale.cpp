#include "stdio.h"
#include "stdlib.h"
#define  MAX  100
struct SeqStack{
    int MAXNUM;
    int t;
    int *data;
};
typedef struct SeqStack *stack;

stack create(int m){
    stack s=(stack)malloc(sizeof(struct SeqStack));
    if(s){
        s->data=(int*)malloc(sizeof(int)*m);
        if(s->data){
            s->t=-1;
            s->MAXNUM=m;
            return s;
        }
        else 
            free(s);}
    else{
        printf("out of space!\n");
        return NULL;
    }
}
int isEmpty(stack s){
    if (s->t==-1)
        return 1;
    else
        return 0;
} 

void push(stack s,int x){
    if(s->t >= MAX-1)
        printf("OverFlow!\n");
    else
    {
        s->t=s->t+1;
        s->data[s->t]=x;
    }
}

void pop(stack s){
    if(s->t==-1)
        printf("UnderFlow!\n");
    else
        s->t=s->t-1;
}

int top(stack s){
    if(s->t==-1)
        printf("The stack is empty!\n");
    else
        return(s->data[s->t]);
}

void print(stack s){
    while(s->t!=-1)
        printf("%d",top(s));
}

int choice(){
    printf("please enter your choice:");
    int choices;
    scanf("%d",&choices);
    if(choices<=3&&choices>=1)
        return choices;
    else
        printf("Error!please enter again!\n");
}

void main(){
    int num;
    printf("please enter the number you wantan convert:");
    scanf("%d",&num);
   printf("            menu            \n");
    printf("\n");
    printf("1            10 -- 2         \n");
    printf("2            10 -- 8         \n");
    printf("3            10 -- 16        \n");
    while(true){
        switch(choice()){
            case 1:{ 
                       stack s=create(MAX);
                       while(true){
                           push(s,num%2);
                           num=num/2;
                       }
                       print(s);
                       break;}    
            case 2:{ 
                       stack s=create(MAX);
                       while(true){
                           push(s,num%8);
                           num=num/8;
                       }
                       print(s);
                       break;}        
            case 3:{ 
                       stack s=create(MAX);
                       while(true){
                           push(s,num%16);
                           num=num/16;
                       }
                       print(s);
                       break;}        
        }
    }
}


