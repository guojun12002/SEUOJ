#include <cstdio>
#include <iostream>
#include <math.h>
using namespace std;
int main()
{
	freopen("input.txt","r",stdin);
	int n;
	while(cin>>n)
	{
		bool* sushu=new bool[n+1];
		int step1=4,step2=4,step3=4;
		for(int i=5;i<=n;i+=step1^=6)
			sushu[i]=true;
		for(int i=5;i<=sqrt(n);i+=step2^=6)
			for(int j=i*i;j<=n;j+=i*2)
				sushu[j]=false;
		int sum=0;
		for(int i=5;i<=n;i+=step3^=6)
			if(sushu[i]) sum++;
		if(n<2) sum-=2;
		else if(n<3) sum--;
		cout<<sum+2<<endl;
		delete []sushu;
	}
	return 0;
}