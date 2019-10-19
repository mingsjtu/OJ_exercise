//http://poj.org/problem?id=1002
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<map>
#include<algorithm>
using namespace std;
int n;
string s[100005];
string tmp;
map<string, int> dic;
map<string, int> geshu;
//char s1[8];
string s1="00000000";
int duiying(char c)
{
	int res;
	switch (c)
	{
	case 'A':
	case 'B':
	case 'C':
		res=2;
		break;
	case 'D':
	case 'E':
	case 'F':
		res = 3;
		break;
	case 'G':
	case 'H':
	case 'I':
		res = 4;
		break;
	case 'J':
	case 'K':
	case 'L':
		res = 5;
		break;
	case 'M':
	case 'N':
	case 'O':
		res = 6;
		break;
	case 'P':
	case 'R':
	case 'S':
		res = 7;
		break;
	case 'T':
	case 'U':
	case 'V':
		res = 8;
		break;
	case 'W':
	case 'X':
	case 'Y':
		res = 9;
		break;
	}
	return res;
}
void solve(string x)
{
	int i, j, k, len = x.length();
	j = 0;
	for (i = 0; i < len; i++)
	{
		//("i %d ;", i);
		if (x[i] >= 'A'&&x[i] <= 'Z')
		{
			s1[j]=duiying(tmp[i])+'0';
				j++;
		}
		if (x[i] >= '0'&&x[i] <= '9')
		{
			s1[j]=tmp[i];
			//printf("s1 %c", s1[j]);

				j++;
		}
	}
	s1[j] = '\0';
}
int main()
{
	cin >> n;
	int i, j, k,cnt=0;
	//map<string, int> m1;
	for (i = 0; i < n; i++)
	{
		cin >> tmp;
		solve(tmp);
		//cout << s1 << endl;
		//printf("%s\n", s1);
		if (dic.find(s1) == dic.end())
		{
			s[cnt] = s1;
			//cnt++;
			dic[s1] = cnt++;
			geshu[s1] = 1;
		}
		else
		{
			geshu[s1]++;
		}
	}
	//printf("cnt %d\n", cnt);
	sort(s, s + cnt);
	bool flag = false;
	for (i = 0; i < cnt; i++)
	{
		int ge = geshu[s[i]];
		if ( ge== 1)
			continue;
		tmp = s[i];
		tmp.insert(tmp.begin() + 3,'-');
		cout << tmp;
		flag = true;
		printf(" %d\n",geshu[s[i]]);
	}
	if (!flag)
		printf("No duplicates.\n");
}