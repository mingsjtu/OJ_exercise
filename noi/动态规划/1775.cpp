#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int T,M;
int w[105];//weight
int p[105];//price
int dp[1000];
int max(int a,int b)
{
    return a>b?a:b;
}
int main()
{
    cin>>T>>M;
    int i,j,k;
    for(i=0;i<M;i++)
    {
        cin>>w[i]>>p[i];
    }
    memset(dp,0,sizeof(dp));
    for(i=0;i<M;i++)
    {
        for(j=T;j>=w[i];j--)
            {
                dp[j]=max(dp[j-w[i]]+p[i],dp[j]);
            }
        //cout<<dp[T]<<endl;
    }
    cout<<dp[T]<<endl;
}
