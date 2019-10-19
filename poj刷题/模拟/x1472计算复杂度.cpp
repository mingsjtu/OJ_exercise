//http://poj.org/problem?id=1472
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
#include<stack>
using namespace std;
char oper[20];
const char con[3][6] = { "BEGIN","LOOP","OP" };
struct elem
{
	int type;
	int myci;
	bool isn;
};
int xishu[25];
void solve(elem e)
{
	int i, j, k;
	if (e.type == 1)
	{
		if (e.isn)
		{
			for (i = 24; i >= 0; i--)
			{
				xishu[i] = xishu[i - 1];
			}
		}
		else
		{
			int tmp = e.myci;
			for (i = 0; i < 25; i++)
			{
				xishu[i] *= tmp;
			}
		}
	}
	if (e.type == 2)
	{
		if (e.isn)
		{

			xishu[1] ++;
		}
		else
		{
			xishu[0] += e.myci;
		}
	}
}
int main()
{
	int i, j, k, n,t=0;
	int a=1, b=0, num;
	char num1[10];
	cin >> n;
	char ci;
	while (n--)
	{
		t++;
		memset(xishu, 0, sizeof(xishu));
		int last = 25 - 1;
		a = 1; b = 0;
		stack<int> s;
		bool flag = false;
		while (cin >> oper)
		{
			//printf("oper %s  ,size %d\n",oper, s.size());
			if (oper[0]=='B')
				s.push(-2);
			if (oper[0]=='L')
			{
				cin >> num1;
				if (num1[0] == 'n')
				{
					b++;
					s.push(-1);
				}
				else
				{
					num = num1[0] - '0';
					int len = strlen(num1);
					for (i = 1; i < len; i++)
					{
						num *= 10;
						num += num1[i] - '0';
					}
					a *= num;
					s.push(num);
					printf("push %d\n", num);
				}
			}
			if (oper[0] == 'O')
			{
				cin >> num1;
				num = num1[0] - '0';
				int len = strlen(num1);
				for (i = 1; i < len; i++)
				{
					num *= 10;
					num += num1[i] - '0';
				}
				//a *= num;
				xishu[b] += a * num;
			}
			if (oper[0] == 'E')
			{
				num = s.top();
				s.pop();
				//printf("pop %d\n", num);
				if (num == -1)
					b--;
				else
				{
					if (num == -2)
					{
						flag = true;
						break;
					}
					else
						a /= num;
				}
			}
			if (flag)
				break;
		}
		//printf("ok\n");
		/*for (i = 24; i >= 0; i--)
		{
			if (xishu[i] != 0)
				printf("xishu %dis %d\n", i, xishu[i]);
		}*/
		for (i = 0; i <= 24; i++)
		{
			if (xishu[i] != 0)
			{
				last = i;
				break;
			}
		}
		printf("Program #%d\nRuntime = ", t);
		for (i = 24; i >last; i--)
		{
			if (xishu[i] > 0)
			{
				if (xishu[i] > 1)
				{
					if (i > 1)
						printf("%d*n^%d+", xishu[i], i);
					else
						printf("%d*n+", xishu[i]);
				}
				else
				{
					if (i > 1)
						printf("n^%d+", i);
					else
						printf("n+");
				}
			}
		}
		if (xishu[last] > 1)
		{
			if (last > 1)
				printf("%d*n^%d\n", xishu[last], last);
			if (last == 1)
				printf("%d*n\n", xishu[1]);
		}
		if (xishu[last] ==1)
		{
			if (last > 1)
				printf("n^%d\n",last);
			if (last == 1)
				printf("n\n");
		}
		if (last == 0)
			printf("%d\n", xishu[0]);
	}
}