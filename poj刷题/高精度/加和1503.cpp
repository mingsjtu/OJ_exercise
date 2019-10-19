//http://poj.org/problem?id=1503
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
short cur[105];
short res[110];
char curc[105];
char resc[105];
int main()
{
	
	scanf("%s", resc);
	int len1 = strlen(resc);
	int i, j, k;
	for (i = 0; i < len1; i++)
	{
		res[i] = resc[len1-1-i] - '0';
	}
	while (scanf("%s", curc))
	{
		if (strcmp(curc ,"0")==0)
		{
			break;
		}
		int jinwei = 0;
		int len2 = strlen(curc);
		int tmp;
		for (i = 0; i < len2; i++)
		{
			cur[i] = curc[len2-1-i] - '0';
			tmp = cur[i] + res[i]+jinwei;
			jinwei = tmp / 10;
			res[i] = tmp % 10;
		}
		if (jinwei > 0)
		{
			for (i = len2; i < len1; i++)
			{
				tmp = res[i] + jinwei;
				jinwei=tmp / 10;
				res[i] = tmp % 10;
				if (jinwei == 0)
					break;
			}
			if (jinwei > 0)
			{
				res[len1] = jinwei;
				len1++;

			}
		}
	}
	for (i = len1-1; i>=0; i--)
		cout << res[i];
	cout << endl;
}