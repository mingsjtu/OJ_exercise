//https://blog.csdn.net/da_kao_la/article/details/82429824
#include<iostream>
#include<cstdio>
#include<cstring>
#include<stack>
using namespace std;
int n,des,tmp;
int shu[11];
bool zhaodao = false;
int dfs(int d,int res,int jie)
{
	if (d == n)
	{
		cout << res << endl;
		
		if (res == des)
		{
			
			zhaodao = true;
			return jie;
		}
		else
		{
			if (res > des && res < tmp)
			{
				tmp = res;
			}
			return -1;
		}

	}
	int ans0 = dfs(d + 1, res + shu[d], (jie << 1) + 0);
	int ans1 = dfs(d + 1, res * shu[d], (jie << 1) + 1);
	if (ans0 == -1 && ans1 == -1)
		return -1;
	else
	{
		return (ans0 > ans1)? ans0 : ans1;
	}
}
int main()
{
	cin >> n>>des;
	int i, j;
	for (i = 0; i < n; i++)
	{
		cin >> shu[i];
	}
	int jie=dfs(0,0,0);
	cout << "jie" << jie << endl;
	stack<int> s;
	for (i = 0; i < n-1; i++)
	{
		cout << shu[i];
		if (jie&(1 << (n - 2 - i)))
		{
			cout << '*';
		}
		else
		{
			cout << '+';
		}
	}
	cout << shu[n - 1] << endl;
}