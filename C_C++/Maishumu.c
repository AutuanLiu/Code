#include <stdio.h>
#include <time.h>
int main()
{
    float start,end;
    start=clock();
    int x,y;
    for(x=0;x<200;x++)
        for(y=0;y<200;y++)
        if(3*x-5*y==7)
        printf("%4d%4d\n",x,y);
    end=clock();
    printf("%f\n",(end-start)/1000);
}
