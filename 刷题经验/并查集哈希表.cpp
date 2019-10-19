//https://ac.nowcoder.com/acm/contest/1080/B?&headNav=acm
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>

using namespace std;
int f[1000005];
int findf(int x)
{
	if (f[x] == x)
		return x;
	else
	{
		f[x] = findf(f[x]);
		return f[x];
	}
}
int n,res[100005];
int main()
{
	int i, j, k,tmp,ftmp;
	while (cin >> n)
	{
		for (i = 0; i < n; i++)
		{
			f[i] = i;
		}
		for (i = 0; i < n; i++)
		{
			scanf("%d",&tmp);
			ftmp = findf(tmp%n);
			//printf("ftmp %d\n", ftmp);
			res[ftmp] = tmp;
			f[ftmp]++;
			if (f[ftmp] >= n - 1)
				f[ftmp] = 0;
		}
		for (i = 0; i < n; i++)
		{
			printf("%d ", res[i]);
		}
		cout << endl;
	}
}