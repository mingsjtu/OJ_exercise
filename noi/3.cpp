#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;
typedef long long ll;
ll wu[55],jin[55],li[55];
struct guai
{
    ll wu,jin;
	ll li;
};
ll mymax(ll a, ll b)
{
	ll tmp;
	tmp=(a>=b)?a:b;
}
guai g[55];
bool cmp(guai g1,guai g2)
{
    if(g1.li>g2.li)
        return true;
        else if(g1.li==g2.li&&g1.wu>g2.wu)
        return true;
        else if(g1.li==g2.li&&g1.jin<g2.jin)
        return true;
        else
		return false;
}
int main()
{
	priority_queue<ll> q1;

int m,i=0;
cin>>m;
for(i=0;i<m;i++)
{

cin>>g[i].wu;
}
int l=0,r=m-1;
for(i=0;i<m;i++)
{
cin>>g[i].jin;
//g[i].li=g[i].wu/g[i].jin;
//cout<<g[i].li;
}
ll max1=0,max2=0;//zhizhen , diyixiao , dierxiao
i=0;
bool flag;//wu>max1 t, else f
ll mywu=0,re=0;
while(i<m)
{
    //cout<<"dangqia"<<i<<endl;
	if(mywu>=g[i].wu)
	{
//cout<<q1.empty()<<endl;
        if(g[i].jin==2)
		{i++;continue;}
		else
		{
			q1.push(g[i].wu);
//			if(g[i].wu>max1)
//			{
//				flag=t;
//				max1=g[i].wu;
//			}
//			if(!flag)
//			{
//				max2=mymax(g[i].wu,max2);
//			}
//			else max2=max1;
		}
	}
	else
	{
		if(q1.empty()||g[i].jin==1)
		{mywu+=g[i].wu;
		re+=g[i].jin;
		}
		else
		{
			max1=q1.top();q1.pop();
			max2=q1.top();
			cout<<"max1"<<max1<<endl;
			mywu+=max1;
			if(g[i].wu>mywu)
			{
			    mywu+=max2;
			    if(g[i].wu>mywu)
			{
			     mywu-=max1;
			     mywu-=max2;
			     q1.push(max1);
			     mywu+=g[i].wu;
                re+=2;
			}
			}
		}
	}

	i++;
}
cout<<re;
}
