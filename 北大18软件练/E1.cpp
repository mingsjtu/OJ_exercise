#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int casen;
int n;//jianzhuwu gaodu
int high[10005];
int dp[10005];
int solve()
{
    int i,j;
    memset(dp,0,sizeof(dp));
    for(i=0;i<n;i++)
    {
        for(j=0;j<i;j++)
        {
            if(high[i]<=high[j])
                dp[i]=dp[j]+1;
        }
    }
    return dp[n-1]+1;
}
int solve1()
{
    int i,j;
    memset(dp,0,sizeof(dp));
    for(i=n-1;i>=0;i--)
    {
        for(j=n-1;j>i;j--)
        {
            if(high[i]<=high[j])
                dp[i]=dp[j]+1;
        }
    }
    return dp[0]+1;
}
int main()
{
    cin>>casen;
    int i,j,k;
    for(i=0;i<casen;i++)
    {
        cin>>n;
        memset(high,0,sizeof(high));
        for(j=0;j<n;j++)
        {
            cin>>high[j];
        }
        int res=solve();
        int res1=solve1();
        res=res>res1?res:res1;
        cout<<res<<endl;
    }
}
