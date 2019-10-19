//º∆À„∆˜£¨’ª µœ÷
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<stack>
#include<string>
#include<math.h>
using namespace std;
string ori;
int len;
bool flag;
stack<int> v1;
stack<char> f1;
int readint(int sta)
{
	int i, j, k;
	int res = 0;
	for (i = sta; i < len; i++)
	{
		if (ori[i] > '9' || ori[i] < '0')
			break;
		res *= 10;
		res += ori[i] - '0';
	}
	if (i == len - 1)
		flag = false;
	v1.push(res);
	return i-1;
}
void deal(int com)
{
	int s1 = v1.top();
	v1.pop();
	int s2 = v1.top();
	v1.pop();
	printf("deal %c %d and %d\n", com,s1,s2);

	int res = 0;
	switch (com)
	{
	case '+':
	{
		res = s1 + s2;
		v1.push(res);
		break;
	}
	case '-':
	{
		res = s2 - s1;
		v1.push(res);
		break;
	}
	case '*':
	{
		res = s1 * s2;
		v1.push(res);
		break;
	}
	case '/':
	{
		res = s2 / s1;
		v1.push(res);
		break;
	}
	case '^':
	{
		res = int(pow(s2, s1));
		v1.push(res);
		break;
	}
	}
}
int main()
{
	int i;
	char cur;
	while (cin >> ori)
	{
		while (!v1.empty())
		{
			v1.pop();
		}
		while (!f1.empty())
			f1.pop();
		len = ori.length();
		flag = true;
		for (i = 0; i < len&&flag; i++)
		{
			if (ori[i] == ' ')
				continue;
			if (ori[i] >= '0'&&ori[i] <= '9')
			{
				i=readint(i);
			}
			else
			{
				switch (ori[i])
				{
				case '+':case'-':
				{
					while (!f1.empty())
					{
						cur = f1.top();
						if (cur == '(')
							break;
						f1.pop();
						deal(cur);
					}
					f1.push(ori[i]);

					break;
				}
				case '*':case'/':
				{
					while (!f1.empty())
					{
						cur = f1.top();
						if (cur == '+' || cur == '-' || cur == '(')
							break;
						f1.pop();
						deal(cur);
					}
					f1.push(ori[i]);
					break;
				}
				case '(':case'^':
				{
					f1.push(ori[i]);
					break;
				}
				case ')':
				{
					while (!f1.empty())
					{
						cur = f1.top();
						f1.pop();
						if (cur == '(')
							break;
						deal(cur);
					}
					break;
				}
				}
			}
		}
		while (!f1.empty())
		{
			cur = f1.top();
			f1.pop();
			deal(cur);
		}
		
		cout << v1.top() << endl;
	}
	
}