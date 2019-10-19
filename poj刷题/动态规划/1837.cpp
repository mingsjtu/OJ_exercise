#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int c,g;
int dis[22];
int w[22];
int dp[22][15001];
int main()
{
cin>>c>>g;
int i,j,k;
memset(dp,0,sizeof(dp));
dp[0][7500]=1;
for(i=0;i<c;i++)
    cin>>dis[i];
for(i=0;i<g;i++)
    {
    cin>>w[i];
    }
for(i=1;i<=g;i++)
    {
        for(j=0;j<=15000;j++)
        {
            if(dp[i-1][j])continue;
            for(k=0;k<c;k++)
                dp[i][j]+=dp[i-1][j-w[i-1]*dis[k]];
        //printf("i%d j%d dp %d\n",i,j,dp[i][j]);
        }

    }
    cout<<dp[g][7500];
}
