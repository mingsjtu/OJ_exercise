#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
int n;
int a[8005],res[8005];
bool p[8005];
int main()
{
	int i, j, k;
	memset(p, 0, sizeof(p));
	cin >> n;
	a[0] = 0;
	for (i = 1; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	int cnt;
	
	for (i = n - 1; i >= 0; i--)
	{
		cnt = 0;
		for (j = 1; j <= n; j++)
		{
			
			if (!p[j])
			{
				cnt++;
			if (cnt > a[i])
			{
				res[i] = j;
				p[j] = 1;
				//printf("i%d ,j%d\n", i, j);
				break;
			}
		}
		}
	}
	for (i = 0; i < n; i++)
	{
		printf("%d\n", res[i]);
	}
	//cout << endl;
}