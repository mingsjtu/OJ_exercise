//https://www.nowcoder.com/practice/ccc3d1e78014486fb7eed3c50e05c99d?tpId=40&tqId=21351&tPage=1&rp=1&ru=/ta/kaoyan&qru=/ta/kaoyan/question-ranking
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<math.h>
#include<queue>
using namespace std;
int yin[20];
int shu[20];
int zhao(int x)
{
	//cout << x;
	int i, j, k;
	int index = 0;
	memset(yin, 0, sizeof(yin));
	memset(shu, 0, sizeof(shu));
	int res = 1;
	int yuan = x;
	for (i = 2; i <=yuan; i++)
	{
		if (x%i == 0)
		{
			//cout << "yin" << i << endl;
			j = 0;
			while (x%i == 0)
			{
				x /= i;
				j++;
			}
			res *= (1 - pow(i, j+1) )/ (1 - i);
		}
	}
	//cout <<' '<< res << endl;
	if (x != 1)
	{
		return 1;
	}
	else
	{
		return res-yuan;
	}
}
int main()
{
	queue<int> wan,ying;
	int x;
	int i, j, k;
	for (i = 2; i <=60; i++)
	{
		//cout << i <<' '<< zhao(i)<<endl;
		if (zhao(i) == i)
			wan.push(i);
		if (zhao(i) > i)
			ying.push(i);
	}
	cout << "E: ";
	while (!wan.empty())
	{
		printf("%d ", wan.front());
		wan.pop();
	}
	cout << endl;
	cout << "G: ";
	while (!ying.empty())
	{
		printf("%d ", ying.front());
		ying.pop();
	}
	cout << endl;
}