//https://www.nowcoder.com/practice/d0e751eac618463bb6ac447369e4aa25?tpId=40&tqId=21352&tPage=1&rp=1&ru=%2Fta%2Fkaoyan&qru=%2Fta%2Fkaoyan%2Fquestion-ranking
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;

short dp[1000005];
int main()
{
	int a0, a1, p, q, k;
	int i, j;
	while (cin >> a0 >> a1 >> p >> q >> k)
	{
		a0 %= 10000;
		a1 %= 10000;
		p %= 10000;
		q %= 10000;
		dp[0] = a0;
		dp[1] = a1;
		for (i = 2; i <= k; i++)
		{
			dp[i] = p * dp[i - 1]%10000 + q * dp[i - 2] % 10000;
		}
		cout << dp[k]%10000 << endl;
	}
}