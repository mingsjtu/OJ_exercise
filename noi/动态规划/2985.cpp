#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int dp[1005];
int a[22];
int num;
int all;
int main()
{
    int i,j,k;
    cin>>num>>all;
    for(i=0;i<num;i++)
        cin>>a[i];
    memset(dp,0,sizeof(dp));
    dp[0]=1;
    dp[a[0]]=1;
    for(i=1;i<num;i++)
    {
        for(j=all;j>=a[i];j--)
        {
            dp[j]+=dp[j-a[i]];
        }
    }
    cout<<dp[all]<<endl;
}
