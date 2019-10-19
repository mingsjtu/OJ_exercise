#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<stdio.h>
//#include<pch.>


#include<list>
#include<stack>

using namespace std;
int main()
{
	char s[100005];
	int a[26];
	int res[26];
	int tmp = 1,co=100011;
	char r='#';
	
	while (cin.getline(s,100005))
	{
		memset(a, 0, sizeof(a));
		memset(res, 0, sizeof(res));
		for (int i = 0; s[i] != '\0'; i++)
		{
			a[s[i] - 'a']++;
			if (a[s[i] - 'a'] > 1)
				res[s[i] - 'a'] = 0;
			else if(a[s[i] - 'a']==1)
			{
				res[s[i] - 'a'] = tmp;
				tmp++;
			}
		}
		int i = 0;
		for (i = 0; i < 26; i++)
		{
			if (!res[i])
				continue;
			if (co > res[i])
			{
				co = res[i];
				r = i+'a';
			}
		}
		if (r == '#')
			cout << "no";
		else
		cout << r;
		return 0;
		
	}
}