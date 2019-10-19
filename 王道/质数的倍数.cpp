//https://blog.csdn.net/wangkingkingking/article/details/80666385
#include<iostream>
#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;
typedef long long ll;
int zhishu[105];
int main()
{
	int n, k,i=0;
	cin >> n >> k;

	priority_queue<ll, vector<ll>, greater<ll>> q1;
	for (i = 0; i < n; i++)
	{
		cin >> zhishu[i];
		q1.push(zhishu[i]);
	}
	int cnt = n,tmp,tmp1;
	while (cnt < k)
	{
		tmp=q1.top();
		for (i = 0; i < n; i++)
		{
			tmp1 = tmp*zhishu[i];
			q1.push(tmp1);
			cnt++;
		}
	}
	for (i = 0; i < k; i++)
	{
		tmp1 = q1.top(); q1.pop();
		cout << tmp1 << endl;
	}
	cout << tmp1 << endl;
	return 0;
}