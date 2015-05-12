#include<stdio.h>
#include<stdlib.h>
typedef struct Loc *PLoc;
struct Loc
{
    int num;
    int location;
};
int compare(const void *elem1, const void *elem2);
int search_location(PLoc loc, int n, int num);

int main()
{
    freopen("input.txt","r",stdin);
    unsigned long n;
    unsigned int m;
    int num;
    while(scanf("%d %d",&n,&m)!=EOF)
    {
        PLoc loc= new Loc[n];
        for(int i=0; i<n; i++)
        {
            scanf("%d", &loc[i].num);
            loc[i].location= i+1;
        }
        qsort(loc,n,sizeof(Loc),compare);

        for(int i=0; i<m; i++)
        {
            scanf("%d", &num);
            printf("%d\n", search_location(loc,n,num));
        }
    }
}

int compare(const void *elem1, const void *elem2)
{
    PLoc p1= (PLoc)elem1;
    PLoc p2= (PLoc)elem2;
    if(p1->num!=p2->num) return p1->num-p2->num;
    else return p1->location-p2->location;
}

int search_location(PLoc loc, int n, int num)
{
    int l=0, h=n, mid, m;
    while(l<h)
    {
        mid= (l+h)/2;
        if(loc[mid].num==num)
        {
            m= mid;
            break;
        }
        if(loc[mid].num<num) l=mid;
        else h=mid;
    }
    while(m>0 && loc[m-1].num==loc[m].num)
    {
        m--;
    }
    return loc[m].location;
}
