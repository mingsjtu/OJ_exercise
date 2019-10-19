#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	char s1[260];
	int cnt=0;
	while(cin.getline(s1,260))
	{
		for(int i=0;s1[i]!='\0';i++)
		{
			if(s1[i]>='0'&&s1[i]<='9')
			cnt++;
		}
		cout<<cnt<<endl;
	}
	
	return 0;
	
}
 
