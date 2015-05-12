#include<stdio.h>
#include <cstring>
bool weight[1001];
int a[6];

int main()
{
    freopen("input.txt", "r", stdin);
    int T, n;
    scanf("%d", &T);
    while((T--)>0)
    {
        for(int i=0; i<6; i++) scanf("%d", &a[i]);
        memset(weight, false, 1001);
        n= 0;
        for(int i=4; i>-1; i--)
            if(i>2 || i<1)
            {
                if(a[i]>2)
                    if(a[i]%2==1)
                        { a[i+1]+= a[i]/2; a[i]= 1;}
                    else
                        { a[i+1]+= a[i]/2-1; a[i]= 2;}
            }
        for(int i=0; i<=a[0]; i++)
            for(int j=0; j<=a[1]; j++)
                for(int k=0; k<=a[2]; k++)
                    for(int l=0; l<=a[3]; l++)
                        for(int m=0; m<=a[4]; m++)
                            for(int n=0; n<=a[5]; n++)
                                weight[i*1+j*2+k*3+l*5+m*10+n*20]=true;

        for(int i=1; i<1001; i++)
            if(weight[i]) n++;
        printf("%d\n", n);
    }
}
