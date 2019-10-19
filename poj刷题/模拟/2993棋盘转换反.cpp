//http://poj.org/status
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
const int N = 35;
const int M = 17;
const char bian[N] = {"+---+---+---+---+---+---+---+---+\n"};
const char name1[7] = { "KQRBNP" };
const char name2[7] = { "kqrbnp" };
char map[M][N] = { "+---+---+---+---+---+---+---+---+\n",
"|...|:::|...|:::|...|:::|...|:::|\n",
"+---+---+---+---+---+---+---+---+\n",
"|:::|...|:::|...|:::|...|:::|...|\n",
"+---+---+---+---+---+---+---+---+\n",
"|...|:::|...|:::|...|:::|...|:::|\n",
"+---+---+---+---+---+---+---+---+\n",
"|:::|...|:::|...|:::|...|:::|...|\n",
"+---+---+---+---+---+---+---+---+\n",
"|...|:::|...|:::|...|:::|...|:::|\n",
"+---+---+---+---+---+---+---+---+\n",
"|:::|...|:::|...|:::|...|:::|...|\n",
"+---+---+---+---+---+---+---+---+\n",
"|...|:::|...|:::|...|:::|...|:::|\n",
"+---+---+---+---+---+---+---+---+\n",
"|:::|...|:::|...|:::|...|:::|...|\n",
"+---+---+---+---+---+---+---+---+\n"
};
bool flag;
void solve()
{
	char tmp,tmp1; int tmp2;
	while (1)
	{
		scanf("%c", &tmp);
		if ((tmp >= 'a'&&tmp <= 'h') || (tmp >= 'A'&&tmp <= 'Z'))
			break;
		if (tmp == '\n')
		{
			flag = false;
			return;
		}
	}
	int x, y;
	if (tmp>='a'&&tmp<='h')
	{
		cin >> tmp2;
		map[17-2*tmp2][(tmp - 'a')*4+2] = 'P';
	}
	else {
		if(tmp>='A'&&tmp<='Z')
		{
			cin >> tmp1 >> tmp2;
			map[17 - 2 * tmp2][(tmp1 - 'a') * 4 + 2] = tmp;
		}
	}
}
void solve1()
{
	char tmp, tmp1; int tmp2;
	while (1)
	{
		scanf("%c", &tmp);

		if ((tmp >= 'a'&&tmp <= 'h') || (tmp >= 'A'&&tmp <= 'Z'))
			break;
		if (tmp == '\n')
		{
			flag = false;
			return;
		}
	}
	int x, y;
	if (tmp >= 'a'&&tmp <= 'h')
	{
		cin >> tmp2;
		map[17 - 2 * tmp2][(tmp - 'a') * 4 + 2] = 'p';
	}
	else
	{
		if (tmp >= 'A'&&tmp <= 'Z')
		{
			cin >> tmp1 >> tmp2;
			map[17 - 2 * tmp2][(tmp1 - 'a') * 4 + 2] = tmp - 'A' + 'a';
		}
	}
}
int main()
{
	char tmp=' ';
	
	while (1)
	{
		scanf("%c",&tmp);
		flag = true;

		if (tmp == ' ' || tmp == ',')
		{
			flag = true;
			solve();
			if (!flag)
				break;
		}
		if (tmp == '\n')
			break;
	}
	//printf("get\n");
	while (1)
	{
		scanf("%c",&tmp);
		flag = true;
		if (tmp == ' ' || tmp == ',')
		{
			flag = true;
			solve1();
			if (!flag)
				break;
		}
		if (tmp == '\n')
			break;
	}
	//printf("get\n");

	int i;
	for (i = 0; i < M; i++)
	{
		printf("%s", map[i]);
	}
	


}