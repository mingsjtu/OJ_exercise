#include<stdio.h>
#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
#include<string.h>
#include<math.h>
using namespace std;
char ch[200009];
int main()
{
	int i=0,num,re;
	cin>>num;
	re=num;
	for(i=0;i<num;i++)
	cin>>ch[i];
	int l=0,r=1,j=0;
	//cout<<re;
	while(r<=num-1)
	{
		if(ch[l]==ch[r])
		{
			l=r;
			r++;
		}
		else{
		re=re-2;
		ch[l]='#';
		ch[r]='#';
		if(l==0){
		l=r+1;
		r=r+2;}
		else
		{
			j=l;
			while(ch[j]=='#'&&j!=0)
			{
				j--;
			}
			if(j==0)
			{
				l=r+1;
				r=r+2;
			}
			else{
				l=j;
				r++;
			}
			}	
		}
		//cout<<'l'<<l<<'r'<<r<<endl;
	}
	cout<<re;
}
