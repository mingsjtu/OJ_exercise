//Memory Time 
//252K   16MS 
/* 2011 POJ��ټ�ѵ��-Problem E */

#include<iostream>
#include<algorithm>
using namespace std;

int cmp(const void* a, const void* b)
{
	return *(int*)b - *(int*)a;
}

int n;  //ľ������

bool dfs(int* stick, bool* vist, int len, int InitLen, int s, int num)  //len:��ǰ������ϵİ���  InitLen:Ŀ�����  
{                                                                  //s:stick[]���������  num:���õİ�������
	if (num == n)
	{
		//printf("curn %d\n", curn);
		return true;
	}

	int sample = -1;
	for (int i = s; i < n; i++)
	{
		if (vist[i] || stick[i] == sample)  //��֦3,�ȳ���ľ��ֻ����һ��
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

		if (len == 0)  //��֦4�������°�ʱ�������°��ĵ�һ�����ӣ������������а��Ӻ��޷����
			break;  //��˵���ð����޷��ڵ�ǰ��Ϸ�ʽ����ϣ�������������(������������ð��ӱ�����)��ֱ�ӷ�����һ��
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
		int maxlen = stick[0];   //���İ�ΪInitLen���������

		bool flag = false;
		//��֦1,������[maxlen,sumlen-InitLen]�ҵ���̵�InitLen����InitLen��Ҳ��[maxlen,sumlen]�����
		for (int InitLen = maxlen; InitLen <= sumlen - InitLen; InitLen++)  //InitLen:ԭʼ����
		{   //��֦2,InitLen����sumlen��Լ��
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
