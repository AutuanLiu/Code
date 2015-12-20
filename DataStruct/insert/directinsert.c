#include "stdio.h"
#include "stdlib.h"
typedef int KeyType;
//typedef int DataType;
typedef struct
{
    KeyType key;
   // DataType info;
}RecordNode;
typedef struct
{
    int n;
    RecordNode *record;
}SortObject;

SortObject *create(int cap,int data[])
{
    SortObject *dic;
    dic->n=cap;
    dic->record=data;
    return  dic;
}

RecordNode *insertsort(SortObject *pvector)
{
    int i,j;
    RecordNode temp;
    RecordNode *data=pvector->record;
    for(i=1;i<pvector->n;++i)
    {
        temp=data[i];
        for(j=i-1;temp.key<data[j].key&&j>=0;j--)
        {
            data[j+1]=data[j];
        }
        if(j!=i-1)
            data[j+1]=temp;
    }
    return data;
}

void main()
{
    int i,info[8]={49,38,65,97,76,13,27,49};
    SortObject *s;
    RecordNode *data;
    s=create(8,info);
    data=insertsort(s);
    for(i=0;i<s->n;i++)
        printf("%4d",data[i].key);
}
