//http://poj.org/problem?id=1094
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
int n, m;
vector<int> head[30];
int rudu[30];
int sorted[30];
int map[30];
int tuopu()
{
	int res = -1;
	int i, j, k;
	int newp = -1;
	int tou = 0;
	bool vis[30];
	int rudu1[30];
	for (i = 0; i < n; i++)
		rudu1[i] = rudu[i];
	memset(vis, 0, sizeof(vis));
	for (i = 0; i < n; i++)
	{
		if (!rudu1[i])
		{
			newp = i;
			if (tou > 0)
			{
				res = 0;
				return 0;
			}
			tou++;
		}
	}
	//printf("find newp%d\n", newp);
	queue<int> dian;
	if (!dian.empty())
		dian.pop();
	dian.push(newp);
	tou = 0;
	int ok;
	ok = 1;
	map[newp] = 0;
	sorted[0] = newp;
	vis[newp] = 1;
	while (!dian.empty() && ok < n)
	{
		tou = 0;
		newp = dian.front();
		//printf("pop %d\n", newp);
		dian.pop();
		int newp1 = -1;
		//printf("size %d\n", head[newp].size());
		for (i = 0; i < head[newp].size(); i++)
		{
			//printf("here i%d\n", head[newp][i]);
			if (vis[head[newp][i]] == 1)
				continue;
			rudu1[head[newp][i]]--;
		}
		tou = 0;
		for (j = 0; j < n; j++)
		{
			//printf("rudu1 i %d is %d\n", j, rudu1[j]);
			if (rudu1[j] == 0 && vis[j] == 0)
			{
				//printf("rudu10\n");
				newp1 = j;
				if (tou > 0)
				{
					res = 0;
					return 0;
				}
				tou++;
			}
		}
		if (newp1 == -1)
			return 2;
		vis[newp1] = 1;
		dian.push(newp1);
		sorted[ok] = newp1;
		map[newp1] = ok;
		//printf("find newp%d ok%d\n", newp1, ok);
		ok++;
	}
	if (ok < n - 1)
		return 2;
	return 1;
}

int main()
{
	int i, j, k;
	char a, b, rab;
	//cin >> t;
	int result = -1;
	int det = 0;
	while (scanf("%d %d", &n, &m) != EOF)
	{
		if (n == 0 && m == 0)
			break;
		memset(rudu, 0, sizeof(rudu));
		memset(sorted, 0, sizeof(sorted));
		memset(map, 0, sizeof(map));
		det = 0;
		result = -1;
		for (i = 0; i < 30; i++)
		{
			while (!head[i].empty())
				head[i].pop_back();
		}
		for (i = 0; i < m; i++)
		{
			cin >> a >> rab >> b;
			//printf("pre res%d\n", result);
			//if (result == 1)
			//{
			//	if (map[a - 'A'] > map[b - 'A'])
			//	{
			//		//printf("er\n");
			//		result = 2;
			//		det = i + 1;
			//		break;
			//	}
			//}
			if (result == 2||result==1)
				continue;
			if (result == 0 || result == -1)
			{
				//printf("a %d b%d\n", a - 'A', b - 'A');
				head[a - 'A'].push_back(b - 'A');
				rudu[b - 'A']++;
				//for (j = 0; j < n; j++)
					//printf("rudu i %d is %d\n", j, rudu[j]);
				result = tuopu();
				if (result == 1 || result == 2)
					det = i+1;
			}
			//printf("result %d\n", result);
		}
		if (result == 1)
		{
			printf("Sorted sequence determined after %d relations: ", det);
			for (i = 0; i < n; i++)
			{
				printf("%c", char(sorted[i] + 'A'));
			}
			printf(".\n");
			//for (i = 0; i < n; i++)
			//{
			//	printf("%d ", map[i]);
			//}
		}
		if (result == 0)
		{
			printf("Sorted sequence cannot be determined.\n");
		}
		if (result == 2)
		{
			printf("Inconsistency found after %d relations.\n", det);
		}
	}

}