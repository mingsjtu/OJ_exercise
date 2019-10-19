//http://poj.org/problem?id=2259
#include<iostream>
#include<cstring>
#include<map>
#include<string>
#include<cstdio>
#include<queue>
using namespace std;
int n, m;//duishu,duiyuanshu
int suoshu[1000000];
queue<int> q1[1001];
int index[1001];//duilieshuxu
int shunxu=0;
int shunxupop = 0;
void deal(string command)
{
	int tmp, cur;
	//cout << "shunxu" << shunxupop << endl;
	if (command.find("ENQUEUE") != -1)
	{
		cin >> cur;
		tmp = suoshu[cur];
		if (q1[tmp].empty())
		{
			index[shunxu] = tmp;
			shunxu++;
		}
		q1[tmp].push(cur);
	}
	if (command.find("DEQUEUE") != -1)
	{

		tmp=index[shunxupop];
		if (!q1[tmp].empty())
		{
			cout<<q1[tmp].front()<<endl;
			q1[tmp].pop();
			if (q1[tmp].empty())
				shunxupop++;
		}
	}
}
int cishu = 1;
int main()
{
	int i, j, k;
	int tmp;
	string command;
	while (cin >> n)
	{
		shunxu = 0;
		shunxupop = 0;

		if (n == 0)
			break;
		printf("Scenario #%d\n", cishu++);
		for (i = 0; i < 1001; i++)
		{
			while (!q1[i].empty())
				q1[i].pop();
		}
		if (n == 0)
			return 0;

		for (i = 0; i < n; i++)
		{
			cin >> m;
			for (j = 0; j < m; j++)
			{
				cin >> tmp;
				suoshu[tmp] = i;
			}
		}
		//cout << "wan" << endl;
		while (cin >> command)
		{
			if (command.find("STOP")!=-1)
				break;
			deal(command);
		}
		cout << endl;
	}
	return 0;
}
