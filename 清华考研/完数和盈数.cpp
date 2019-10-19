//https://www.nowcoder.com/practice/ccc3d1e78014486fb7eed3c50e05c99d?tpId=40&tqId=21351&tPage=1&rp=1&ru=%2Fta%2Fkaoyan&qru=%2Fta%2Fkaoyan%2Fquestion-ranking
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<math.h>
using namespace std;
bool wan[65], ying[65];
int cal(int x)
{
	int i, j, k;
	int res = 1;
	//printf("cal %d\n", x);
	int old = x;
	for (i = 2; i <old; i++)
	{
		int k = 0;
		if (x%i == 0)
		{
			while (x%i == 0)
			{
				x /= i;
				k++;
			}
			//printf("i %d ^ k %d\n", i, k);
			res *= (pow(i, k+1)-1)/(i-1);
		}
	}
	if (x == old)
		return 1 + old;
	return res;
}
int main()
{
	int i, j, k;
	memset(wan, 0, sizeof(wan));
	memset(ying, 0, sizeof(ying));
	for (i = 2; i <= 60; i++)
	{
		//cout <<i<<' '<< cal(i)-i << endl;
		
		if (cal(i) == (i<<1))
			wan[i] = 1;
		else if (cal(i) > (i<<1))
			ying[i] = 1;
	}
	printf("E: ");
	for (i = 2; i <= 60; i++)
	{
		if(wan[i]==1)
		printf("%d ",i);
	}
	printf("\n");
	printf("G: ");
	for (i = 2; i <= 60; i++)
	{
		if(ying[i])
		printf("%d ",i);
	}
	printf("\n");
}