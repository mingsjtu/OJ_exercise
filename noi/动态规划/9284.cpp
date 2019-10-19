#include<iostream>
using namespace std;
const int maxn=50;

typedef long long ll; 
ll dp[maxn][maxn];
//ll dp(ll x,ll y)
//{
//	ll re1=1,re2=1;
//	if(x>y/2) x=y-x;
//	for(int i=1;i<=x;i++)
//	re1*=y-x+i;
//	for(int j=1;j<=x;j++)
//	re1/=j;
//	return re1;
//}
int main()
{
	ll i,j,N,A,B,re;
	cin>>N>>A>>B;
	ll en=(A>B)?A:B;
	for(i=0;i<=N;i++)
	{
	dp[i][i]=1;
	dp[0][i]=1;
}
for(j=1;j<=N+en;j++)
	{
		for(i=1;i<=en;i++)
		dp[i][j]=dp[i-1][j-1]+dp[i][j-1];
	}
	re=dp[A][N+A]*dp[B][N+B];
	cout<<re; 
 } 
