//http://poj.org/problem?id=3252
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
int c[35][35];
void play_table()
{
	for (int i = 0; i <= 32; i++)
		for (int j = 0; j <= i; j++)
			if (!j || i == j)
				c[i][j] = 1;
			else
				c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
	//	c[0][0]=0;
	return;
}

int c0(int a, int b)
{
	int i,res=0;
	for (i = b; i <=a; i++)
	{
		res += c[a][i];
	}
	return res;
}

long long whole(int t)
{
	long long res = 0;
	while (t>=2)
	{
		long long tmp = c0(t - 1, (t-1)/ 2+1);
		//printf("tmp %d\n", tmp);
		t --;
		res += tmp;
	}
	return res;
}
long long compute(int x)
{
	if (x <= 1)
		return 0;
	//printf("compute %d\n", x);
	int t=0;//weishu
	int dig[50];
	int i, j, k;
	while (x > 0)
	{
		dig[t] = x % 2;
		//printf("wei %d is %d\n", t, dig[t]);
		x = x >> 1;
		t++;
	}
	long long res = 0;
	res += whole(t - 1);
	//printf("whole %d is %d\n", t, whole(t-1));
	int ge0 = 0,ge1=0;
	for (i = t - 2; i >= 0&&ge1<=(t+1)/2; i--)
	{
		if (dig[i] == 0)
			ge0++;
		if (dig[i] == 1)
		{
			ge1++;
			//start(i);
			//printf("start from %d to%d is %d", i, (t + 1) / 2 - ge0-1, c0(i,(t+1)/2-ge0-1));
			res += c0(i, (t + 1) / 2 - ge0-1);
		}
	}
	if (ge1 <= (t+1)/ 2)
		res++;
	return res;
}


int main()
{
	play_table();
	int i, j;

	int sta, en;
	long long res1, res2;
	cin >> sta >> en;
	res1 = compute(sta-1);
	//printf("res1 is %d\n", res1);
	res2=compute(en);
	//printf("res2 is %d\n", res2);
	cout << res2 - res1 << endl;
}