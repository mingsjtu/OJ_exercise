//https://blog.csdn.net/da_kao_la/article/details/82416299
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
int shu1[10000005];
int shu2[10000005];
int shu3[10000005];
char str[10000005];
int main()
{
	while (scanf("%s", str) != EOF)
	{
		memset(shu1, 0, sizeof(shu1));
		memset(shu2, 0, sizeof(shu2));
		memset(shu3, 0, sizeof(shu3));

		int len1 = strlen(str);
		int i, j, k;
		for (i = 0; i < len1; i++)
		{
			shu1[i] = str[len1 - i - 1] - '0';
		}
		int tmp;
		for (i = 0; i < len1; i++)
		{
			for (j = 0; j < len1; j++)
			{
				tmp = shu1[i] * shu1[j];
				shu2[i + j + 1] += (shu2[i + j] + tmp) / 10;
				shu2[i + j] = (shu2[i + j] + tmp) % 10;
				//printf("zhongjian %d\n", tmp);
			}
		}
		int len2 = len1 + len1;
		if (shu2[len2 - 1] > 10)
		{
			shu2[len2] = shu2[len2 - 1] / 10;
			shu2[len2 - 1] %= 10;
			len2++;
		}
		while (shu2[len2] == 0)
			len2--;
		len2++;

		for (i = 0; i < len2; i++)
		{
			for (j = 0; j < len1; j++)
			{
				tmp = shu2[i] * shu1[j];
				shu3[i + j + 1] += (shu3[i + j] + tmp) / 10;
				shu3[i + j] = (shu3[i + j] + tmp) % 10;
			}
		}
		int len3 = len2 + len1;
		if (shu3[len3 - 1] > 10)
		{
			shu3[len3] = shu3[len3 - 1] / 10;
			shu3[len3 - 1] %= 10;
			len3++;
		}
		while (shu3[len3] == 0)
			len3--;
		len3++;
		for (i = 0; i < len3; i++)
			cout << shu3[len3 - i - 1];
		cout << endl;
	}
	}
	