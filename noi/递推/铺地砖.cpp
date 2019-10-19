//http://noi.openjudge.cn/ch0202/9273/
#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;

struct ll
{
	int shu[100];
	int wei;
	
	void display()
	{
		int i;
		for (i = wei-1; i>=0; i--)
		{
			cout <<shu[i];
		}
	}
}dp[260];
ll plus1(const ll a,const ll b)
{
	int i, tmp, carry = 0;
	ll res;
	res.wei = a.wei > b.wei ? a.wei : b.wei;
	for (i = 0; i < res.wei; i++)
	{
		tmp = a.shu[i] + b.shu[i] + carry;
		res.shu[i] = tmp % 10;
		carry = tmp / 10;
	}
	if (carry > 0)
	{
		res.wei++;
		res.shu[res.wei - 1] = carry;
	}
	return res;

}
int main()
{
	int i = 0;
	dp[0].wei = 1;
	dp[0].shu[0] = 0;
	dp[1].shu[0] = 1;
	dp[1].wei = 1;
	dp[2].wei = 1;
	dp[2].shu[0] = 3;
	ll t;
	for (i = 3; i < 260; i++)
	{
		t = plus1(dp[i - 2], dp[i - 2]);
		dp[i] = plus1(dp[i - 1],t);
	}

	int tmp;
	while (cin >> tmp)
	{
		if (!tmp)
			cout << 1 << endl;
		else {
			dp[tmp].display();
			cout << endl;
		}
	}
	
	
 }