//
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
int tree[1005];
int findf(int x)
{
	if (tree[x] == -1)
		return x;
	int res = findf(tree[x]);
	tree[x] = res;
	return res;
}
int maxn[1005];
int main()
{
	int i, j, k;
	int n, x,y;
	int res=-1,maxres=0;
	while (cin >> n)
	{
		memset(maxn, 0, sizeof(maxn));
		memset(tree, -1, sizeof(tree));
		for (i = 0; i < n; i++)
		{
			scanf("%d %d", &x, &y);
			x = findf(x);
			y = findf(y);
			if (x != y)
			{
				tree[x] = y;
				maxn[y]+=maxn[x];
				if (maxn[x] > maxres)
				{
					maxres = maxn[y];
					res = y;
				}
			}
		}
		cout << maxres << endl;
	}
	
}