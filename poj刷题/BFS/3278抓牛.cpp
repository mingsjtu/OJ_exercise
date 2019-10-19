//http://poj.org/problem?id=3278
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
using namespace std;
int n, km;
bool vis[200005];
int step[200005];
int res = 0;
const int maxn = 200001;
void bfs()
{
	queue<int> q1;
	if (!q1.empty())
		q1.pop();
	q1.push(n);
	step[n] = 0;
	//cout << "k"<<km << endl;
	int s1;
	while (!q1.empty())
	{
		//cout <<"k"<<km << endl;
		s1 = q1.front();
		q1.pop();
		int s2;

		
			//printf("pop s1%d is %d\n", s1, step[s1]);
			s2 = s1 * 2;
			
			if (s2 >= 0 && s2 < maxn&&vis[s2] == false)
			{
				step[s2] = step[s1] + 1;
				//printf("s2 %d is %d\n", s2, step[s2]);
				vis[s2] = true;
				if (s2 == km)
				{
					res = step[s2];
					return;
				}
					q1.push(s2);
			}
			s2 = s1 + 1;
			
			if (s2 >= 0 && s2 < maxn&&vis[s2] == false)
			{
				step[s2] = step[s1] + 1;
				vis[s2] = true;
				if (s2 == km)
				{
					res = step[s2];
					return;
				}
					q1.push(s2);

			}
		
		s2 = s1 - 1;
		
		if (s2 >= 0 && s2 < maxn&&vis[s2] == false)
		{
			step[s2] = step[s1] + 1;
			vis[s2] = true;
			if (s2 == km)
			{
				res = step[s2];
				return;
			}
			q1.push(s2);
		}
	}
	return;
}
int main()
{
	int i, j, k;
	memset(vis, 0, sizeof(vis));
	cin >> n >> km;

	if (n > km)
	{
		res = n - km;
		cout << res << endl;
		return 0;
	}
	bfs();
	cout << res << endl;
	return 0;

}
