//https://www.nowcoder.com/practice/fd972d5d5cf04dd4bb4e5f027d4fc11e?tpId=40&tqId=21357&tPage=2&rp=2&ru=%2Fta%2Fkaoyan&qru=%2Fta%2Fkaoyan%2Fquestion-ranking
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
using namespace std;

//const bool dui[10][4] = { {0,0,0,0},{0,0,0,1},{0,0,1,0},{0,0,1,1},{0,1,0,0},{0,1,0,1},{0,1,1,0},{0,1,1,1},{1,0,0,0},{1,0,0,1} };
string zhuan(int n, string a, int m)
{
	int len = a.length();
	string b;
	int i, j, k;
	int tmp, jin = 0;
	int t;
	for (i = 0; i < len;)
	{
		//cout << i << endl;
		jin = 0;
		for (j = i; j < len; j++)
		{
			
			tmp = jin * n + a[j] - '0';
			jin = tmp % m;
			a[j] = tmp / m+'0';
		}
		//cout << a << endl;
		b += jin + '0';
		while (a[i] == '0')
			i++;
	}
	return b;
}
int main()
{
	string yuan, xin1,zhong;

	while (cin>>yuan)
	{
		zhong = zhuan(10, yuan, 2);
		//cout << zhong << endl;
		xin1 = zhuan(2, zhong, 10);
		reverse(xin1.begin(), xin1.end());
		cout << xin1 << endl;
	}
}