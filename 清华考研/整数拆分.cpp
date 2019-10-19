//https://www.nowcoder.com/practice/376537f4609a49d296901db5139639ec?tpId=40&tqId=21339&tPage=1&rp=1&ru=%2Fta%2Fkaoyan&qru=%2Fta%2Fkaoyan%2Fquestion-ranking
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
using namespace std;
int dp[1000005];
int a[25];
int maxi[1000005];
int main()
{
	int i, j, k;
	memset(dp, 0, sizeof(dp));
	//memset(maxi, 0, sizeof(maxi));
	a[0] = 1;
	dp[0] = 1;
	for (i = 1; i <=21; i++)
	{
		a[i] = a[i - 1] << 1;
		//cout << a[i] << endl;
		
	}
	
	for (i = 0; i <= 20; i++)
	{
		for (j = a[i];;j++)
		{
			if (j >= 1000005)
				break;
			dp[j] += dp[j - a[i]];
			dp[j] %=1000000000;
		};
	}
	while (cin >> i)
	{
		cout << dp[i] << endl;
	}
}