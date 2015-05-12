#include<stdio.h>
#include<stdlib.h>
int compare(const void* e1, const void* e2)
{
    return *(int*)e1-*(int*)e2;
}
int main()
{
    freopen("input.txt","r",stdin);
    long n;
    while(scanf("%d",&n))
    {
        if(n==0) break;
        int *t= new int[n];
        for(int i=0; i<n; i++) scanf("%d",&t[i]);
        qsort(t,n,sizeof(int),compare);
        double sum=0;
        for(int i=0; i<n; i++)
        {
            sum+=t[i]*(n-i);
        }
        printf("%.3f\n", sum/n);
        delete []t;
    }
}
