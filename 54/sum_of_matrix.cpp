#include<stdio.h>

int main()
{
    freopen("input.txt","r",stdin);
    int num,sum;
    sum= 0;
    for(int i=0; i<12; i++)
    {
        scanf("%d",&num);
        sum+= num;
        if(i%4==3)
        {
            printf("%d ",sum);
            sum= 0;
        }
    }

}
