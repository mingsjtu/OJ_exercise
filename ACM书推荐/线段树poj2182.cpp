//http://poj.org/problem?id=2182
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
struct node
{
	int lc;
	int rc;
	int len;
}n[30005];
void build(int l, int r, int v)
{
	n[v].lc = l;
	n[v].rc = r;
	n[v].len = r - l + 1;
	if (l == r)
	{
		return;
	}
	build(l, (l + r) / 2, 2 * v);
	build((l + r) / 2 + 1, r, 2 * v + 1);
}
int query(int shan, int v)
{
	n[v].len--;
	if (n[v].lc == n[v].rc)return n[v].lc;
	if (shan <= n[v * 2].len)
	{
		return query(shan, v * 2);
	}
	else
	{
		return query(shan - n[v * 2].len, v * 2 + 1);
	}
}
int num;
int small[8005];
int real[8005];
int main()
{
	int i, j, k;
	cin >> num;
	small[0] = 1;
	for (i = 1; i < num; i++)
	{
		cin >> small[i];
		small[i]++;
	}
	build(1, num, 1);
	for (i = num - 1; i >=0; i--)
	{
		real[i]=query(small[i], 1);
	}
	for (i = 0; i < num; i++)
	{
		cout << real[i] << endl;
	}
}