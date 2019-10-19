//https://www.nowcoder.com/practice/a5edebf0622045468436c74c3a34240f?tpId=40&tqId=21349&tPage=1&rp=1&ru=%2Fta%2Fkaoyan&qru=%2Fta%2Fkaoyan%2Fquestion-ranking
#include<iostream>
#include<string>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
int cal(int x)
{
	int i, j, k,res=0;
	while (x > 0)
	{
		res += x % 10;
		x /= 10;
	}
	return res;
}
int main()
{
	int x, y;
	while (cin >> x >> y)
	{
		int n1 = cal(x);
		int n2 = cal(y);
		cout << n1 * n2 << endl;
	}
}