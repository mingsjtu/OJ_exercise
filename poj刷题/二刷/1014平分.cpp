//http://poj.org/problem?id=1014
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
int sum = 0;
int geshu[6];
int index = 0;
int qian[500];
int dp[120000];
int t = 0;
int max(int a, int b)
{
	return a > b ? a : b;
}
void solve()
{
	int i = 0;
	int c = 1;
	for (i = 0; i < 6; i++)
	{
		c = 1;
		if (geshu[i] == 0)
			continue;
		int tmp = geshu[i];
		//cout << "geshu" << geshu[i] << endl;
		while (tmp >= c)
		{
			qian[index++] = (i+1) * c;
			tmp -= c;
			c *= 2;
		}
		if(tmp>0)
		qian[index++] = tmp*(i + 1);
	}
}
int main()
{
	int i, j, k;
	while (scanf("%d %d %d %d %d %d", &geshu[0], &geshu[1], &geshu[2], &geshu[3], &geshu[4], &geshu[5]))
	{
		t++;//cishu
		index = 0;
		sum = 0;
		bool flag = false;
		for (i = 0; i < 6; i++)
		{
			if (geshu[i] != 0)
			{
				flag = true;
				break;
			}
		}
		if (!flag)
			break;
		solve();
		for (i = 0; i < 6; i++)
		{
			sum += (i+1) * geshu[i];
		}
		if (sum % 2 == 1)
		{
			printf("Collection #%d:\nCan't be divided.\n\n", t);
			continue;
		}
		sum /= 2;
		memset(dp, 0, sizeof(dp));
		for (i = 0; i < index; i++)
		{
			//cout <<"qiani"<< qian[i] << endl;
		}
		for (i = 0; i < index; i++)
		{
			for (j = sum; j >= qian[i]; j--)
			{
				
				dp[j] = max(dp[j],dp[j - qian[i]] + qian[i]);
			}
		}
		if (dp[sum] == sum)
		{
			printf("Collection #%d:\nCan be divided.\n\n", t);
		}
		else
			printf("Collection #%d:\nCan't be divided.\n\n", t);
	}

}