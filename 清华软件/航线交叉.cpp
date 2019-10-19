#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>

using namespace std;
int dp[101];
struct xian
{
    int sta,en;
    bool operator<(const xian x)
    {
        if(sta<x.sta)
            return true;
        else return false;
    }
}x[101];
int n;//chengshishu
int maxv(int a,int b)
{
    int res;
    if(a>b)res=a;
    else res=b;
    return res;
}
int solve()
{
    int i,j;
    dp[0]=1;
    for(i=1;i<n;i++)
    {
        for(j=0;j<i;j++)
        {
            if(x[i].en>x[j].en)
                {dp[i]=maxv(dp[i],dp[j]+1);
                printf("for i %d dp =%d\n",i,dp[i]);
                }
            else dp[i]=maxv(dp[i],dp[j]);
        }
    }
    return dp[n-1];
}
int main()
{
    int i,j,k,res;
    while(cin>>n)
    {
        memset(dp,0,sizeof(dp));
        for(i=0;i<n;i++)
            scanf("%d%d",&x[i].sta,&x[i].en);
        sort(x,x+n);
        res=solve();
        cout<<n-res<<endl;
    }
}
