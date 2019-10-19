#include<iostream>
using namespace std;
void solve(char word[])
{
	int i=0,j=0,k=0,tmp=0,flag=0,maxleng=0;
	char huiwen[110];
	for(i=0;word[i]!='\0';i++)
	{
		j=0;
		tmp=0;
		while(i-j>=0&&word[i+j]!='\0'&&word[i-j]==word[i+j])
		{
			tmp=tmp+2;
			j++;
		}
		//cout<<"max"<<tmp<<endl;
		if(tmp>maxleng)
		{
			maxleng=tmp;
			flag=i;
		}
	}
	//cout<<maxleng<<endl;
	maxleng--;
			for(k=0;k<maxleng;k++)
			{
				//cout<<flag<<maxleng;
				cout<<word[flag-maxleng/2+k];
			}
			//return huiwen;
}
int main()
{
	char word[110];
	int n=0,i=0,j=0;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>word;
		//cout<<endl;
		solve(word);
		cout<<endl;
	}
	return 0;
	
 } 
