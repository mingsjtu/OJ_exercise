//Memory Time 
//252K   16MS 
/* 2011 POJ暑假集训题-Problem E */

#include<iostream>
#include<algorithm>
using namespace std;

int cmp(const void* a, const void* b)
{
	return *(int*)b - *(int*)a;
}

int n;  //木棒数量

bool dfs(int* stick, bool* vist, int len, int InitLen, int s, int num)  //len:当前正在组合的棒长  InitLen:目标棒长  
{                                                                  //s:stick[]的搜索起点  num:已用的棒子数量
	if (num == n)
	{
		//printf("curn %d\n", curn);
		return true;
	}

	int sample = -1;
	for (int i = s; i < n; i++)
	{
		if (vist[i] || stick[i] == sample)  //剪枝3,等长的木棒只搜索一次
			continue;

		vist[i] = true;
		if (len + stick[i] < InitLen)
		{
			if (dfs(stick, vist, len + stick[i], InitLen, i, num + 1))
			//if (dfs(stick, vist, len + stick[i], InitLen, i, num + 1,curn))
				return true;
			else
				sample = stick[i];
		}
		else if (len + stick[i] == InitLen)
		{
			if (dfs(stick, vist, 0, InitLen, 0, num + 1))
			//if (dfs(stick, vist, 0, InitLen, 0, num + 1,curn+1))
				return true;
			else
				sample = stick[i];
		}
		vist[i] = false;

		if (len == 0)  //剪枝4，构建新棒时，对于新棒的第一根棒子，在搜索完所有棒子后都无法组合
			break;  //则说明该棒子无法在当前组合方式下组合，不用往下搜索(往下搜索会令该棒子被舍弃)，直接返回上一层
	}
	return false;
}

int main(void)
{
	while (cin >> n && n)
	{
		int* stick = new int[n];
		bool* vist = new bool[n];
		int sumlen = 0;

		for (int i = 0; i < n; i++)
		{
			cin >> stick[i];
			sumlen += stick[i];
			vist[i] = false;
		}

		qsort(stick, n, sizeof(stick), cmp);
		int maxlen = stick[0];   //最大的棒为InitLen的搜索起点

		bool flag = false;
		//剪枝1,若能在[maxlen,sumlen-InitLen]找到最短的InitLen，该InitLen必也是[maxlen,sumlen]的最短
		for (int InitLen = maxlen; InitLen <= sumlen - InitLen; InitLen++)  //InitLen:原始棒长
		{   //剪枝2,InitLen必是sumlen的约数
			if (!(sumlen%InitLen) && dfs(stick, vist, 0, InitLen, 0, 0))
			//if (!(sumlen%InitLen) && dfs(stick, vist, 0, InitLen, 0, 0,1))
			{
				cout << InitLen << endl;
				flag = true;
				break;
			}
		}
		if (!flag)
			cout << sumlen << endl;

		delete stick;
		delete vist;
	}
	return 0;
}
