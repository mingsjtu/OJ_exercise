//https://blog.csdn.net/da_kao_la/article/details/82354850
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int dig1[30];
int dig11[30];
char cdig1[30];

int dig2[30];
int dig22[30];
char cdig2[30];

int res[35];
int prime[35] = { 2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107,109,113,127,131,137,139,149 };
bool ispri(int x)
{
	int i;
	for (i = 2; i <= sqrt(x) + 1&&i<x; i++)
	{
		if (x%i == 0)
			return false;
	}
	return true;
}
int main()
{
	int i, j, k=0;
	while (1)
	{
		scanf("%s", cdig1);
		scanf("%s", cdig2);
		if (cdig1[0] == '0'&&cdig2[0] == '0')
			break;
		memset(res, 0, sizeof(res));
		memset(dig1, 0, sizeof(dig1));
		memset(dig2, 0, sizeof(dig2));
		memset(dig11, 0, sizeof(dig11));
		memset(dig22, 0, sizeof(dig22));

		int len1, len2, len;
		len1 = strlen(cdig1);
		//cout << "len1" << len1<< endl;
		k = 0;
		for (i = 0; i < len1; i++)
		{
			//cout << "find" << (len1 - i - 1) * 2 << endl;
			if (cdig1[i] != ',')
			{
				dig11[k] *= 10;
				dig11[k] += cdig1[i]-'0';
			}
			else
			{
				k++;
			}
			//cout << dig1[i];
		}
		len1 = k+1;
		for (i = 0; i <len1; i++)
		{
			dig1[i] = dig11[len1-1 - i];
			//cout << dig1[i];
		}
			
		//cout << endl;
		len2 = strlen(cdig2);
		k = 0;
		for (i = 0; i < len2; i++)
		{
			if (cdig2[i] != ',')
			{
				dig22[k] *= 10;
				dig22[k] += cdig2[i] - '0';
			}
			else
			{
				k++;
			}
		}
		len2 = k+1;
		for (i = 0; i <len2; i++)
		{
			dig2[i] = dig22[len2- i - 1];
			//cout << dig2[i];
		}
		//for (i = 0; i < k; i++)
		//	cout << dig2[i];
		//cout << endl;
		len = max(len1, len2);
		int tmp;
		int jinwei = 0;
		for (i = 0; i < len; i++)
		{
			//printf("jiashang %d ,%d\n", dig1[i], dig2[i]);
			tmp = dig1[i] + dig2[i] + jinwei;
			jinwei = tmp / prime[i];
			res[i] = tmp % prime[i];
		}
		while (jinwei > 0)
		{
			res[len++] = jinwei % prime[len];
			jinwei /= prime[len];
		}
		for (i = 0; i < len; i++)
		{
			cout << res[len - 1 - i];
			if (i != len - 1)
				cout << ',';
		}
		cout << endl;
	}
	

}