//https://blog.csdn.net/zhonghuan1992/article/details/39718161
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int n;
int wei[10];
int ori[10];
int lei;
void zuida(int w)
{
	//printf("zuida\n");
	for (int i = 0; i < w / 2; i++)
	{
		wei[i] = 1;
	}
	for (int i = w / 2; i < w; i++)
	{
		wei[i] = 4;
	}
}
int chai(int n)
{
	lei = 1;
	int big1=0, big4=0;
	int i=0, j, k;
	while (n > 0)
	{
		ori[i] = n % 10;
		if (ori[i] >= 4)
			big4++;
		else
		{
			if (ori[i] >= 1)
				big1++;
			else
			{
				lei = 0;
				//break;
			}
		}
		n /= 10;
		i++;
	}
	int w = i;
	for (i = 0; i < w; i++)
	{
		printf("%d", ori[i]);
	}
	cout<<endl;
	//printf("big 4 %d\n", big4);
	//printf("big 1 %d\n", big1);
	//cout << "wei" << w << endl;
	if (lei==0 || big4 < w / 2)
	{
		w--;
		if (w / 2 == 1)
			w--;
		zuida(w);
		return w;
	}
	if (w % 2 == 1)
	{
		zuida(w-1);
		return (w-1);
	}
	big4 = w / 2;
	for (i = w/2; i < w; i++)
	{
		if (ori[i] < 4)
			wei[i] = 1;
		else
		{
			wei[i] = 4;
			big4--;
		}
	}
	i = w / 2 - 1;
	//printf("big4 %d,i%d\n", big4, i);
	while (big4 > 0&&i>=0)
	{
		if (ori[i] >= 4)
		{
			wei[i] = 4;
			big4--;
			//printf("wei[%d] is\n", i, wei[i]);
		}
		else
			wei[i] = 1;
		i--;
	}
	while (i>=0)
	{
		wei[i] = 1;
		i--;
	}
	return w;
	
}

int main()
{
	int i, j, k;
	while (cin >> n)
	{
		if (n < 14)
		{
			cout << 14 << endl;
			continue;
		}
		int w=chai(n);
		for (i = w-1; i>=0; i--)
		{
			printf("%d", wei[i]);
		}
		cout << endl;
	}
}