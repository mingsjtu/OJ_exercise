//http://poj.org/problem?id=2151
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int m, t, n;
double p[1010][35];
double dui1[35];
double dui11[35];
int main()
{
	
	int i, j, k;
	while (cin >> m >> t >> n)
	{
		memset(p, 0, sizeof(p));
		for (i = 0; i < t; i++)
		{
			for (j = 0; j < m; j++)
			{
				cin >> p[i][j];
			}
		}
		double tmp = 1, zong1 = 1;
		for (i = 0; i < m; i++)
		{
			for (j = 0; j < t; j++)
			{
				tmp *= (1 - p[i][j]);
			}
			dui1[i] = 1 - tmp;
			printf("dui1[i] %lf\n", dui1[i]);
			zong1 *= dui1[i];
		}
		printf("zong1 %lf\n", zong1);
		double res = 0;
		tmp = 0;
		bool flag = false;
		for (i = 0; i < m; i++)
		{
			for (j = 0; j < t; j++)
			{
				if (p[i][j] == 0&&flag==false)
				{
					tmp = dui1[i];
					flag = true;
					res = max((dui1[i] - dui11[i]) / dui1[i] * zong1, res);
				}
				if (p[i][j] == 0 && flag == true)
				{
					tmp = dui1[i];
					flag = true;
					res = max((dui1[i] - dui11[i]) / dui1[i] * zong1, res);
				}
				tmp += p[i][j] / (1 - p[i][j]);
			}
			printf("tmp %lf\n", tmp);
			dui11[i] = tmp*(1- dui1[i]);
			printf("dui11 %lf\n",dui1[i]-dui11[i]);

			res = max((dui1[i]-dui11[i])/dui1[i] * zong1 , res);
		}
		printf("%.3f\n", res);
	}
	
}