#include<stdio.h>
#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
#include<string.h>
#include<math.h>
using namespace std;
const int maxn=15;
int dp[maxn][maxn];
int main()
{
	int N,M,K;
	cin>>N>>M>>K;
	int num,i=0,j=0;
	memset(dp,0,sizeof(dp));
	for(i=0;i<=N;i++)
	dp[i][i]=1;
	num=N-M*K;
//	cout<<num;
//	for(i=1;i<=num;i++)
//	{
//		for(j=1;j<i&&j<=M;j++)
//		{
//			for(int r=0;i-r>=j-1;r++)
//			dp[i][j]+=dp[i-r][j-1];
//			cout<<"at"<<i<<j<<"is"<<dp[i][j]<<endl;
//		}
//		dp[i+1][j]=dp[i][j]*j+dp[i][j-1];
//	}
int re;
if(num<0)
dp[num][m]=0;
if(num=0)
dp[num][m]=1;
else{
for(i=1;i<=num;i++)
dp[num][m]=dp[num-1][m]*m;
}
for(j=1;j<i&&j<=M;j++)
		{
		for(int r=0;i-r>=j-1;r++)
        dp[i][j]+=dp[i-r][j-1];
			cout<<"at"<<i<<j<<"is"<<dp[i][j]<<endl;
		}
			cout<<re<<endl;

}
