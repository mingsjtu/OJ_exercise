//https://blog.csdn.net/bugaosuni59/article/details/82707451
#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
#include<math.h>
using namespace std;
int p;
int dig[1670][57];
void multi(int* ori, int* res)
{
	int i, j, k, tmp, jinwei = 0;
	for (i = 0; i <= 55; i++)
	{
		//printf("tmp%d\n", tmp);
		tmp=ori[i]*2 + jinwei;
		jinwei=tmp / 1000000000;
		res[i]=tmp % 1000000000;
		
	}
}
void display(int* ori)
{
	int i;
	printf("%05d", ori[55]);
	for (i = 0; i< 54; i++)
	{
		//cout << "at" << i << endl;
		printf("%09d", ori[54 - i]);
	}
	printf("%09d\n", ori[0] - 1);
	cout << endl;
	
}
int main()
{
	scanf("%d", &p);
	int i, j, k;
	int weishu = p * log(2) / log(10) + 1;
	for (i = 12; i*log(2) / log(10) <= 501; i++){}
		//cout << i * log(2) / log(10) << endl;
	cout << (i+1)<< endl;
	int jie = i+1;
	memset(dig, 0, sizeof(dig));
	dig[1][0] = 2;
	for (i = 1; i <= p; i++)
	{	
		printf("current i%d\n", i);
		multi(dig[i], dig[i + 1]);
	}
	
	display(dig[p]);
}