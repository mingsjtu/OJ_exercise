//http://poj.org/problem?id=1276
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int dp[100005];
int qian[2000];
int b[12];//mianzhi
int g[12];//geshu
int num;
int cash;
int index = 0;
void solve(int g,int b)
{
	int i = 1;
	int sheng = g - 1;
	int tmp;
	while (g > i)
	{
		g -= i;
		qian[index++] = i * b;
		//printf("qian b%d is %d\n", b,i * b);
		i = i * 2;
	}
	if (g > 0)
	{
		qian[index++] = g * b;
		//printf("qian b%d is %d\n", b, g * b);
	}

}
int max(int a, int b)
{
	return a > b ? a : b;
}

int main()
{
	int i, j, k;
	while (scanf("%d %d", &cash, &num))
	{
		if (cash == 0 || num == 0)
		{
			cout << 0 << endl;
			continue;
		}
		index = 0;
		memset(dp, 0, sizeof(dp));

		for (i = 0; i < num; i++)
		{
			scanf("%d %d", &g[i],&b[i]);
			//printf("%d %d", g[i], b[i]);
			solve(g[i], b[i]);
		}
		//cout << "index"<<index << endl;
		//for (i = 0; i < index; i++)
		//	cout << qian[i] << endl;
		//cout << "qian" << endl;

		for (i = 0; i < index; i++)
		{
			for (k = cash; k >=qian[i]; k--)
			{

                dp[k] = max(dp[k], dp[k-qian[i]] + qian[i]);
				//cout << dp[k] << endl;

			}
		}
		printf("%d\n", dp[cash]);

	}

}
