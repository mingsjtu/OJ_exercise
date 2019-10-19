//https://www.nowcoder.com/practice/0337e32b1e5543a19fa380e36d9343d7?tpId=40&tqId=21361&tPage=2&rp=2&ru=%2Fta%2Fkaoyan&qru=%2Fta%2Fkaoyan%2Fquestion-ranking
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
using namespace std;
string from, to;
string converse(string a, int n, int m)
{
	int i, j, k;
	string b;
	int jin = 0;
	int len = a.length();
	for (i = 0; i < len;)
	{
		jin = 0;
		for (j = i; j < len; j++)
		{
			int tmp = jin * n + a[j]-'0';
			a[j] = tmp / m+'0';
			jin = tmp % m;
		}
		//cout << a << endl;
		b += '0' + jin;
		while (a[i] == '0')
			i++;
		//cout <<"i "<<i << endl;
	}
	return b;
}
int main()
{
	while (cin >> from)
	{
		to = converse(from, 10, 2);
		reverse(to.begin(),to.end());
		cout << to<<endl;
	}
}