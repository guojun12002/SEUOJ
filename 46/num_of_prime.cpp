#include<stdio.h>
#include<math.h>

int count(int l, int r);
int prime(int n);

int main()
{
    freopen("input.txt","r",stdin);
    int l, r;
    while(scanf("%d %d",&l,&r)!=EOF)
    {
        printf("%d\n",count(l,r));
    }
}

int count(int l, int r)
{
    int sum=0;
    for(int i=l; i<r; i++)
    {
        sum+= prime(i);
    }
    return sum;
}

int prime(int n)
{
    if(n<2) return 0;
    if(n==2) return 1;
    if(n%2==0) return 0;
    for(int i=3; i<=sqrt(n); i+=2)
    {
        if(n%i==0) return 0;
    }
    return 1;
}

