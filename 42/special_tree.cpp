#include<stdio.h>
#include<stdlib.h>
typedef struct E *PE;
struct E
{
    int from,to;
    int weight;
};

int compare(const void *e1, const void *e2)
{
    PE p1=(PE)e1;
    PE p2=(PE)e2;
    return p1->weight-p2->weight;
}
int judge(int *parent, int n)
{
    while(parent[n]>-1)
    {
        n=parent[n];
    }
    return n;
}
int main()
{
    freopen("input.txt","r",stdin);
    int n,m;
    while(scanf("%d %d",&n,&m)!=EOF)
    {
        PE edges= new E[m];
        int *parent= new int[n+1];
        int cost=0;
        int maxe=-1;
        int p,q;
        for(int i=0; i<m; i++)
        {
            scanf("%d %d %d",&edges[i].from,&edges[i].to,&edges[i].weight);
        }
        for(int i=0; i<n; i++)
        {
            parent[i]=-1;
        }
        qsort(edges,m,sizeof(E),compare);
        for(int i=0; i<m; i++)
        {
            p=judge(parent,edges[i].from);
            q=judge(parent,edges[i].to);
            if(p!=q)
            {
                parent[q]=p;
                if(maxe<edges[i].weight) maxe=edges[i].weight;
                cost+=edges[i].weight;
            }
        }
        printf("%d %d\n",cost,maxe);
        delete []parent;
        delete []edges;
    }
}
