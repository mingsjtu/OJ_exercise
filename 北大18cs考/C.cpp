#include<iostream>
#include<cstring>
#include<stdio.h>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
char map[60][60];
int re[10];
int x_[4]={1,0,-1,0};
int y_[4]={0,1,0,-1};

void dftt(int m, int n ,int w, int h )
{
	if(!((m>=0&&m<h)&&(n>0&&n<w)))
	return ;
	int i=0,j=0,k=0;
	for(i=0;i<4;i++)
	{
		int xx=m+x_[i],yy=n+y_[i];
		if((xx>=0&&xx<h)&&(yy>=0&&yy<w)&&map[m+x_[i]][n+y_[i]]=='X')
		{
		map[m+x_[i]][n+y_[i]]='*';
		dftt(m+x_[i],n+y_[i],w,h); 
		}
	}
}
void dft(int m, int n ,int w, int h,int num)//hang,lie,zonghang,zonglie
{
	//cout<<m<<'m'<<n<<'n'<<endl;
	if(!((m>=0&&m<h)&&(n>=0&&n<w)))
	return ;
	int i=0,j=0,k=0;
	for(i=0;i<4;i++)
	{
		int xx=m+x_[i],yy=n+y_[i];
		if(xx>=h||yy>=w||xx<0||yy<0||mmap[xx][yy]=='.')
           continue;
		if(map[m+x_[i]][n+y_[i]]=='*')
		{
		map[m+x_[i]][n+y_[i]]='.';
		dft(m+x_[i],n+y_[i],w,h,num); 
		}
		else if(map[m+x_[i]][n+y_[i]]=='X')
		{
			map[m+x_[i]][n+y_[i]]='*';
			dftt(m+x_[i],n+y_[i],w,h);
			re[num]++;
		}
	}
}
int main()
{
	int w,h,k=0;
	scanf("%d%d",&w,&h);
	while(1)
	{
		scanf("%d%d",&w,&h);
		if(!(w||h))return 0;
		int i=0,j=0,renum=0;
		memset(re,0,sizeof(re));
		memset(map,0,sizeof(map));
	for(i=0;i<h;i++)
	{
		for(j=0;j<w;j++)
		cin>>map[i][j];
	}
	for(i=0;i<h;i++)
	{
		for(j=0;j<w;j++)
		{
			if(map[i][j]=='*')
			{
			map[i][j]='.';
			dft(i,j,w,h,renum);
			renum++;
			//cout<<"renum"<<renum<<endl;
			}
		}
	}
	cout<<"Throw "<<k+1<<endl;
	//cout<<renum<<"renum"<<endl;
	sort(re,re+renum+1);
	for(int i=1;i<=renum;i++)
	cout<<re[i]<<' ';
	printf("\n\n");
	k++;
	}
	return 0;
 } 
