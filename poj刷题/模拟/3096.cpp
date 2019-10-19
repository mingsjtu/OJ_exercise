//http://poj.org/problem?id=3096
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
char s[80];
int main()
{
	int i, j, k;
	int len;
	while (scanf("%s", s))
	{
		if (s[0] == '*')
			return 0;
		len = strlen(s);
		bool flag = true;
		for (i = 1; i <= len&&flag; i++)
		{
			map<string, int> m1;
			if (!m1.empty())
			{
				m1.clear();
			}
			string tmp="aa";
			int index = 0;
			for (j = 0; j < len - i; j++)
			{
				tmp[0] = s[j];
				tmp[1]=s[j + i];
				//tmp[2] = '\0';
				//cout << tmp << endl;
				if (m1.find(tmp) == m1.end())
				{
					m1[tmp] = index++;
				}
				else
				{
					flag = false;
					break;
				}
			}
		}
		if (flag)
		{
			printf("%s is surprising.\n", s);
		}
		else
		{
			printf("%s is NOT surprising.\n", s);
		}
	}
}