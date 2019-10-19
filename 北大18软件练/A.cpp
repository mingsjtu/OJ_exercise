#include<iostream>
#include<math.h>
using namespace std;
int main()
{
	int a,b,cnt=0;
	bool flag;
	cin>>a>>b;
	int tmp;
	if(a>b)
	{
		tmp=a;
		a=b;
		b=tmp;
	}
	
	for(int i=a>2?a:2;i<=b;i++)
	{
		flag=1;
		//if(i==1)
		//break;
		for(int j=2;j<=sqrt(i);j++)
		{
			if(i%j==0)
			{
			flag=0;
			break;
			}
		}
		if(flag)
		cnt++;
	}
	cout<<cnt;
 } 
