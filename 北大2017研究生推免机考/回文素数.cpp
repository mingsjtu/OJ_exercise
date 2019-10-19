#include<iostream>
#include<cstdio>
#include<math.h>

using namespace std;
int dp1[100000],dp2[100000];

bool isprime()
{

}

int main()
{
int N,tmp;
cin>>N;
int m=N/2,cnt=9,cnt1;
int i;
if(N%2==0)
{
cout<<0<<endl;
return 0;
}
for(i=1;i<=9;i++)
    {
    dp1[i]=i;
    dp2[i]=i;
    }
int j=2;
while(j<m)
{
    cnt1=cnt;
    while(cnt1>0){
    for(i=0;i<=9;i++)
    {
        dp1[cnt1]=dp1[cnt1]*10+i;
        dp2[cnt1]=dp2[cnt]+i*pow(10,j);
        cout<<dp1[cnt1]<<' '<<dp2[cnt1]<<endl;
    }
    cnt1--;
    }
    j++;
}

}
