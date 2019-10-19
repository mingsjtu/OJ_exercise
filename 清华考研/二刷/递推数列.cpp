//https://www.nowcoder.com/practice/d0e751eac618463bb6ac447369e4aa25?tpId=40&tqId=21352&tPage=1&rp=1&ru=%2Fta%2Fkaoyan&qru=%2Fta%2Fkaoyan%2Fquestion-ranking
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
using namespace std;
int a0, a1, p, q, k;
int dp[10000005];
int main()
{
	int i, j, k;
	while (cin >> a0 >> a1 >> p >> q >> k)
	{
		p %= 10000;
		q %= 10000;
		a0 %= 10000;
		a1 %= 10000;
		dp[0] = a0;
		dp[1] = a1;
		for (i = 2; i <= k; i++)
		{
			dp[i] = p * dp[i - 1] + q * dp[i - 2];
			dp[i] %= 10000;
		}
		cout << dp[k] << endl;
	}
}