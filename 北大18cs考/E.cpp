#include<iostream>
#include<stdio.h>
#include<cstring>
#include<algorithm>
#include <iomanip>
typedef long long ll;
using namespace std;
ll sum=0;
void mymerge(int *s,int *temp,int left , int right,int mid)
{
	int i=left,j=mid+1,point=left,k=left;
	printf("deal left%d right%d \n",left,right);
	while(i<=mid&&j<=right){
	if(s[i]>s[j])
	{
		printf("i%d j%d",i,j);
		temp[k]=s[j];
		while(s[point]<=2*s[j]&&point<=mid)
		{
		//printf("point%d j%d \n",point,j);
		point++;
		}
		if(point<=mid)
		{
		sum+=mid-point+1;
		printf("plus %d\n",mid-point+1);
	}
		j++;
	}
	else
	{
		temp[k]=s[i];
		i++;
		printf("i %d++\n",i);
	}
	k++;
}
	while(i<=mid){
	temp[k++]=s[i++];
	}
	while(j<=right)
	{
	temp[k++]=s[j++];	
	}
	for(i=left;i<=right;i++)
	s[i]=temp[i];

}
void mergesort(int *a,int *temp,int left, int right)
{
	//printf("deal %d  %d",left ,right);
	int mid=(left+right)/2;
	if(left<right){
	mergesort(a,temp,left,mid);
	mergesort(a,temp,mid+1,right);
	mymerge(a,temp,left,right,mid);
	 
}
}
int main()
{
	int num,i=0,j=0,count=0;
	int ans[20010];
	int temp[40020];
	cin>>num;
	
	for(i=0;i<num;i++)
	{
		cin>>ans[i];
	}
	mergesort(ans,temp,0,num-1);
	for(int i=0;i<num;i++)
	cout<<ans[i]<<'s'<<endl;
	cout<<sum<<endl;
	return 0;
	
 } 
