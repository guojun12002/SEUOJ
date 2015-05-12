#include<stdio.h>

int main()
{
    freopen("input.txt", "r", stdin);
    int n, m, k;

    char act[100][2];
    int index[100][2];
    while(scanf("%d%d%d", &n, &m, &k))
    {
        int ch[101]={};
        if(n==0 && m==0 && k==0) break;
        for(int i=0; i<k; i++)
        {
            scanf("%s", act[i]);
            switch(act[i][0])
            {
                case 'a':
                case 'b': scanf("%d", &index[i][0]); break;
                default: scanf("%d%d", &index[i][0], &index[i][1]); break;
            }
        }
        for(int i=0; i<m; i++)
            for(int j=0; j<k; j++)
                switch(act[j][0])
                {
                    case 'a': ch[index[j][0]]++; break;
                    case 'b': ch[index[j][0]]= 0; break;
                    default: ch[index[j][0]]+= ch[index[j][1]]; ch[index[j][1]]= ch[index[j][0]]-ch[index[j][1]]; ch[index[j][0]]-=ch[index[j][1]]; break;
                }

        for(int i=1; i<n; i++)
            printf("%d ", ch[i]);
        printf("%d\n", ch[n]);
    }
}
