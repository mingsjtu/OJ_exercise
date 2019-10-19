//https://www.nowcoder.com/practice/04c8a5ea209d41798d23b59f053fa4d6?tpId=40&tqId=21334&tPage=1&rp=1&ru=/ta/kaoyan&qru=/ta/kaoyan/question-ranking
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<math.h>
using namespace std;
int num;
const int maxn = 1000000005;
int arr[1005];
bool is[maxn];

void init()
{
	int i, j, k;
	memset(is, 0, sizeof(is));
	for (i = 2; i < sqrt(maxn)+1; i++)
	{
		//printf("test %d\n", i);
		if (is[i])
			continue;
		j = i;
		while (j < maxn)
		{
			j += i;
			is[j] = 1;
		}
	}
}
int compute(int x)
{
	int i, j, k;
	int ci = 0;
	long long sum = 1;
	while (x > 1)
	{
		//printf("test\n");
		int pre = x;
		for (i = 2; i <=sqrt(x)&&i<x; i++)
		{
			if (x%i == 0)
			{
				ci = 0;
				while (x%i == 0)
				{
					x /= i;
					ci++;
				}
				sum *= (ci+1);
				//printf("i %d ci %d\n", i,ci);
				break;
			}
		}
		if (pre==x)
		{
			sum *= 2;
			break;
		}
	}
	printf("%ld\n", sum);

	return 0;
}
int main()
{
	int i, j, k;
	//init();
	
	while (cin >> num)
	{
		for (i = 0; i < num; i++)
		{
			scanf("%d",&arr[i]);
			compute(arr[i]);
		}
	}
	return 0;
}