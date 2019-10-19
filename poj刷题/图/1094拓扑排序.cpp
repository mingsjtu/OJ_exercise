//http://poj.org/problem?id=1094
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
int cnt = 0;
int n, m;
int rudu[300];

vector<int> head[300];
int paixu()
{
	queue < int> q1;

	int i, j, k, qidian;
	bool flag = false;
	int rudu1[30];
	int ok = 0;
	int xuhao[30];
	memset(xuhao, -1, sizeof(xuhao));

	for (i = 0; i < n; i++)
	{
		if (rudu[i] == 0)
		{
			if (!flag)
			{
				qidian = i;
				flag = true;
			}
			else
			{
				return 0;
			}
		}
	}
	if (flag == 0)
		return -1;
	//cout << "here" << endl;
	q1.push(qidian);
	//ok++;
	for (i = 0; i < n; i++)
		rudu1[i] = rudu[i];
	int geshu;
	while (!q1.empty())
	{
		geshu = 0;
		qidian = q1.front();
		ok++;
		q1.pop();
		for (i = 0; i < head[qidian].size(); i++)
		{
			rudu1[head[qidian][i]]--;
			if (rudu1[head[qidian][i]] == 0)
			{
				q1.push(head[qidian][i]);
				geshu++;
				if (geshu > 1)
					return 0;
			}

		}
	}
	if (ok < n)
		return -1;
	else
		return 1;
}
int xuhao[30];
void paixu1()
{
	queue < int> q1;
	int i, j, k, qidian;
	bool flag = false;
	int rudu1[30];
	int ok = 0;
	memset(xuhao, -1, sizeof(xuhao));

	for (i = 0; i < n; i++)
	{
		if (rudu[i] == 0)
		{
			
			qidian = i;
		}
	}
	q1.push(qidian);
	//ok++;
	for (i = 0; i < n; i++)
		rudu1[i] = rudu[i];
	while (!q1.empty())
	{
		qidian = q1.front();
		xuhao[ok] = qidian;
		ok++;
		q1.pop();
		for (i = 0; i < head[qidian].size(); i++)
		{
			rudu1[head[qidian][i]]--;
			if (rudu1[head[qidian][i]] == 0)
			{
				q1.push(head[qidian][i]);
			}
		}
	}
	
}
int main()
{
	int i, j, k;
	int flag = false;
	char tmpa, tmpb, no;
	int tmpe;

	while (cin >> n >> m)
	{
		if (n == 0&&m==0)
			break;
		memset(rudu, 0, sizeof(rudu));
		for (i = 0; i < 30; i++)
		{
			while (!head[i].empty())
				head[i].pop_back();
		}
		flag = 0;
		int here = 0;
		for (i = 0; i < m; i++)
		{
			getchar();
			scanf("%c%c%c", &tmpa, &no, &tmpb);
			if (flag == -1)
				continue;
			tmpe = tmpb-'A';
			head[tmpa-'A'].push_back(tmpe);
			rudu[tmpe]++;
			flag = paixu();
			//cout << "at " << i << "is " << flag << endl;
			if (flag == 1&&here==0)
			{
				here = i;
				//continue;
			}
			if (flag == -1)
			{
				here = i;
				//continue;
			}
		}
		if (flag == 0)
			printf("Sorted sequence cannot be determined.\n");
		if (flag == -1)
			printf("Inconsistency found after %d relations.\n", here + 1);
		if (flag == 1)
		{
			paixu1();
			printf("Sorted sequence determined after %d relations: ",here+1);
			for (i = 0; i < n; i++)
			{
				cout << char(xuhao[i]+'A');
			}
			printf(".\n");
		}

	}
}