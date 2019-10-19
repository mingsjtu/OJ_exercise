//《王道》172页，素数环问题
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<math.h>
using namespace std;

bool mark[25];//biaoji shifouyongguo
int arr[25];//zhaodaode sushuxulie
int n;
bool isprime(int n)
{
	int en = sqrt(n);
	for (int i = 2; i <= en + 1; i++)
	{
		if (n%i == 0)
			return false;
	}
	return true;
}
void check()
{
	if (isprime(arr[1] + arr[n]))
	{
		for (int i = 1; i <= n; i++)
			cout << arr[i] << ' ';
	}
	cout << endl;
}
void dfs(int con)//dangqian
{
	
	//cout << con;
	if (con == n)
		return check();
	int i = 0;
	for (i = 2; i <=n; i++)
	{
		
		if (mark[i] == false)
		{
			if (isprime(arr[con] + i))
			{
				arr[con + 1] = i;
				mark[i] = true;
				dfs(con + 1);
				mark[i] = false;
			}
		}

			
	}
}
int main()
{
	int cishu = 1;
	while (cin >> n)
	{
		cout << "Case " << cishu <<";"<< endl;
		mark[1] = true;
		arr[1] = 1;
		dfs(1);
	}
}