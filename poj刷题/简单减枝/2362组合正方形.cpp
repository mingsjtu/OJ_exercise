//http://poj.org/problem?id=2362
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
using namespace std;
int t, n, len[22];
int vis[22];
bool flag = false, flag1 = true;;
int sum, each;
int map[4];
void dfs(int sta, int fin,int left)
{
	//printf("dfs sta%d,fin%d, left%d\n", sta, fin,left);
	int i, j, k;
	int tmp=0;
	if (fin == 3)
	{
		flag = true;
		return;
	}
	for (i = sta; i < n; i++)
	{
		//printf("fin %d ,test i%d\n",fin, i);
		if (vis[i] == 0)
		{
			vis[i] = fin + 1;
			if (len[i] == left)
			{
				dfs(0, fin + 1, each);
				if (flag)
					return;
			}
			if (len[i] < left)
			{
				dfs(i + 1, fin, left - len[i]);
				if(flag)
					return;
			}
			vis[i] = 0;
			//map[fin + 1] -= len[i];
		}
	}
}

int main()
{
	int i, j, k;
	scanf("%d", &t);
	
	while (t--)
	{
		sum = 0;
		memset(vis, 0, sizeof(vis));
		memset(map, 0, sizeof(map));
		flag = false;
		flag1 = true;
		scanf("%d", &n);
		for (i = 0; i < n; i++)
		{
			scanf("%d", &len[i]);
			sum += len[i];
		}
		if (sum % 4 == 0)
		{
			each = sum / 4;
			for (i = 0; i < n; i++)
			{
				if (len[i] > each)
					flag1 = false;
			}
		}
		else
		{
			flag1 = false;
		}
		if (flag1)
			dfs(0, 0, each);
		else
		{
			flag = false;
		}
		if (flag == true)
			printf("yes\n");
		else
			printf("no\n");
		
		
	}
}