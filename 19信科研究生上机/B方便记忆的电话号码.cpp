//http://bailian.openjudge.cn/ss2019/B/
#include<iostream>
#include<cstring>
#include<map>
#include<algorithm>
#include<cstdio>
using namespace std;
int ci[100000];
map<int, int> m1;
int itr = 0;
int duiying(char c)
{
	if (c == 'A' || c == 'B' || c == 'C')
	{
		return 2;
	}
	if (c == 'D' || c == 'E' || c == 'F')
	{
		return 3;
	}
	if (c == 'G' || c == 'H' || c == 'I')
	{
		return 4;
	}
	if (c == 'J' || c == 'K' || c == 'L')
	{
		return 5;
	}
	if (c == 'M' || c == 'N' || c == 'O')
	{
		return 6;
	}
	if (c == 'P' || c == 'R' || c == 'S')
	{
		return 7;
	}
	if (c == 'T' || c == 'U' || c == 'V')
	{
		return 8;
	}
	if (c == 'W' || c == 'X' || c == 'Y')
	{
		return 9;
	}
}
char hao[200];
int shu;
struct hm
{
	int shu;
	int ci=0;

}hm1[100000];
bool cmp(hm h1, hm h2)
{
	if (h1.shu < h2.shu)
	{
		return true;
	}
	else
		return false;
}

void solve(char h[])
{
	int i;
	shu = 0;
	int len = strlen(h);
	int w = 1;
	for (i = len-1; i>=0; i--)
	{
		if (h[i] == '-')
			continue;
		else
		{
			if (h[i] >= '0' && h[i] <= '9')
				shu += w * (h[i] - '0');
			else
			{
				shu += w * duiying(h[i]);
			}
			w = w * 10;
		}
	}

	if (m1.find(shu) == m1.end())
	{
		m1[shu] = itr++;

	}
	else
	{
		ci[m1[shu]]++;
	}
}

int main()
{
	int n;
	int i, j, k;
	memset(ci, 0, sizeof(ci));
	cin >> n;
	for (i = 0; i < n; i++)
	{
		cin >> hao;
		solve(hao);
	}
	j = 0;
	map<int, int>::iterator it;
	int itr1=0;
	for (it = m1.begin(); it != m1.end(); it++)
	{
		if (ci[it->second] >= 1)
		{
			hm1[itr1].shu = it->first;
			hm1[itr1].ci = ci[it->second]+1;
			itr1++;
		}
	}
	if (itr1 == 0)
	{
		cout << "No duplicates.\n" << endl;
		return 0;
	}
	sort(hm1, hm1 + itr1, cmp);
	int tmp;
	for (i = 0; i < itr1; i++)
	{
		tmp = hm1[i].shu / 10000;
		printf("%3d-", tmp);
		tmp = hm1[i].shu % 10000;
		printf("%4d %d\n", tmp, hm1[i].ci);

	}
	
}