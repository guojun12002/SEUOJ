#include<stdio.h>

int main()
{
    freopen("input.txt", "r", stdin);
    int y, k, n, num, temp;
    while(scanf("%d%d%d", &y, &k, &n)!=EOF)
    {
        num= n/k;
        int i;
        for(i=0; i<num-1; i++)
        {
            temp= (i+1)*k-y;
            if(temp>0) printf("%d ", temp);
        }
        temp= (i+1)*k-y;
        if(temp<1 || num <1) printf("-1\n");
        else printf("%d\n", temp);
    }
}
