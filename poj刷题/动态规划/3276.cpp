//http://poj.org/problem?id=3267
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int w, l;
char juzi[301];
char word[601][26];
int dp[301];
int min(int a, int b)
{
	return a < b ? a : b;
}
void panduan(char a[],int sta,int en)
{
	int len = strlen(a);
	int i, j, k;
	j = 0;
	
	
}
int main()
{
	cin >> w >> l;
	int i, j, k;
	for (i = 0; i < l; i++)
	{
		cin >> juzi[i];
	}
	for (i = 0; i < w; i++)
	{
		cin >> word[i];
	}
	//myend = l - 1;
	dp[l] = 0;
	for (i = l-1; i >=0; i--)
	{
		dp[i] = dp[i + 1] + 1;
		for (j = 0; j < w; j++)
		{
			int len = strlen(word[j]);
			if (juzi[i] == word[j][0]&&len<=l-i)
			{
				int pm = i, pd = 0;
				while (pm < l)
				{
					if (juzi[pm] == word[j][pd])
					{
						pd++;
						if (pd == len)
						{
							dp[i] = min(dp[i], dp[pm + 1] + pm - i + 1 - len);
							//printf("update,i %d,pm %d,dp %d\n", i, pm, dp[i]);
							break;
						}
					}
					pm++;
				}
			}
		}
	}
	cout << dp[0] << endl;
}