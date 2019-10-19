//http://noi.openjudge.cn/ch0206/2728/
#include<iostream>
#include<cstring>
using namespace std;
int num, n, m;
int map[105][105];
int dp[105][105];
int max(int a, int b)
{
	return a > b ? a : b;
}
int main()
{
	int i, j, k;
	cin >> num;
	for (i = 0; i < num; i++)
	{
	    memset(dp,0,sizeof(0));
		cin >> n >> m;
		for (j = 0; j < n; j++)
            {
        for (k = 0; k < m; k++)
			{
				cin >> map[j][k];
			}
		}
		dp[0][0]=map[0][0];
		for(j=1;j<m;j++)
            dp[0][j]=map[0][j]+dp[0][j-1];
        for(j=1;j<n;j++)
            dp[j][0]=map[j][0]+dp[j-1][0];
        //cout<<dp[0][1]<<dp[1][0]<<endl;
		for (j = 1; j < n; j++)
		{
			for (k = 1; k < m; k++)
			{
				dp[j][k] = max(dp[j - 1][k], dp[j][k - 1]) + map[j][k];
			}
			//printf("con,j%d m-1%d ,is %d\n",j,m-1,dp[j][m-1]);
		}

		cout << dp[n-1][m-1] << endl;


	}
	return 0;
}
