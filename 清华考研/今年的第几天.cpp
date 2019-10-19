//https://www.nowcoder.com/practice/ae7e58fe24b14d1386e13e7d70eaf04d?tpId=40&tqId=21350&tPage=1&rp=1&ru=%2Fta%2Fkaoyan&qru=%2Fta%2Fkaoyan%2Fquestion-ranking
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
int mday1[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
int mday2[12] = { 31,29,31,30,31,30,31,31,30,31,30,31 };
int y, m, d;
int isrun(int x)
{
	if (x % 4 == 0 && x % 100 != 0)
		return true;
	if (x % 400 == 0)
		return true;
	return false;
}
int cal1(int m,int d)
{
	int i, j, k, res = 0;
	for (i = 0; i < m - 1; i++)
	{
		res += mday1[i];
	}
	res += d;
	return res;
}
int cal2(int m, int d)
{
	int i, j, k, res = 0;
	for (i = 0; i < m - 1; i++)
	{
		res += mday2[i];
	}
	res += d;
	return res;
}
int main()
{
	while (cin >> y >> m >> d)
	{
		if (isrun(y))
		{
			cout<<cal2(m, d)<<endl;
		}
		else cout << cal1(m, d) << endl;
	}
}