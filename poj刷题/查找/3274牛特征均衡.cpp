//http://poj.org/problem?id=3274
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<map>
#include<vector>
using namespace std;
//int a[31];
int dig[100005][33];
int n, k,ans;
const int prim = 149977;
vector<int> hah[prim+3];
int max(int a, int b)
{
	return a > b ? a : b;
}
void swic(int j,int x,int w)
{
	for (int i = 0; i < w; i++)
	{
		dig[j][i] = x & 1;
		//printf("x %d dig [%d][%d] is %d\n ",x, j, i, dig[j][i]);
		x=x >> 1;
	}
}
bool allsame(int* b)
{
	int i;
	for (i = 1; i < k - 1; i++)
	{
		if (b[i] != b[i + 1])
			return false;

	}
	return true;
}
bool issame(int a, int b)
{
	int i;
	for (i = 1; i < k; i++)
	{
if (dig[a][i] != dig[b][i])
		return false;
	}
	return true;
	
}
void myhash(int* a,int index)
{
	int sum=0,i;
	for (i = 0; i < k; i++)
		sum += a[i];
	sum %= prim;
	for (i = 0; i < hah[sum].size(); i++)
	{
		if (issame(index, hah[sum][i]))
		{
			//printf("a %d ,b %d \n", index, hah[sum][i]);
			ans = max(ans, index-hah[sum][i] );
		}
	}
	hah[sum].push_back(index);

}
int main()
{
	ans = 0;
	int i, j=0, r,v;
	cin >> n >> k;
	for (i = 0; i < n; i++)
	{
		scanf("%d", &v);
		swic(i, v, k);
	}
	for (i = 1; i < n; i++)
	{
		for (j = 0; j < k; j++)
		{
			dig[i][j] += dig[i - 1][j];
		}
	}
	for (i = n-1; i >= 0; i--)
	{
		for (r = 1; r < k; r++)
		{
			dig[i][r] = dig[i][r] - dig[i][0];
			
		}
		dig[i][0] = 0;
	}

	for (i = n-1; i >=0; i--)
	{
		if (allsame(dig[i]))
			break;
	}
	ans = i;
	for (i = 0; i < n; i++)
	{
		myhash(dig[i], i);
	}
	printf("%d\n", ans);
}