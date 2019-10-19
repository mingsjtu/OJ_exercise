//http://poj.org/problem?id=2388
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
int n, a[10005];
int main()
{
	int i, j, k;
	cin >> n;
	for (i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	sort(a, a + n);
	cout << a[n / 2] << endl;
}