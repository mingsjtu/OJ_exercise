//https://www.nowcoder.com/practice/97be22ee50b14cccad2787998ca628c8?tpId=40&tqId=21348&tPage=1&rp=1&ru=%2Fta%2Fkaoyan&qru=%2Fta%2Fkaoyan%2Fquestion-ranking
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
struct big
{
	int wei;
	int dig[10000];
}tmp;// b1[1005];
void display(big b)
{
	int i, j, k;
	for (i =b.wei-1; i>=0; i--)
	{
		cout << b.dig[i];
	}
	cout << endl;
}
big fun(big b2, int x)
{
	big b3;
	b3.dig[0] = 0;
	b3.wei = b2.wei;
	int jin = 0;
	int i, j, k, tmp;
	for (i = 0; i < b2.wei; i++)
	{
		tmp = b2.dig[i] * x+jin;
		jin = tmp / 10;
		b3.dig[i] = tmp % 10;
	}
	if (jin > 0)
	{
		b3.wei++;
		b3.dig[i] = jin;
	}
	return b3;
}
int main()
{
	int i, j, k;
	//b1[0].wei = 1;
	//b1[0].dig[0] = 1;
	//big tmp;// = b1[0];
	//for (i = 1; i <= 1000; i++)
	//{
	//	b1[i] = fun(b1[i - 1] , i);
	//	//tmp = fun(tmp, i);
	//}
	int x;
	//for (i = 1; i <= 20; i++)
		//display(b1[i]);
	while (cin >> x)
	{
		tmp.wei = 1;
		tmp.dig[0] = 1;
		for (i = 1; i <= x; i++)
		{
			//b1[i] = fun(b1[i - 1] , i);
			tmp = fun(tmp, i);
		}
		display(tmp);
	}
}