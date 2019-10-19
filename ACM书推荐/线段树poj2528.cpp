#define _CRT_SECURE_NO_DEPRECATE
//http://poj.org/problem?id=2528
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
bool gai[10005];
struct node
{
	int lc;
	int rc;
	int value;
};
node n[20000005];

int maxv = 0;
void build(int v, int l, int r)
{
	n[v].lc = l;
	n[v].rc = r;
	n[v].value = 0;
	if (l == r)return;
	else
	{
		if (v * 2 + 1 > maxv)maxv = v * 2 + 1;
		build(v * 2, l,(l+r)/2);
		build(v * 2 + 1, (l + r) / 2 + 1, r);
		return;
	}
}
void fugai(int l,int r, int gai,int v)//fugaide shu, dangqian jiedian
{
	//cout << "fugai" << l << "and" << r << endl;
	//cout << "current v" <<v<<"is"<< n[v].lc<<"and"<<n[v].rc << endl;
	if (n[v].lc == l && n[v].rc == r)
	{
		n[v].value = gai;
		return;
	}
	int mid = (n[v].lc + n[v].rc) / 2;
	if (n[v].lc<=l && r<=mid)
	{
		return fugai(l, r, gai, v * 2);
	}
	if (l > mid && n[v].rc >= r)
	{
		return fugai(l, r, gai, v * 2 + 1);
	}
	else
	{
		fugai(l, mid, gai, v * 2);
		fugai(mid+1, r, gai, v * 2 + 1);
		return;
	}
}
int ans=0;
void find(int v)
{
	int i;
	for (i = 0; i <= maxv; i++)
	{
		int tmp = n[i].value;
		if (tmp > 0 && gai[tmp] == false)
		{
			//cout << "yes" << endl;
			ans++;
			gai[tmp] = true;
		}
	}
	/*
	if (n[v].value!=0)
	{
		if (gai[n[v].value] == false)
		{
			ans++;
			cout << "gaizhule" << n[v].value << endl;
			gai[n[v].value] = true;
		}
		return;
	}
	if (v * 2 > maxv)
		return;
	find(v * 2);
	if (v * 2+1 > maxv)
		return;
	find(v * 2 + 1);
	return;
	*/
}
int min(int a, int b)
{
	return a < b ? a : b;
}
int max(int a, int b)
{
	return a > b ? a : b;
}
int t;//test case
int num;
int le[10005];
int ri[10005];
int p=1, q=1;//zuo you
int main()
{
	
	cin >> t;
	int i, j, k;
	while (t-- > 0)
	{
		cin >> num;
		
		for (i = 0; i < num; i++)
		{
			scanf("%d %d", &le[i], &ri[i]);
			p = min(le[i], p);
			q = max(ri[i], q);
			//cout << p << q << endl;
		}
		build(1, p, q);
		//cout << "maxv" << maxv << endl;
		for (i = 0; i < maxv; i++)
		{
			gai[i] = false;
		}
		for (i = 0; i < num; i++)
		{
			fugai(le[i], ri[i], i + 1, 1);
		}
		find(1);
		
		cout << ans << endl;
	}
}
