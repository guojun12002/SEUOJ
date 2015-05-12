#include<stdio.h>
typedef struct node *btnode;
struct node
{
    int num;
    int location;
    btnode left,right;
};
typedef struct node *btlink;

btnode newbt(int num, int location);
int search_location(btlink root, int num);
void createbt(btnode pbt, int num, int location);

int main()
{
    freopen("input.txt","r",stdin);
    unsigned long n;
    unsigned int m;
    int num;
    while(scanf("%d %d",&n,&m)!=EOF)
    {
    scanf("%d",&num);
    btlink root= newbt(num,1);
    for(int i=1; i<n; i++)
    {
        scanf("%d",&num);
        createbt(root,num,i+1);
    }
    for(int i=0; i<m; i++)
    {
        scanf("%d",&num);
        printf("%d\n",search_location(root,num));
    }
    }
}

void createbt(btnode pbt, int num, int location)
{
    if(num == pbt->num) return;
    else if(num< pbt->num)
    {
        if(pbt->left== NULL)
            pbt->left= newbt(num, location);
        else
            createbt(pbt->left, num, location);
    }
    else
    {
        if(pbt->right== NULL)
            pbt->right= newbt(num, location);
        else
            createbt(pbt->right, num, location);
    }
}

int search_location(btlink root, int num)
{
    if(num== root->num) return root->location;
    else if(num< root->num) return search_location(root->left, num);
    else return search_location(root->right, num);
}

btnode newbt(int num, int location)
{
    btnode p= new struct node;
    p->num= num;
    p->location= location;
    p->left= NULL;
    p->right= NULL;
    return p;
}
