#include<iostream>
#include<stdio.h>
#include<cstring>
#include<algorithm>
#include <iomanip> 

using namespace std;


int qianshu=0;
int mianzhi[6];
int flag[101];
int dangqian[100][500];

int yilun(int qian_s)
{
	int zhaodao=0;
	int dangqian1[500],i=0,j=0,k=0,tmp;
	memset(dangqian1,0,500*sizeof(int));
	if(qian_s==1)
	{
		for(i=0;i<6;i++)
		{
		dangqian[1][i]=mianzhi[i];
		flag[dangqian[1][i]]=1;
		zhaodao++;
		}
	 }
	 else {
	 	j=0;
	 	//cout<<"when"<<qian_s<<endl; 
	 	while(dangqian[qian_s-1][j])
	 	{	 		
	 		dangqian1[j]=dangqian[qian_s-1][j];
			//cout<<dangqian[qianshu-1][j]<<'i'<<dangqian1[j]<<"  ";
	 		j++;
	 		
		}
		
		j=0;
		k=0; 
	 	while(dangqian1[j]){
	 	for(i=0;i<6;i++)
	 	{
	 		tmp=dangqian1[j]+mianzhi[i];
	 		if(tmp>0&&flag[tmp]==0)
	 		{
			dangqian[qian_s][k]=tmp;
			k++;
			if(tmp>0&&tmp<=100){
			flag[tmp]=qian_s;
			//cout<<tmp<<"is"<<qian_s<<"zhaodao"<<zhaodao<<endl; 
			zhaodao++;}
			}
			tmp=dangqian1[j]-mianzhi[i];
	 		if(tmp>0&&flag[tmp]==0)
	 		{
			dangqian[qian_s][k]=tmp;
			k++; 
			if(tmp>0&&tmp<=100){
			flag[tmp]=qian_s;
			//cout<<tmp<<"is"<<qian_s<<"zhaodao"<<zhaodao<<endl; 
			zhaodao++;}
			}
		}
		j++;
	}
	}
	//cout<<zhaodao<<"zhaodao"<<endl;
	return zhaodao;	 
} 

int sum(int a[101])
{
	int s=0;
	for(int i=0;i<101;i++)
	s+=a[i];
	return s; 
}


int main()
{
	int cishu=0;
	cin>>cishu;
	while(cishu)
	{
	int zongshu=0,tmp=0;
	for(int i=0;i<6;i++)
	cin>>mianzhi[i];
	memset(dangqian,0,sizeof(dangqian));
	memset(flag,0,sizeof(flag));
	for(qianshu=1;zongshu<100;qianshu++)
	{
		tmp=yilun(qianshu);
		zongshu+=tmp;
		//cout<<"when"<<qianshu<<"zongshu"<<zongshu<<"tmp"<<tmp<<endl;
	}
	//cout<<fixed<<setprecision(2)<<double(sum(flag))/double(100)<<' '<<qianshu-1<<endl;
	printf("%.2f %d\n" ,double(sum(flag))/double(100),qianshu-1);
	cishu--;
	}
	
	return 0;
 } 
