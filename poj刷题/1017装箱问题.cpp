//http://poj.org/problem?id=1017
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
int shu[7];
int give[3];
int main()
{
	int i, j, k;
	int res = 0;
	bool flag = true;
	while (1)
	{
		flag = true;
		memset(give, 0, sizeof(give));
		res = 0;
		for (i = 1; i <=6; i++)
		{
			cin >> shu[i];
			if (shu[i] != 0)
				flag = false;
		}
		if (flag)
			break;
		res += shu[6];

		res += shu[5];
		give[1] += 11*shu[5];

		res += shu[4];
		give[2] += 5 * shu[4];

		res += shu[3] / 4;
		if (shu[3] % 4 != 0)
		{
			res++;
			if (shu[3] % 4 == 1)
			{
				give[2] += 5;
				give[1] += 7;
			}
			if (shu[3] % 4 == 2)
			{
				give[2] += 3;
				give[1] += 6;
			}
			if (shu[3] % 4 == 3)
			{
				give[2] += 1;
				give[1] += 5;
			}
		}

		if (shu[2] <=give[2])
		{
			give[1] += 4 * (give[2] - shu[2]);
		}
		if (shu[2] > give[2])
		{
			res += (shu[2] - give[2]) / 9;
			if ((shu[2] - give[2]) % 9 != 0)
			{
				res++;
				give[1] += 4 * (9 - (shu[2] - give[2]) % 9);
			}
		}
		//printf("res %d shu1 %d give1 %d\n", res,shu[1], give[1]);
		//cout << (1 % 36) << endl;
		if (give[1] < shu[1])
		{
			res += (shu[1] - give[1]) / 36;
			if ((shu[1] - give[1]) % 36 != 0)
				res++;

		}
		cout << res << endl;
	}
	

}