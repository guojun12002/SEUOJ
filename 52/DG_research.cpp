#include<stdio.h>

int find_from(int *from, int n);

int main()
{
    freopen("input.txt", "r", stdin);
    int m, n;
    int i, j;
    int p, q;
    while(scanf("%d%d", &n, &m))
    {
        if(m==0 && n==0) break;
        int from[50001]={};
        int sum= 0;
        for(int k=0; k<m; k++)
        {
            scanf("%d%d", &i, &j);
            p= find_from(from, i);
            q= find_from(from, j);
            if(p<q)
            {
                sum++;
                from[q]= p;
            }
            else if(p>q)
            {
                sum++;
                from[p]= q;
            }
        }
        printf("%d\n", n-sum);
    }
}

int find_from(int *from, int n)
{
    while(from[n]>0)
    {
        n= from[n];
    }
    return n;
}
