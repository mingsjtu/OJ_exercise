//https://www.nowcoder.com/practice/0160bab3ce5d4ae0bb99dc605601e971?tpId=40&tqId=21359&tPage=2&rp=2&ru=%2Fta%2Fkaoyan&qru=%2Fta%2Fkaoyan%2Fquestion-ranking
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
int n, m;
int zhen[605];
struct bian
{
	int sta, en, len;
}b[10005];
vector<bian> head[605];
int f()
{
	int s[605];
	bool vis[605];
	memset(s, -1, sizeof(s));
	memset(vis, 0, sizeof(vis));
	vis[1] = 1;
	int newp = 1;
	int i;
	s[1] = 0;
	int ok = 1;
	bian b1;
	while (newp!=2)
	{
		printf("newp %d\n", newp);
		for (i = 0; i < head[newp].size(); i++)
		{
			b1 = head[newp][i];
			int e = b1.en;
			int l = b1.len;
			if (vis[e])
				continue;
			if (s[e] == -1 || s[e] > l + s[newp])
			{
				//cout << 'e' << e << "len" << l << endl;
				s[e] = l + s[newp];
			}
		}
		int minx = 1000000000;
		for (i = 1; i <= n; i++)
		{
			if (s[i] == -1 || vis[i])
				continue;
			if (s[i] < minx)
			{
				minx = s[i];
				newp = i;
			}
		}
		vis[newp] = 1;
		ok++;
	}
	return s[2];
}
int main()
{
	int i, j, k;
	int s1, s2, tmp;
	while (cin >> n)
	{
		if (n == 0)
			break;
		cin >> m;
		for (i = 0; i < m; i++)
		{
			scanf("%d %d %d", &b[2 * i].sta, &b[2 * i].en, &b[2 * i].len);
			b[2 * i + 1].sta = b[2 * i].en;
			b[2 * i + 1].en = b[2 * i].sta;
			b[2 * i + 1].len = b[2 * i].len;
		}
		for (i = 1; i <= n; i++)
		{
			scanf("%d", &zhen[i]);
		}
		for (i = 0; i < 2 * m; i++)
		{
			//printf("push sta%d en%d len%d\n", b[i].sta, b[i].en, b[i].len);
			if (zhen[b[i].sta] == zhen[1] || zhen[b[i].sta] == zhen[b[i].en])
			{
				printf("push sta%d en%d len%d\n", b[i].sta, b[i].en, b[i].len);
				head[b[i].sta].push_back(b[i]);
			}
		}
		//cout << dis[0][1] << endl;

		cout << f() << endl;
		for (i = 1; i <= n; i++)
		{
			if (!head[i].empty())
				head[i].clear();
		}
	}
}