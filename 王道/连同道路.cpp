//《王道》126页
#include<iostream>
#include<iomanip>
#include<cstring>
#include<string>
#include<vector>
#include<math.h>
#include<algorithm>
using namespace std;
const int maxn = 1000;
int tree[maxn];
int findtree(int i)
{
	if (tree[i] == -1)
		return i;
	else
	{
		int tmp = findtree(tree[i]);
		tree[i] = tmp;
		return tmp;
	}
}
struct edge
{
	int sta, en;
	double cost;
	void init(int sta1,int en1,double c1)
	{
		sta = sta1;
		en = en1;
		cost = c1;
	}
	bool operator<(const edge &e)
	{
		if (cost < e.cost)
		{
			return true;
		}
		else return false;
	}
}e1[1000];
bool cmp(edge &e1, edge &e2)
{
	if (e1.cost < e2.cost)
		return true;
	else
		return false;
}
double nodex[101], nodey[101], noded[101];
int main()
{
	int m;//边的数量
	double tx, ty;
	double td;
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> tx >> ty;
		//td = sqrt(tx*tx + ty * ty);
		nodex[i] = tx;
		nodey[i] = ty;
		//noded[i] = td;
		tree[i] = -1;
	}
	int i, j,r=0;
	for (i = 0; i < m; i++)
	{
		for (j = i + 1; j < m; j++)
		{
			td = sqrt((nodex[i] - nodex[j])*(nodex[i] - nodex[j]) + (nodey[i] - nodey[j])*(nodey[i] - nodey[j]));
			//cout << "td" << td << endl;
			e1[r++].init(i, j, td);
		}
	}
	sort(e1,e1+2,cmp);

	int sta1, en1, r1, r2;
	double line = 0.0;
	for (i = 0; i < r; i++)
	{
		sta1=e1[i].sta;
		cout << "sta" << sta1<<endl;
		en1 = e1[i].en;
		cout << "en" << en1 << endl;
		r1 = findtree(sta1);
		r2 = findtree(en1);
		printf("%d root %d,%d root %d",sta1,r1,en1 , r2);
		if (r1 != r2)
		{
			tree[sta1] = en1;
			line += e1[i].cost;
			printf("from %d to %d", e1[i].sta, e1[i].en);
		}

	}
	cout << line;
}