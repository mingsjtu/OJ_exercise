//http://poj.org/problem?id=2109
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<math.h>
using namespace std;
int main()
{
	double a1, n;
	while (cin >> n >> a1)
	{
		cout << pow(a1, 1 / n)<<endl;
	}
}