#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
using namespace std;
int num[100000];
int dff[100000];
int N, M;
int a, b;
int main()
{
	int i, j, k;
	cin >> N>>M;
	num[0] = 0;
	dff[0] = 0;
	int res;
	for (i = 1; i <= N; i++)
	{
		scanf("%d", &num[i]);
		dff[i] = num[i] - num[i - 1];
	}
	i = 1;
	while (M-- > 0)
	{
		scanf("%d %d", &a, &b);
		while (dff[i] > a)
		{
			i = i + 1;
		}
		if (i == 1)
		{
			res = num[i] - a * i - b;
		}
		else
		{
			res = max(num[i] - a * i - b, num[i - 1] - a * (i - 1) - b);
			if (i < N)
				res = max(res, num[i + 1] - a * (i + 1) - b);
		}
		printf("%d\n", res);
	}
	
}