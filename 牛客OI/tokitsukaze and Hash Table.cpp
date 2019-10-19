//https://ac.nowcoder.com/acm/contest/1080/B
#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<string>
using namespace std;
int n;
int res[1000005];
int ori[1000005];
int findx(int x)
{
	if (ori[x] == x)
		return x;
	else
		return ori[x]=findx(ori[x]);
}
int main()
{
	int i, j, k;
	cin >> n;
	int xx,x;
	memset(res, -1, sizeof(res));
	for (i = 0; i < n; i++)
		ori[i] = i;
	for (i = 0; i < n; i++)
	{
		scanf("%d", &x);
		xx = x % n;
		xx = findx(xx);
		ori[xx]++;
		res[xx] = x;
	}
	for (i = 0; i < n; i++)
	{
		printf("%d ", res[i]);
	}
	cout << endl;
}