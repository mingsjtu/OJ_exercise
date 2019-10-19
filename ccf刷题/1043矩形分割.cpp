//http://oj.noi.cn/oj/#main/show/1043
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct ju
{
	int sta, end, w;
};
int map[1000005];
int r,n;
int xiajie = 1000000, shangjie = 0;

void solve(int l,int w,int h)
{
	for (int i = l; i <= l + w - 1; i++)
	{
		map[i] += h;
	}
}
int res;
long long a[1000005];
void myfind(int sta, int en, int tar)
{
	//printf("find %d and %d is tar%d\n", sta, en,tar);
	if (sta == en)
		return;
	int m = (sta + en) / 2;
	if (a[m] > tar)
	{
		res = m;
		if(m-1>sta)
			myfind(sta, m-1, tar);
	}
	if (a[m] < tar)
	{	
		if (m + 1 < en)
		{
			myfind(m+1, en, tar);
		}
	}
	if(a[m]==tar)
	{
		res = m;
		return;
	}
}

int main()
{
	cin >>r;
	cin >> n;
	int i, j, k;
	int l, t, w, h;
	memset(map, 0, sizeof(map));
	memset(a, 0, sizeof(a));
	for (i = 0; i < n; i++)
	{
		scanf("%d %d %d %d", &l, &t, &w, &h);
		solve(l, w, h);
		xiajie = min(xiajie, l);
		shangjie = max(shangjie, l + w);
	}
	for (i = xiajie; i < shangjie; i++)
	{
		//printf("map[%d] is %d\n", i, map[i]);
		a[i] =a[i-1]+map[i];
		//printf("a[%d] is %d\n", i, a[i]);
	}
	long long sum=a[shangjie - 1];
	myfind(xiajie,shangjie-1, sum / 2);
	if (res != 0)
	{
		i = res;

		while (a[i++] == a[res])
		{
			//cout << "i" << i << endl;
		}

		res = i - 1;
	}
	else
	{
		res = shangjie;
	}
	cout << res << endl;
}
