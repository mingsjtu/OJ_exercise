//http://bailian.openjudge.cn/xly2019/D/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
queue<int> q1;
const int f4[13] = { 4,14,24,34,41,42,43,44,45,46,47,48,49 };
bool can[51];
int main()
{
	int i, j;
	memset(can, 0, sizeof(can));
	for (i = 0; i < 13; i++)
	{
		can[f4[i]] = 1;
	}
	int n, k;
	while (cin >> n >> k)
	{
		while (!q1.empty())
		{
			q1.pop();
		}
		long long res=0;
		if (n == 0 && k == 0)
			break;
		q1.push(0);
		int cur;
		while (!q1.empty())
		{
			cur = q1.front();
			q1.pop();
			if (cur == n)
			{
				res++;
				continue;
			}
			for (i = 1; i <= k&&can[i]==0; i++)
			{
				if (cur + i <= n )
				{
					q1.push(cur + i);
				}
			}
		}
		cout << res << endl;
	}
}