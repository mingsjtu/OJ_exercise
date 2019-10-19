//https://www.nowcoder.com/practice/0177394fb25b42b48657bc2b1c6f9fcc?tpId=40&tqId=21360&tPage=2&rp=2&ru=/ta/kaoyan&qru=/ta/kaoyan/question-ranking
#include<iostream>
#include<cstring>
#include<cstdio>
#include<string>
using namespace std;
int a[205];
int d[205];
int n, m;
int main()
{
	int i,j,k;
	while (cin >> n >> m)
	{
		memset(d, 0, sizeof(d));
		for (i = 0; i < n; i++)
		{
			cin >> a[i];
			d[a[i]]++;
		}
		for (i = 0; i < n; i++)
		{
			if (d[a[i]] == 1)
				cout << "BeiJu\n";
			else
				cout << d[a[i]] - 1 << endl;
		}
	}

}