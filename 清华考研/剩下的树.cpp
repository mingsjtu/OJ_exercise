//https://www.nowcoder.com/practice/f5787c69f5cf41499ba4706bc93700a2?tpId=40&tqId=21356&tPage=2&rp=2&ru=%2Fta%2Fkaoyan&qru=%2Fta%2Fkaoyan%2Fquestion-ranking
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
bool shu[10005];
using namespace std;
int L, M;
int main()
{
	int i, j, k;
	int a, b;
	while (cin >> L >> M)
	{
		memset(shu, 0, sizeof(shu));

		for (i = 0; i <= L; i++)
			shu[i] = 1;
		for (i = 0; i < M; i++)
		{
			cin >> a >> b;
			for (j = a; j <= b; j++)
				shu[j] = 0;
		}
		int len = 0;
		for (i = 0; i <= L; i++)
		{
			if (shu[i] == 1)
				len++;
		}
		cout << len << endl;
	}
}