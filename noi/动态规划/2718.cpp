//http://noi.openjudge.cn/ch0206/2718/
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int dp[21][21];
int m,n;
int main()
{

    cin>>m>>n;
    int i,j,k;
    dp[0][0]=1;
    for(i=0;i<m;i++)
        dp[i][0]=1;
    for(i=0;i<n;i++)
        dp[0][i]=1;
    for(i=1;i<m;i++)
    {
        for(j=1;j<n;j++)
    {
        for(k=0;k<=j;k++){
        dp[i][j]+=dp[i-1][k];
        }
    }
    }
    cout<<dp[m-1][n-1]<<endl;
}
