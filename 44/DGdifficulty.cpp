#include<stdio.h>

int main()
{
    freopen("input.txt","r",stdin);
    int n, m;
    int query;
    int rank_query;
    while(scanf("%d%d", &n, &m)!=EOF)
    {
        int a[100000];       //��¼i����ÿ���˷���
        int sum[101]={};     //��¼100���ڲ�ͬ�ֵ���������ʼ��Ϊ0
        for(int i=0; i<n; i++)
        {
            scanf("%d",&a[i]);
            sum[a[i]]++;
        }
        for(int i=0; i<m; i++)
        {
            scanf("%d", &query);
            rank_query= 1;
            for(int j=a[query-1]+1; j<101; j++) rank_query+= sum[j];
            printf("%d\n", rank_query);
        }
        printf("\n");
    }
}
