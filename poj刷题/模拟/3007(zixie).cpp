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
string s, s1, s2, ss1, ss2, res;
vector<string> m[bigp];
bool solve(string s,int l)
{
	int i, j, k,key=0;
	for (i = 0; i < l; i++)
	{
		key += (s[i] - 'a')*(i+1);
	}
	key %= bigp;
	bool flag = false;
	for (i = 0; i < m[key].size(); i++)
	{
		if (m[key][i] == s)
		{
			return true;
		}
	}
	if (!flag)
	{
		m[key].push_back(s);
		return false;
	}
}
int main()
{
	int n, i, j, k, len;
	cin >> n;
	int key;
	while (n--)
	{
		cin >> s;
		int len = s.length();
		
		int index = 1;
		solve(s,len);
		len = s.length();
		for (i = 1; i <= len - 1; i++)
		{
			s1 = s.substr(0, i);
			s2 = s.substr(i, len - 1);
			//cout << s1 << endl<<s2 << endl;
			ss1 = s1;
			reverse(ss1.begin(), ss1.end());
			ss2 = s2;
			reverse(ss2.begin(), ss2.end());
			
			
			bool flag1 = (ss1 == s1), flag2 = (s2 == ss2);
			if (!flag1&&flag2)
			{
				res = ss1 + s2;
				if (!solve(res,len))
					index++;
			}
			if (flag1 && !flag2)
			{
				res = s1 + ss2;
				if (!solve(res, len))
					index++;
			}
			if (!flag1 && !flag2)
			{
				res = ss1 + s2;
				if (!solve(res, len))
					index++;
				res = s1 + ss2;
				if (!solve(res, len))
					index++;
				res = ss1 + ss2;
				if (!solve(res, len))
					index++;
			}
		}
		reverse(s.begin(), s.end());
		if (!solve(s, len))
			index++;
		for (i = 1; i <= len - 1; i++)
		{
			s1 = s.substr(0, i);
			s2 = s.substr(i, len - 1);
			//cout << s1 << endl<<s2 << endl;
			ss1 = s1;
			reverse(ss1.begin(), ss1.end());
			ss2 = s2;
			reverse(ss2.begin(), ss2.end());
			bool flag1 = (ss1 == s1), flag2 = (s2 == ss2);
			if (!flag1&&flag2)
			{
				res = ss1 + s2;
				if (!solve(res, len))
					index++;
			}
			if (flag1 && !flag2)
			{
				res = s1 + ss2;
				if (!solve(res, len))
					index++;
			}
			if (!flag1 && !flag2)
			{
				res = ss1 + s2;
				if (!solve(res, len))
					index++;
				res = s1 + ss2;
				if (!solve(res, len))
					index++;
				res = ss1 + ss2;
				if (!solve(res, len))
					index++;
			}
		}
		printf("%d\n", index);
	}
}