#include<stdio.h>
#include<string.h>

int main()
{
    freopen("input.txt","r",stdin);
    char s[1001];
    while(scanf("%s",s)!=EOF)
    {
        int num=0;
        int mapc[26]={};
        int length= strlen(s);
        for(int i=0; i<length; i++) mapc[s[i]-'a']++;
        for(int i=0; i<26; i++) if(mapc[i]%2==1) num++;
        if(num==0 || num%2==1) printf("First\n");
        else printf("Second\n");
    }
}
