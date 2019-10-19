//http://poj.org/problem?id=1125
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
struct edge
{
	int en, leng;
};
vector<edge> e[105];
int d[105];
int N;
int ok=0;
bool visited[105];
int dij(int x)
{
	//printf("dij %d\n", x);
	memset(visited, 0, sizeof(visited));
	ok = 0;
	int newp = x;
	visited[x] = 1;
	int i, j, k;
	memset(d, -1, sizeof(d));
	d[newp] = 0;
	ok++;
	edge e1;
	int prep;
	while (ok < N)
	{
		prep = newp;
		int minv = -1;
		//cout << "current ok" << ok <<"current newp "<<newp<< endl;
		for (i = 0; i < e[newp].size();i++)
		{
			
			e1 = e[newp][i];
			//printf("current edge sta %d,en %d,length %d\n", newp, e1.en, e1.leng);
			if (d[e1.en] == -1 || d[e1.en] > d[newp] + e1.leng)
			{
				d[e1.en] = d[newp] + e1.leng;
				//printf("update %d length %d  dnewp %d, e1.leng %d\n", e1.en, d[e1.en],d[newp],e1.leng);

			}
		}
		for (i = 0; i < N; i++)
		{
			if (visited[i]||d[i]==-1)continue;
			if (minv == -1||d[i]<minv)
			{
				//printf("update %d\n", i);
				newp=i;
				minv = d[i];
			}
			if (minv == -1) 
			{
				return -1;
			}
		}
		if (newp == prep)
		{
			return -1;
		}
		visited[newp] = 1;
		ok++;
		//cout << "newp" << newp << endl;
		
	}
	//cout << "last dian" << newp << endl;
	return d[newp];

}
int main()
{
	int i, j, k;
	int m,ren,time;
	edge tmp;
	while (cin >> N)
	{
		if (N == 0)
			break;
		for (i = 0; i < N; i++)
		{
			scanf("%d", &m);
			for (j = 0; j < m; j++)
			{
				scanf("%d %d", &ren, &time);
				tmp.en = ren - 1;
				tmp.leng = time;
				//printf("ren %d leng %d\n", tmp.en, tmp.leng);
				e[i].push_back(tmp);
			}
		}
		int res = 100000,tmpres,resdian=0;
		for (i = 0; i < N; i++)
		{
			tmpres=dij(i);
			//cout << "result " << tmpres << endl;
			if (tmpres!=-1&&tmpres < res)
			{
				res=tmpres;
				resdian = i;
			}
			//res=min(res,dij(i));
		}
		if (res != 100000)
			cout << resdian + 1 << " " << res << endl;
		else
			cout << "disjoint\n";
		for (i = 0; i < N; i++)
		{
			while (!e[i].empty())
			{
				e[i].pop_back();
			}
		}
	}
}