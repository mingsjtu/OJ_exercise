#include<iostream>
#include<cstring>
#include<cstdio>
#include<string>
using namespace std;
bool dp[100000005];
int main()
{
	int n=0, i, j, k;
	int tmp;
	memset(dp, 0, sizeof(dp));
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &tmp);
		//cout << tmp<<endl;
		dp[tmp] = 1;
	}
	//cout << dp[0] << endl;
	for (i = 0;; i++)
	{
		if (dp[i] == 0)
		{
			cout << i << endl;
			break;
		}
	}
}