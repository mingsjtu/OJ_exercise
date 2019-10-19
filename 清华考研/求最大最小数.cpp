//https://www.nowcoder.com/practice/82e5ff335eeb486aab359767895cc7b4?tpId=40&tqId=21344&tPage=1&rp=1&ru=%2Fta%2Fkaoyan&qru=%2Fta%2Fkaoyan%2Fquestion-ranking
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	int maxn, minn, n, i,tmp;
	while (cin >> n)
	{
		maxn = -100000000;
		minn = -maxn;
		for (i = 0; i < n; i++)
		{
			scanf("%d", &tmp);
			//cout << tmp<<" ";
			if (tmp > maxn)
				maxn=tmp;
			if (tmp < minn)
				minn = tmp;
		}
		printf("%d %d\n", maxn, minn);
	}
}