//http://poj.org/problem?id=1703
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
int t;//test cases
int n,m;
int fa[100005];
bool rela[100005];
void init()
{
	int i, j, k;
	for (i = 0; i < n; i++)
	{
		fa[i] = i;
		rela[i] = 0;
	}
}
int findfa(int index)
{
	//cout << "index" << index << endl;
	int tmp = fa[index];
	if (fa[index] == index)
		return index;
	fa[index] = findfa(tmp);
	rela[index]=(rela[index] == rela[tmp]) ? 0 : 1;
	return fa[index];
}
int main()
{
	int i, j, k;
	cin >> t;
	int a, b;
	bool flag = 1;
	char command;
	while (t-- > 0)
	{
		cin >> n >> m;
		init();

		for (i = 0; i < m; i++)
		{
			//cout << i << endl;
			cin >> command;
			cin >> a >> b;
			a--; b--;
			//printf("command %c , figure %d ,figure %d\n", command, a, b);
			//printf("pa %d ,pb %d\n", fa[a], fa[b]);

			int pa = findfa(a), pb = findfa(b);
			if (command == 'A')
			{
				if (pa!=pb)

				{
					cout << "Not sure yet.\n";
					continue;
				}
				if (pa==pb&&rela[a]==rela[b])
				{
					cout << "In the same gang.\n";
					continue;

				}
				if (pa == pb && rela[a] != rela[b])
				{
					cout << "In different gangs.\n";
					continue;

				}
			}
			if (command == 'D')
			{
				if (pa != pb)
				{
					fa[pa] = pb;
					rela[pa] = (rela[b]==rela[a])?1:0;
				}
				continue;
			}
		}
	}
}