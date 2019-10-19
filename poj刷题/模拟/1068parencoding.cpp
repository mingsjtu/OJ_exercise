//http://poj.org/problem?id=1068
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<string>
#include<stack>
using namespace std;
stack<int> l;
int res[50];
int main()
{
	int t, n,i,j,k;
	cin >> t;
	int tmp;
	while (t--)
	{
		memset(res, 0, sizeof(res));
		cin >> n;
		int cur = 1;
		int xuan;
		for (i = 0; i < n; i++)
		{
			cin >> tmp;
			for (j = cur; j <= tmp; j++)
			{
				l.push(j);
			}
			cur = tmp+1;
			xuan=l.top();
			l.pop();
			res[i] = tmp-xuan+1;
		}
		for (i = 0; i < n; i++)
		{
			cout << res[i] << ' ';
		}
		cout << endl;
	}
}