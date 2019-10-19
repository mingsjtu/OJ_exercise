//http://poj.org/problem?id=1039
#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;
int x[22], y[22];
int n;
double k11[22], k12[22];
double k21[22], k22[22];
double test(int t)
{
	int i=1,j, k;
	while (k11[t] <= k11[i] && k11[t] > k12[i])
	{
		i++;
	}
	i -= 1;
	double k1 = double(y[i + 1] - y[i]) / double(x[i + 1] - x[i]);

}
int main()
{
	int i, j, k;
	
	for (i = 0; i < n; i++)
	{
		cin >> x[i] >> y[i];
		if (i != 0)
		{
			k11[i] = double(y[i] - y[0]) / double(x[i] - x[0]);
			//k11[i] = min(double(y[i] - y[0]) / double(x[i] - x[0]),k11[i-1]);
			//k12[i] = max(double(y[i] - y[0] - 1) / double(x[i] - x[0]), k12[i - 1]);
			k12[i] = double(y[i] - y[0] - 1) / double(x[i] - x[0]);
			k21[i] = double(y[i] - y[0] + 1) / double(x[i] - x[0]);
			//k21[i] = min(double(y[i] - y[0] + 1) / double(x[i] - x[0]),k21[i-1]);
			k22[i] = k11[i];
		}
	}
	for (i = 1; i < n - 1; i++)
	{
		test(i);
	}
}