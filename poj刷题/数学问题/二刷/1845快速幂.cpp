//http://poj.org/problem?id=1845
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n, k;
int zhi[5000];
int num[5000];
const int mm = 9901;
int init()
{
	int i, j, cnt = 0, cnt1 = 0;
	int nn = n;
	for (i = 2; i <= nn; i += 1)
	{
		if (i & 1 == 0)
			continue;
		//cout << i << endl;
		cnt1 = 0;
		if (nn%i == 0)
		{
			zhi[cnt] = i;
			while (nn%i == 0)
			{
				nn /= i;
				cnt1++;
			}
			num[cnt] = cnt1 * k;
			cnt++;
		}
		if (nn == 1)
		{
			break;
		}
	}
	return cnt;
}
int npowk(int a, int k)
{
	int re = 1;

	//printf("kuaisumi\n");
	while (k != 0)
	{
		if (k & 1)
		{
			re = (re*a) % mm;
			//printf("a %d, re%d\n", a, re);
		}
		k = k >> 1;
		a = (a*a) % mm;
	}

	return re;
}
int main()
{
	cin >> n >> k;

	int i, j, r;
	int geshu = init();
	int res = 1;
	for (i = 0; i < geshu; i++)
	{
		int zhong = npowk((zhi[i] % mm), num[i]);
		//cout << "zhong" << zhong << endl;
		zhong = (zhong*(zhi[i] % mm) - 1) / ((zhi[i] - 1) % mm);
		res = (res*zhong) % mm;
	}
	cout << res << endl;

}