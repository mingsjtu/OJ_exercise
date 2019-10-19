//http://poj.org/problem?id=3007
#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
#include<cstdio>
#include<map>
#include<stack>
#include<vector>
using namespace std;
const int bigp = 65535;
string s,s1,s2,ss1,ss2,res;
vector<string> m[bigp];
int main()
{
	int n, i, j, k,len;
	cin >> n;
	while (n--)
	{
		cin >> s;
		map<string, int> m1;
		if (!m1.empty())
			m1.clear();
		int index = 0;
		len = s.length();
		for (i = 1; i <=len - 1; i++)
		{
			s1 = s.substr(0, i);
			s2 = s.substr(i, len-1);
			//cout << s1 << endl<<s2 << endl;
			ss1 = s1;
			reverse(ss1.begin(), ss1.end());
			ss2 = s2;
			reverse(ss2.begin(), ss2.end());
			res = s1+s2;
			if (m1.find(res) == m1.end())
			{
				m1[res] == index++;
			}
			bool flag1 = (ss1 == s1),flag2=(s2==ss2);
			if(!flag1&&flag2)
			{
				res = ss1 + s2;
				if (m1.find(res) == m1.end())
				{
					m1[res] == index++;
				}
			}
			if (flag1&&!flag2)
			{
				res = s1 + ss2;
				if (m1.find(res) == m1.end())
				{
					m1[res] == index++;
				}
			}
			if (!flag1&&!flag2)
			{
				res = ss1 + s2;
				if (m1.find(res) == m1.end())
				{
					m1[res] == index++;
				}
				res = s1 + ss2;
				if (m1.find(res) == m1.end())
				{
					m1[res] == index++;
				}
				res = ss1 + ss2;
				if (m1.find(res) == m1.end())
				{
					m1[res] == index++;
				}
			}
		}
		reverse(s.begin(), s.end());
		for (i = 1; i <= len - 1; i++)
		{
			s1 = s.substr(0, i);
			s2 = s.substr(i, len - 1);
			//cout << s1 << endl<<s2 << endl;
			ss1 = s1;
			reverse(ss1.begin(), ss1.end());
			ss2 = s2;
			reverse(ss2.begin(), ss2.end());
			res = s1 + s2;
			if (m1.find(res) == m1.end())
			{
				m1[res] == index++;
			}
			bool flag1 = (ss1 == s1), flag2 = (s2 == ss2);
			if (!flag1&&flag2)
			{
				res = ss1 + s2;
				if (m1.find(res) == m1.end())
				{
					m1[res] == index++;
				}
			}
			if (flag1 && !flag2)
			{
				res = s1 + ss2;
				if (m1.find(res) == m1.end())
				{
					m1[res] == index++;
				}
			}
			if (!flag1 && !flag2)
			{
				res = ss1 + s2;
				if (m1.find(res) == m1.end())
				{
					m1[res] == index++;
				}
				res = s1 + ss2;
				if (m1.find(res) == m1.end())
				{
					m1[res] == index++;
				}
				res = ss1 + ss2;
				if (m1.find(res) == m1.end())
				{
					m1[res] == index++;
				}
			}
		}
		printf("%d\n",index);
	}
}