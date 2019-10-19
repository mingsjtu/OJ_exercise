//http://poj.org/problem?id=1703
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int t;
char command;
int a, b;
int n, m;
int length[100005];

int fa[100005];//
int re[100005];//0 same,1 diff
int findfa(int son)
{
	if (fa[son] == son)
		return son;
	else
	{
		int tmp = fa[son];
		fa[son] = findfa(fa[son]);
		length[fa[son]]+=length[son];
		re[son] = (re[son] == re[tmp]) ? 0 : 1;
		return fa[son];
	}
}
void hebing(int a,int b)
{
	if (length[a] >= length[b])
	{
		fa[b] = fa[a];
		re[b] = (re[a] == 0) ? 1 : 0;
	}
	if(length[a]<length[b])
	{
		fa[a] = fa[b];
		re[a] = (re[b] == 0) ? 1 : 0;
	}
}
int main()
{
	int i, j, k;
	cin >> t;
	while (t-->0)
	{
		scanf("%d %d \n", &n, &m);
		for (i = 0; i < n; i++)
		{
			fa[i] = i;
			re[i] = 0;
			length[i] = 1;
		}
		for (i = 0; i < m; i++)
		{
			scanf("\n%c %d %d",&command, &a, &b);
			//cout <<"command a b"<< command <<endl;
			a--; b--;
			int fa_a = findfa(a);
			int fa_b = findfa(b);
			if (command == 'A')
			{
				if (fa_a == fa_b)
				{
					//printf("a %d b %d fa%d fb%d rea%d reb%d\n", a, b, fa[a], fa[b], re[a], re[b]);
					if (re[a] == re[b])
					{
						printf("In the same gang.\n");
					}
					else
					{
						printf("In different gangs.\n");
					}
				}
				else
				{
					printf("Not sure yet.\n");
				}
				continue;
			}
			if (command == 'D')
			{

				if (fa_a != fa_b)
					hebing(a, b);
			}
			//printf("a %d b %d fa%d fb%d rea%d reb%d\n", a, b, fa[a], fa[b],re[a],re[b]);
		}
		
	}

}