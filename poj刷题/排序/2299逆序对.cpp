//http://poj.org/problem?id=2299
#include<iostream>
#include<cstring>
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;
int n;
int ori[500005];
int tmp[500005];
int res;
//void mergesort(int l, int r, int m)
//{
//	int i, j, k;
//	i = l;
//	j = m + 1;
//	k = l;
//	while (i <= m && j <= r)
//	{
//		if (a[i] < a[j])
//		{
//			tmp[k++] = a[i++];
//		}
//		else 
//		{
//			tmp[k++] = a[j++];
//			res += m + 1 - i;
//		}
//	}
//	while (i <= m) { tmp[k++] = a[i++]; }
//	while (j <= r) { tmp[k++] = a[j++]; }
//	for (i = l; i <= r; i++)
//	{
//		a[i]=tmp[i];
//	}
//}
//void merge(int l, int r)
//{
//	if (l < r)
//	{
//		int m = (l + r) / 2;
//		merge(l, m);
//		merge(m + 1, r);
//		mergesort(l, r, m);
//	}
//}
void merge(int l, int r, int m)
{
	int i, j, k;
	i = l;
	j = m + 1;
	k = l;
	//int tmp[1005];
	memset(tmp, 0, sizeof(tmp));
	while (i <= m && j <= r)
	{
		if (ori[i] <= ori[j])
		{
			tmp[k++] = ori[i++];
		}
		else
		{
			tmp[k++] = ori[j++];
			res += m + 1 - i;
		}
	}
	while (i <= m)tmp[k++] = ori[i++];
	while (j <= r)tmp[k++] = ori[j++];
	for (i = l; i <= r; i++)
	{
		ori[i] = tmp[i];
	}

}
void solve(int l, int r)
{
	if (l < r)
	{
		int mid = (l + r) / 2;
		solve(l, mid);
		solve(mid + 1, r);
		merge(l, r, mid);
	}
}
int main()
{
	int i, j, k;
	while (1)
	{
		cin >> n;
		if (n == 0)
			break;
		memset(ori, 0, sizeof(ori));
		res = 0;

		for (i = 0; i < n; i++)
		{
			scanf("%d", &ori[i]);
		}
		solve(0, n - 1);
		printf("%d\n", res);
	}
}