//https://www.nowcoder.com/practice/912b15e237ef44148e44018d7b8750b6?tpId=40&tqId=21346&tPage=1&rp=1&ru=%2Fta%2Fkaoyan&qru=%2Fta%2Fkaoyan%2Fquestion-ranking
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
using namespace std;
bool test(int a, int b, int c)
{
	int res = 0;
	res = (a + b) * 100 + (b + c) * 10 + c*2;
	if (res == 532)
		return true;
	return false;
}
int main()
{
	int a, b, c;
	int i, j, k;
	for (a = 0; a <= 5; a++)
	{
		for (b = 0; b + a <= 5; b++)
		{
			for (c = 0; c <= 9; c++)
			{
				if (test(a, b, c))
				{
					printf("%d %d %d\n", a, b, c);
					break;
				}
			}
		}
	}
}