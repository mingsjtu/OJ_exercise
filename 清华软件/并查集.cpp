//ÍõµÀ126
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
int Tree[10000];
int n, m;
int sta, en;
int findroot(int x)
{
	if (Tree[x] == -1)
		return x;
	else
	{
		int tmp = findroot(Tree[x]);
		Tree[x] = tmp;
		return tmp;
	}
}
int main()
{
	while (cin >> n)
	{
		if (!n)break;
		int cnt = 0;
		memset(Tree, -1, sizeof(Tree));
		cin >> m;
		for (int i = 0; i < m; i++)
		{
			cin >> sta >> en;
			Tree[sta-1] = en-1;
		}
		for (int i = 0; i < n; i++)
		{
			//cout <<"root"<<i<<"is"<< findroot(i) << endl;
			if (findroot(i) ==i)
				cnt++;
		}
		cout << cnt-1 << endl;
	}
}
