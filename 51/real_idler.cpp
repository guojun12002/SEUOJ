#include<stdio.h>

int weights[6]={1, 2, 3, 5, 10, 20};
int a[6];

int main()
{
    freopen("input.txt", "r", stdin);
    int T, n, sum;
    scanf("%d", &T);
    while((T--)>0)
    {
        for(int i=0; i<6; i++) scanf("%d", &a[i]);
        bool weight[6][1001]={};
        n= 0; sum= 0;
        for(int i=0; i<6; i++)
        {
            sum+= weights[i]*a[i];
            for(int j=1; j<=a[i]; j++)
                weight[i][j*weights[i]]= true;
        }
        if(a[0]>2)
            if(a[0]%2==1)
                { a[1]+= a[0]/2; a[0]= 1;}
            else
                { a[1]+= a[0]/2-1; a[0]= 2;}
        for(int i=4; i>-1; i--)
            for(int j=0; j<=sum; j++)
                if(weight[i+1][j])
                {
                    for(int k=0; k<=a[i]; k++)
                        weight[i][j+k*weights[i]]= true;
                }
        for(int i=1; i<1001; i++)
            if(weight[0][i]) n++;
        printf("%d\n", n);
    }
}
