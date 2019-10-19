//https://www.nowcoder.com/practice/9324a1458c564c4b9c4bfc3867a2aa66?tpId=40&tqId=21347&tPage=1&rp=2&ru=%2Fta%2Fkaoyan&qru=%2Fta%2Fkaoyan%2Fquestion-ranking
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
int x, y, K;
int root(int x, int k)
{
	if (x < k)
		return x;
	int i, j;
	int sum = 0;
	while (x >= k)
	{
		//cout << x << endl;
		sum = 0;
		while (x > 0)
		{
			sum += x % 10;
			x /= 10;
		}
		x = sum;
	}
	
	return x;
}
int zhishu(int x, int y)
{
	int a = x;
	int res = 0;
	if (y == 1)
		return root(x, K);
	if (y % 2 == 1)
		return zhishu(zhishu(x, y / 2)*zhishu(x, y / 2)*zhishu(x, 1), 1);
	else
		return zhishu(zhishu(x, y / 2)*zhishu(x, y / 2), 1);

}

int main()
{
	int i, j, k;
	while (cin >> x >> y >> K)
	{
		x = root(x, K);
		//cout <<"x "<< x << endl;
		cout << zhishu(x, y) << endl;
		//cout << cal(x, y, K) << endl;
	}
}