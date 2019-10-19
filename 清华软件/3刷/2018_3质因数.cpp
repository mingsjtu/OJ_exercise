//
#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
int pri[1000];
int N, K;
int a[10000];
priority_queue<int,vector<int>,greater<int>> q1;
int main()
{
	cin >> N >> K;
	int i, j, k;
	for (i = 0; i < N; i++)
	{
		scanf("%d", &pri[i]);
		q1.push(pri[i]);
	}
	int res = 0,tmp;
	while (res< K)
	{
		tmp = q1.top();
		a[res++] = tmp;
		q1.pop();
		for (i = 0; i < N; i++)
		{
			int tmp1 =tmp*pri[i];
			q1.push(tmp1);
		}
	}
	for (i = 0; i < K; i++)
	{
		printf("%d ", a[i]);
	}

}