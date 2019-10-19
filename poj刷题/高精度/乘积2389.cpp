//http://poj.org/problem?id=2389
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
using namespace std;
char ac[50];
char bc[50];
int a[50];
int b[50];
int res[100];

int main()
{
	scanf("%s", ac);
	scanf("%s", bc);
	int len1 = strlen(ac);
	int len2 = strlen(bc);
	int i, j, k;
	for (i = 0; i < len1; i++)
	{
		a[i] = ac[len1 - i - 1] - '0';
	}
	for (i = 0; i < len2; i++)
	{
		b[i] = bc[len2 - i - 1] - '0';
	}
	int tmp, jinwei=0;
	memset(res, 0, sizeof(res));
	for (i = 0; i < len1; i++)
	{
		for (j = 0; j < len2; j++)
		{
			tmp = a[i] * b[j];
			res[i+j+1]+=tmp / 10;
			res[i+j] += tmp % 10;
			//printf("i %d j %d tmp %d \n", i, j, tmp);
		}
	}
	int len;
	//cout << res[len1 + len2 - 1] <<  endl;
	if (res[len1 + len2 - 1] == 0)
	{
		len = len1 + len2 - 2;
	}
	else
		len = len1 + len2 - 1;
	jinwei = 0;
	for (i = 0; i <= len; i++)
	{
		int tmp = res[i]+jinwei;
		res[i] = tmp % 10;
		jinwei = tmp / 10;
	}
	while(jinwei > 0)
	{
		len++;
		res[len] = jinwei%10;
		jinwei /= 10;
	}
	for (i = len; i >= 0; i--)
		cout << res[i];

}