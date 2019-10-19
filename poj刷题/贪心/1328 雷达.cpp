//http://poj.org/problem?id=1328
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<math.h>
using namespace std;
int x[1005], y[1005];
int n, d;
struct jie
{
	double j1, j2;
};
jie jj0[1005];
//double jie1[1005], jie2[1005];
bool compute(int x, int y, int i)
{
	if (y> d)
		return false;
	double res = sqrt(d*d - y * y);
	//cout << res << endl;
	jj0[i].j1 = x-res;
	jj0[i].j2 = res + x;
	return true;
}
bool cmp(jie jie1, jie jie2)
{
	if (jie1.j1 < jie2.j1)
		return true;
	return false;
}
int main()
{
	int i, j, k;
	int t = 1;
	bool f1 = true;
	while (cin >> n >> d)
	{
		f1 = true;

		//printf("start\n");
		if (n == 0 && d == 0)
			break;
		for (i = 0; i < n; i++)
		{
			cin >> x[i] >> y[i];
			if (!compute(x[i], y[i],i))
			{
				f1 = false;
			}
		}
		getchar();

		if (!f1)
		{
			printf("Case %d: %d\n", t, -1);
			t++;
			continue;
		}
		int ans = 1;
		sort(jj0, jj0 + n,cmp);
		double end = jj0[0].j2;
		double maxv = end;
		for (i = 0; i < n; i++)
		{
			if (end <jj0[i].j1)
			{
				end = jj0[i].j2;
				//end = maxv;
				ans++;
			}
			else
			{
				end = min(end, jj0[i].j2);
			}
			//maxv = jj0[i].j2;
		}
		printf("Case %d: %d\n", t, ans);
		t++;
	}

}