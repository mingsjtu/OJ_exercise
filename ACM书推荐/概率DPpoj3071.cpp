//http://poj.org/problem?id=3071
#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;
double dp[150][8];
int t;
double gailv[150][150];
int main()
{
	int i, j, k,geshu;
	while (cin >> t)
	{
		if (t == -1)
			return 0;
		geshu = 1 << t;
		for (i = 0; i < geshu; i++)
		{
			for (j = 0; j < geshu; j++)
			{
				cin>>gailv[i][j];
			}
		}
		int ans = 0;
		double tmp;
		for (i = 0; i < geshu; i++)
		dp[i][0] = 1;
		for (j = 1; j <=t; j++)
		{
		    ans=0;
			for (i = 0; i < geshu; i++)
			{
				double tmp = 0;
				for (k = (1<<(j-1)); k <(1<< j); k++)
				{
					tmp += dp[k^i][j - 1]*gailv[i][k^i];
					//cout<<tmp<<endl;
					//cout<<"dp[k^j][j - 1]*gailv[i][k^j]"<<dp[k^(j-1)][j - 1]<<gailv[i][k^(j-1)]<<endl;
				}
				dp[i][j] = dp[i][j - 1] * tmp;
				//printf("gailv i %d j %d",i,j);
				//cout<<"is"<<dp[i][j]<<endl;
				if (dp[i][j] > dp[ans][j])ans = i;
			}
		}
		cout << ans+1 << endl;
	}
}
