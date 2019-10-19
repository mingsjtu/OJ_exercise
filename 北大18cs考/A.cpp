#include<iostream>
using namespace std;
int a[12]={31,28,31,30,31,30,31,31,30,31,30,31};
bool isrun(int nian)
{
	if((nian%4==0&&nian%100!=0)||(nian%400==0))
	return true;
	else return false;
}
int sheng(int nian,int yue,int ri)
{
	int result=0;
	
	for(int i=1;i<yue;i++)
	result+=a[yue];
	result+=ri;
	if(isrun(nian)&&yue-1>=2)
	result+=1;
	return result;
	
}
int solve(int nian1,int yue1,int ri1,int nian2,int yue2,int ri2)
{
	int result=0;
	if(nian1==nian2)
	{
	if(yue1==yue2)
	return ri2-ri1;
	else{
		if(isrun(nian1))
		a[1]=29; 
	for(int i= yue1+1;i<yue2;i++)
	result+=a[i-1];
	
	result+=a[yue1]-ri1+ri2;
	return result;
		}
	}
	else
	{
		if(nian1+1<nian2){
		for(int i=nian1+1;i<nian2;i++)
		{
			//cout<<"nain buyiyang"<<endl;
			if(isrun(i))
			result+=366;
			else result+=365;
		 }}
		 //cout<<"nianbucha1"<<endl;
		int tmp1=(isrun(nian1)==0)?(365-sheng(nian1,yue1,ri1)):(366-sheng(nian1,yue1,ri1));
		int tmp2=sheng(nian2,yue2,ri2);
		result=result+tmp1+tmp2;
		return result; 
	}
 }
 int main()
 {
 int nian1,nian2,yue1,yue2,ri1,ri2;
 cin>>nian1>>yue1>>ri1;
 cin>>nian2>>yue2>>ri2;
 //cout<<isrun(nian1)<<"runnian"<<endl;
 //cout<<sheng(nian1,yue1,ri1);
 cout<<solve(nian1,yue1,ri1,nian2,yue2,ri2)<<endl;
 return 0;
  } 
