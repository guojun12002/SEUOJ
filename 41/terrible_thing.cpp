#include <stdio.h>

int main()
{
    freopen("input.txt", "r", stdin);
    int y, k, n;
    int temp;
    while(scanf("%d%d%d", &y, &k, &n)!=EOF)
    {
        temp= k-y%k;
        if(temp>n-y)
        {
            printf("-1\n");
            continue;
        }
        while(temp<=n-y-k)
        {
            printf("%d ", temp);
            temp+= k;
        }
        printf("%d\n", temp);
    }
}
