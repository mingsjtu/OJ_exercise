//http://poj.org/problem?id=3278
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
using namespace std;
int n, k;
int vis[100005];
int main()
{
	memset(vis, 0, sizeof(vis));
	cin >> n >> k;
	int i, j, r;
	int tmp;
	tmp = n;
	queue<int> q;
	q.push(n);
	int step = 0;
	int res;
	vis[n] = 0;
	while (!q.empty())
	{
		tmp = q.front();
		q.pop();
		if (tmp == k)
		{
			res = vis[tmp];
			break;
		}
		
		if (tmp - 1 >= 0&&vis[tmp-1]==0)
		{
			vis[tmp - 1] = vis[tmp]+1;
			//printf("in %d vis%d\n", tmp - 1, vis[tmp - 1]);
			q.push(tmp - 1);
		}
		if (tmp + 1 <=100000 && vis[tmp + 1] == 0)
		{
			vis[tmp + 1] = vis[tmp] + 1;
			//printf("in %d vis%d\n", tmp + 1, vis[tmp + 1]);
			q.push(tmp + 1);
		}
		if (tmp*2<= 100000 && vis[tmp*2] == 0)
		{
			vis[tmp*2] = vis[tmp] + 1;
			//printf("in %d vis%d\n", tmp *2, vis[tmp*2]);
			q.push(tmp*2);
		}
		//step++;
		//printf("step %d\n", step);
	}
	//if(n-1)
	cout << res << endl;
}