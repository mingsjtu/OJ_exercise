//http://poj.org/problem?id=1012
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
bool flag;
bool test1(int x, int y)
{
	int i = 0;
	int shan = 0;
	int old = 0, ori;
	while (shan < x)
	{
		ori = (old + y - 1) % (2 * x - i);
		//printf("shan %d\n", ori);
		if (ori < x)
			return false;
		shan++;
		i++;
		old = ori;
	}
	return true;
}
bool test(int x, int y)
{
	bool huo[28];
	int i = 0;
	int shan = 0;
	int j = 0;
	memset(huo, 0, sizeof(huo));
	while(shan<x)
	{
		//printf("i %d ,j %d \n",i, j);
		if (huo[i] == 1)
		{
			i++;
			i %= x + x;
			continue;
		}
		j++;
		if (j == y)
		{
			j = 0;
			huo[i] = 1;
			if (i < x)
			{
				
				return false;
			}
			//printf("shan %d\n", i);
			shan++;
		}
		i++;
		i %= x + x;
		
	}
	return true;
}
int main()
{
	int x,i, j, k;
	//test1(3, 5);
	//while (cin >> x)
	//{
	//	if (x == 0)
	//		break;
	//	flag = false;
	//	i = x + 1;
	//	while (flag == false)
	//	{
	//		//printf("test %d for %d\n", i, x);
	//		flag = test1(x, i);
	//		i++;
	//	}
	//	cout << i-1 << endl;
	//}
	for (x = 1; x < 14; x++)
	{
		flag = false;
		i = x + 1;
		while (flag == false)
		{
			//printf("test %d for %d\n", i, x);
			flag=test1(x, i);
			i++;
		}
		//printf("find %d is %d\n", x, i-1);
		printf("%d,",i - 1);
	}
	
}