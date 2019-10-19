//http://poj.org/problem?id=1463
#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
using namespace std;
int num;
int r, rnum;
vector<int> tree[1502];
int fa[1502];//jilu baba
int dp[1502][2];
int min(int a, int b)
{
	return a > b ? b : a;
}
void dfs(int f)
{
	int i, j, k;
	int len = tree[f].size();
	dp[f][0] = 0;
	dp[f][1] = 1;
	//cout << "len" << len << endl;
	for (i = 0; i < len; i++)
	{
		dfs(tree[f][i]);
	}
	for (i = 0; i < len; i++)
	{
		dp[f][0] += dp[tree[f][i]][1];
		dp[f][1] += min(dp[tree[f][i]][0], dp[tree[f][i]][1]);
	}
}
int main()
{
	int i, j, k;
	int tmp;
	while (cin >> num)
	{
		memset(fa, -1, sizeof(fa));
		for (i = 0; i < num; i++)
		{
			scanf("%d:(%d)", &r, &rnum);
			memset(dp, 0, sizeof(dp));
			tree[r].clear();
			for (j = 0; j < rnum; j++)
			{
				scanf("%d", &tmp);
				tree[r].push_back(tmp);
				fa[tmp] = r;
			}
			//cout << "current" << tree[i].size() << endl;
		}
		int a = 0;
		//cout << "fa0" << fa[0] << endl;

		while (fa[a] != -1) a = fa[a];
		//cout << a << endl;
		dfs(a);
		cout << min(dp[a][1], dp[a][0])<<endl;
	}
}