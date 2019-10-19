//https://www.nowcoder.com/practice/83800ae3292b4256b7349ded5f178dd1?tpId=40&tqId=21345&tPage=1&rp=1&ru=%2Fta%2Fkaoyan&qru=%2Fta%2Fkaoyan%2Fquestion-ranking
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
int N,M;
int a[25];
bool is[105];
struct myint
{
	int shu, test;
};
queue<myint> q1;

void bfs()
{
	int i, j, k,tmp;
	myint mytmp;
	while (!q1.empty())
	{
		myint my2;
		my2 = q1.front();
		q1.pop();
		for (i = 0; i < N; i++)
		{
			tmp = my2.shu + a[i];
			if (tmp > M || is[tmp] == true)
				continue;
			is[tmp] = true;
			
			if (tmp == M)
			{
				cout << my2.test + 1<<endl;
				return;
			}
			mytmp.shu = tmp;
			mytmp.test = my2.test + 1;
			q1.push(mytmp);
		}
	}
	
	cout << 0 << endl;
	return;
}
int main()
{
	int i, j, k;
	while (cin >> M>>N)
	{
		memset(is, 0, sizeof(is));
		bool flag = false;
		while (!q1.empty())
			q1.pop();
		for (i = 0; i < N; i++)
		{
			cin >> a[i];
			if(flag)
				continue;
			if (a[i] == M)
			{
				flag = true;
				cout << 1 << endl;
				continue;
			}

			if (a[i] > M)
				continue;
			if (!is[a[i]])
			{
				myint my1;
				my1.shu = a[i];
				my1.test = 1;
				q1.push(my1);
				is[a[i]] = true;
			}
		}
		bfs();
	}
}

