//https://blog.csdn.net/da_kao_la/article/details/82460671
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int n, m;//diyihang,hou m hang
int dig[50005],dao[50005];
int find(int a, int b,int sta,int en)
{
	int tmp1, tmp2;
	if (dao[sta] < a)
		return dig[0] -a- b;
	if (dao[en] > a)
		return dig[n - 1] -a*n- b;
	if (sta == en)
	{
		tmp1 = dig[sta] - a * (sta+1) - b;
		tmp2 = dig[sta - 1] - a * (sta+1) + a - b;
		cout << "zhaodao" << sta<<endl;
		return (tmp1>tmp2)?tmp1:tmp2;
	}
	int middle = (sta + en) / 2;
	if (dao[middle] < a)
		find(a, b, sta, middle);
	else 
	{
	if(dao[middle]==a)
	{
		tmp1 = dig[middle] - a * (middle +1) - b;
		tmp2 = dig[middle - 1] - a * (middle + 1) + a - b;
		cout << "zhaodao" << middle << endl;
		return (tmp1 > tmp2) ? tmp1 : tmp2;
	}
	else
		find(a, b, middle, en);
	}
}
int main()
{
	cin >> n >> m;
	int i, j, k;
	for (i = 0; i < n; i++)
	{
		cin >> dig[i];
		if(i>0)
		dao[i] = dig[i] - dig[i - 1];
	}
	dao[0] = 0x7ffff;

	int a, b;
	for (i = 0; i < m; i++)
	{
		cin >> a >> b;
		cout<<find(a,b,0,n-1)<<endl;
	}
}