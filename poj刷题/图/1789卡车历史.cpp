//http://poj.org/problem?id=1789
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct edge
{
	short sta,en, leng;
}e[2005*2005*2];
short tree[2005];
bool cmp(edge e1, edge e2)
{
	if (e1.leng < e2.leng)
		return true;
	else
		return false;
}
int findroot(int t)
{
	if (tree[t] == t)
		return t;
	else
	{
		tree[t]= findroot(tree[t]);
		return tree[t];
	}
}
int n, m=0;//dian,bian
char name[2005][7];
void init()
{
	int i, j, k;
	for (i = 0; i < n; i++)
	{
		tree[i] = i;
		for (j = i+1; j < n; j++)
		{
			if (i == j)
				continue;
			int len=0;
			
			for (k = 0; k < 7; k++)
			{
				if (name[i][k] != name[j][k])
					len++;
			}
			e[m].sta = i;
			e[m].en = j;
			e[m].leng = len;
			m++;
		}
	}
}
int whole = 0;
void kru()
{
	sort(e, e + m, cmp);
	//cout << "sort" << endl;
	int i, j, k;
	for (i = 0; i < m; i++)
	{
		int ps = findroot(tree[e[i].sta]);
		int pe = findroot(tree[e[i].en]);

		if (ps!=pe)
		{
			tree[e[i].en] = ps;
			whole += e[i].leng;
			//cout << "hebing" << e[i].sta << "and" << e[i].en << endl;

		}
	}
}
int main()
{
	while (cin >> n)
	{
		if (!n)
			break;
		int i, j, k;
		whole = 0;
		m = 0;
		
		for (i = 0; i < n; i++)
		{
			scanf("%s", name[i]);
		}
		init();
		//cout << "edge geshu" << m << endl;
		kru();
		printf("The highest possible quality is 1/%d.\n", whole);
	}
	
}