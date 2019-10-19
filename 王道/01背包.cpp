#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;
int max(int a1, int a2) {
	int tmp = (a1 > a2) ? a1 : a2;
	return tmp;
}
int t1[105], v1[105];
int dp[1005];//qian i ge yao, shijian
int main()
{
	int wv;
	int t, m,i=0,j;//shijian ,caoyaoshu
	cin >> t >> m;
	for (i = 0; i < m; i++)
		cin >> t1[i] >> v1[i];
	for (i = 0; i < m; i++)
	{
		dp[i] = 0;
	}
	for (i = 0; i < m; i++)
	{
		for (j = t; j >= 1; j--)
		{
			if (j - t1[i] >=0)
				dp[j] = max(dp[j - t1[i]] + v1[i], dp[j-1]);
			else
				dp[j] = dp[j-1];
		}
	}
	cout << dp[t] << endl;
	return 0;


}