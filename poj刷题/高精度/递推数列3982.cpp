//http://poj.org/problem?id=3982
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int res[105][60];
int a[3];
int len[105];
void solve(int y, int x1, int x2, int x3)
{
	int tmp[60];//x1+x2
	int i, j, k;
	int tmp1;
	int jinwei = 0;
	int len1 = max(len[x1], len[x2]);
	memset(tmp, 0, sizeof(tmp));
	for (i = 0; i < len1; i++)
	{
		tmp1 = res[x1][i] + res[x2][i] + jinwei;
		jinwei = tmp1 / 10;
		tmp[i] = tmp1 % 10;
	}
	if (jinwei > 0)
	{
		len1++;
		tmp[len1 - 1] = jinwei;
	}
	int len2 = max(len1, len[x3]);
	jinwei = 0;
	for (i = 0; i < len2; i++)
	{
		//cout << "jinwei" << jinwei << endl;
		tmp1 = tmp[i] + res[x3][i] + jinwei;
		//cout << "tmpi " << tmp[i]<<"res x3 "<<res[x3][i]<< endl;
		jinwei = tmp1 / 10;
		res[y][i] = tmp1 % 10;
	}
	if (jinwei > 0)
	{
		len2++;
		res[y][len2 - 1] = jinwei;
	}
	len[y] = len2;
}
void display(int a)
{
	int i;
	for (i = len[a] - 1; i >= 0; i--)
		cout << res[a][i];
}
int main()
{
	while (scanf("%d %d %d", &a[0], &a[1], &a[2]) != EOF)
	{
		memset(res, 0, sizeof(res));
		int i, j, k;

		for (i = 0; i < 3; i++)
		{
			if (a[i] == 0)
			{
				res[i][0] = 0;
				len[i] = 1;
			}
			else
			{

				j = 0;
				while (a[i] > 0)
				{
					res[i][j++] = a[i] % 10;
					a[i] /= 10;
				}

				len[i] = j;
			}
		}


		//printf("len0 %d,len1 %d ,len2 %d\n", len[0], len[1], len[2]);

		for (i = 0; i < 97; i++)
		{
			solve(i + 3, i, i + 1, i + 2);
			//printf("at %d\n", i + 3);
			//display(i + 3);
			//cout << endl;
		}

		for (i = len[99] - 1; i >= 0; i--)
		{
			cout << res[99][i];
		}
		cout << endl;
	}
}

