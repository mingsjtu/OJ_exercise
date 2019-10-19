//http://poj.org/problem?id=3087
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<deque>
#include<map>
using namespace std;
string s1,s2;
string res,cur;
int t, l;
map<string, int> m1;
void get()
{
	int i,j,k;
	for (i = 0; i < l; i++)
	{
		cur[2 * i] = s2[i];
		cur[2 * i + 1] = s1[i];
	}
}
void change()
{

}
int main()
{
	int i, j, k;
	int bu = 0;
	while (t--)
	{
		bu = 0;
		bool flag = false;
		cin >> l;
		for (i = 0; i < l; i++)
		{
			cin >> s1[i];
		}
		for (i = 0; i < l; i++)
		{
			cin >> s2[i];
		}
		for (i = 0; i < 2*l; i++)
		{
			cin >> res[i];
		}
		while (1)
		{
			get();
			if (cur == 0)
			{
				flag = true;
				break;
			}
			if()
			bu++;
			change();
		}
	}
}