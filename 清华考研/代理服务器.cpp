////https://www.nowcoder.com/practice/1284469ee94a4762848816a42281a9e0?tpId=40&tqId=21335&tPage=1&rp=1&ru=%2Fta%2Fkaoyan&qru=%2Fta%2Fkaoyan%2Fquestion-ranking
#include<iostream>
#include<cstring>
#include<cstdio>
#include<string>
#include<map>
#include<ctime>
using namespace std;

map<string, int> m1;
int n, m;
char name[20];
int tar[5005];
bool use[1005];
int ptr = 0;

int myfind(int sta, int no)
{
	int i, j, k;
	int num = 1;
	memset(use, 0, sizeof(use));
	use[no] = 1;
	int xuan = -1;
	ptr = sta + 1;
	for (i = sta + 1; i < m; i++)
	{
		if (tar[i] != 0)
		{
			if (use[tar[i]] == 1 || tar[i] == no)
				continue;
			xuan = tar[sta];
			use[tar[i]] = 1;
			num++;
			if (num == n)
			{
				ptr = i;
				return tar[i];
			}
		}
	}
	return -1;
}
void solve()
{
	ptr = 0;
	memset(use, 0, sizeof(use));
	int biao = 0;
	int last = 0;
	int pie = 0;
	while (ptr < m&&biao < n)
	{
		if (tar[ptr] != 0)
		{
			if (use[tar[ptr]] == 0)
			{
				use[tar[ptr]] = 1;
				last = tar[ptr];
				biao++;
			}
		}
		ptr++;

		if (biao == n)
		{
			pie++;
			break;
		}
	}
	//cout << last << " " << ptr << endl;
	if (ptr == m)
	{
		cout << 0 << endl;
		return;

	}
	ptr--;
	while (1)
	{
		//cout<<last<<" "<<ptr<<endl;
		last = myfind(ptr, last);
		if (last == -1)
		{
			break;
		}
		pie++;
	}
	cout << pie << endl;
}

int main()
{
	int i, j, k;

	while (cin>>n)
	{
		bool flag = true;
		ptr = 0;
		int index = 1;
		for (i = 0; i < n; i++)
		{
			scanf("%s", name);
			m1[name] = index++;
			
		}
		cin >> m;
		for (i = 0; i < m; i++)
		{
			scanf("%s", name);
			if (m1.find(name) == m1.end())
			{
				tar[i] = 0;
			}
			else
			{
				if (n == 1)
				{
					flag = false;
				}
				tar[i] = m1[name];
			}
		}
		if (flag)
			solve();
		else
		{
			for (i = 0; i < m; i++)
			{
				if (tar[i] != 0)
				{
					cout << -1 << endl;
					break;
				}
			}
			if (i == m)
				cout << 0 << endl;
		}
	}
}