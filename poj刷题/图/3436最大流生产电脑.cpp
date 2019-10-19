//
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
using namespace std;
int vis[55];
int pre[55];
int n, p, t;
int liu[55];
int miaoshu[55][6];
int link[55][55];
int add[55][55];
int hou[55] = { -1 };
int cun[55];
bool find(int s, int t)
{
	int tmp = s;
	int i, j, k;

	//for (i = 0; i < n; i++)
	//{
	//	cun[i] = hou[i];
	//}
	memset(pre, -1, sizeof(pre));
	memset(vis, 0, sizeof(vis));
	//memset(hou, -1, sizeof(hou));

	queue<int> q1;
	q1.push(tmp);
	vis[s] = true;
	bool res = false;
	while (!q1.empty() && tmp != t)
	{
		tmp = q1.front();
		if (q1.front() == t)
		{
			res = true;
			break;
		}
		q1.pop();
		for (i = 0; i < n; i++)
		{
			if (vis[i] == 0 && link[tmp][i])
			{
				pre[i] = tmp;
				//hou[tmp] = i;
				vis[i] = true;
				if (i == t)
				{
					res = true;
					break;
				}
				q1.push(i);
			}
		}
		//tmp=q1.front();
	}
	if (res)
		return true;
	else
		return false;
}
int solve(int s, int t)
{
	int res = 0, i, j, k, minv = 100000;
	while (find(s, t))
	{
		i = t;
		while (pre[i] != -1)
		{
			minv = min(minv, link[pre[i]][i]);
			i = pre[i];
			cun[pre[i]] = i;
		}
		i = t;
		while (pre[i] != -1)
		{
			link[pre[i]][i] -= minv;
			link[i][pre[i]] += minv;
			add[i][pre[i]] += minv;
			i = pre[i];
		}
		res += minv;
	}
	return res;
}
int dfs1(int s)
{
	int i, j, k,res=0;
	for (i = 0; i < n - 2; i++)
	{
		for (j = 0; j < n - 2; j++)
		{
			if (add[i][j])
				res++;
		}
	}
	return res;
	return res;
}
int dfs(int s)
{
	int res = 0;
	int i, j, k;
	if (s == n - 1)
		return 0;
	for (i = 0; i < n; i++)
	{
		
		if (add[i][s] != 0)
		{
			if (i != n - 1 && s != n - 2)
			{
				res++;
				printf("%d %d %d\n", s + 1, i + 1, add[i][s]);
			}
			dfs(i);
		}
	}
	return res;
}
int main()
{
	t = 0;
	int res;
	int i, j, k;
	string rub;
	while (getline(cin, rub))
	{
		cin >> p >> n;
		//cout << rub << endl;
		//cout << p << n << endl;
		res = 0;
		memset(link, 0, sizeof(link));
		memset(add, 0, sizeof(add));
		memset(cun, -1, sizeof(cun));


		t++;
		for (i = 0; i < n; i++)
		{
			cin >> liu[i];
			for (j = 0; j < 2 * p; j++)
			{
				cin >> miaoshu[i][j];
			}
		}
		for (i = 0; i < n; i++)//yuan
		{
			for (j = 0; j < n; j++)//shou
			{

				int flag = 0;
				for (k = 0; k < p; k++)
				{
					//cout << miaoshu[i][k];
					if (miaoshu[i][k + p] == 0 && (miaoshu[j][k] == 2 || miaoshu[j][k] == 0))
						flag++;
					if (miaoshu[i][k + p] == 1 && (miaoshu[j][k] == 2 || miaoshu[j][k] == 1))
						flag++;
				}
				if (flag == p)
				{
					link[i][j] = liu[i];
					//printf("add edge from %d , to %d ,is %d\n", i, j, link[i][j]);
				}
			}
		}
		int in, out;
		for (i = 0; i < n; i++)
		{
			int flag1 = 0, flag2 = 0;
			for (j = 0; j < p; j++)
			{

				if (miaoshu[i][j] == 0)
				{
					flag1++;
				}
				if (flag1 == p)
				{
					link[n][i] = liu[i];
					//printf("add yuan %d\n", i);
				}
				if (miaoshu[i][j + p] == 1)
				{
					flag2++;
				}
				if (flag2 == p)
				{
					link[i][n + 1] = liu[i];
					//printf("add out %d\n", i);
				}
			}
		}
		n += 2;
		res = solve(n - 2, n - 1);
		printf("Sample output %d\n", t);
		
		i = n - 2;
		int flag=dfs1(n - 2);
		if (flag > 0)
		{
			cout <<res<<" "<< flag << endl;
			dfs(n - 2);
		}
		else
		cout << 0 << " " << 0 << endl;
		getchar();
	}
}