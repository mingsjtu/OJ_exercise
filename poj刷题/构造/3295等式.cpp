//http://poj.org/problem?id=3295
#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
#include<stack>
using namespace std;
stack<char> fu;
stack<bool> shu;
char s[105];
bool use[5];
bool v[35][5];
void init()
{
	int i, j, k;
	memset(v, 0, sizeof(v));
	for (i = 0; i < 32; i++)
	{
		if (i % 32 > 15)
		{
			v[i][0] = 1;
		}
		if (i % 16 > 7)
		{
			v[i][1] = 1;
		}
		if (i % 8 > 3)
		{
			v[i][2] = 1;
		}
		if (i % 4 > 1)
		{
			v[i][3] = 1;
		}
		if (i % 2 == 1)
		{
			v[i][4] = 1;
		}
	}
}
int main()
{
	int i, j, k;
	int con = 1;
	init();

	while (scanf("%s", s) != EOF)
	{
		bool flag = true;
		int res = 2;
		con = 1;
		memset(use, 0, sizeof(use));
		while (!fu.empty())
		{
			fu.pop();
		}
		while (!shu.empty())
		{
			shu.pop();
		}
		int len = strlen(s);

		char curf;
		bool curs1, curs2;

		for (k = 0; k < 32; k++)
		{
			while (!fu.empty())
			{
				fu.pop();
			}
			while (!shu.empty())
			{
				shu.pop();
			}
			for (i = 0; i < len; i++)
			{
				if (s[i] >= 'p'&&s[i] <= 't')
				{
					//printf("push %d\n", v[k][s[i] - 'p']);
					shu.push(v[k][s[i] - 'p']);
					//printf("push %d\n", v[k][s[i] - 'p']);
					if (use[s[i] - 'p'] == 0)
						use[s[i] - 'p'] = 1;
				}
				else
				{
					if (s[i] >= 'A'&&s[i] <= 'Z')
					{
						fu.push(s[i]);
					}
					else
					{
						flag = false;
					}
				}
				

			}
			if (!flag)
			{
				break;
			}
			//printf("fu size%d\n", fu.size());
			//printf("shu size%d\n", shu.size());
			while (!fu.empty())
			{
				curf = fu.top();
				fu.pop();
				switch (curf)
				{
				case 'K':
				{
					if (shu.size() < 2)
					{
						flag = false;
						break;
					}
					curs1 = shu.top();
					shu.pop();
					curs2 = shu.top();
					shu.pop();
					shu.push(curs1&&curs2);
					break;
				}
				case 'A':
				{
					if (shu.size() < 2)
					{
						flag = false;
						break;
					}
					curs1 = shu.top();
					shu.pop();
					curs2 = shu.top();
					shu.pop();
					shu.push(curs1 || curs2);
					break;
				}
				case 'N':
				{
					if (shu.size() < 1)
					{
						flag = false;
						break;
					}
					curs1 = shu.top();
					shu.pop();

					shu.push(!curs1);
					break;
				}
				case 'C':
				{
					if (shu.size() < 2)
					{
						flag = false;
						break;
					}
					curs1 = shu.top();
					shu.pop();
					curs2 = shu.top();
					shu.pop();
					if (curs1 == 0 && curs2 == 1)
						shu.push(0);
					else
						shu.push(1);
					break;
				}
				case 'E':
				{
					if (shu.size() < 2)
					{
						flag = false;
						break;
					}
					curs1 = shu.top();
					shu.pop();
					curs2 = shu.top();
					shu.pop();
					if (curs1 != curs2)
						shu.push(0);
					else
						shu.push(1);
					break;
				}
				}
			}
			if (shu.size() != 1)
			{
				flag = false;
				break;
			}
			//printf("res %d\n", shu.top());
			if (res == 2)
			{
				res = shu.top();
			}
			else
			{
				if (res == shu.top())
				{
					continue;
				}
				else
				{
					flag = false;
					break;
				}
			}
		}
		if (flag)
			printf("tautology\n");
		else
			printf("not\n");
	}
}