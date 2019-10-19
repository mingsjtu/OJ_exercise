//http://poj.org/problem?id=2996
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
const int N = 33;
const int M = 17;
const char name1[5] = { 'K','Q','R','B','N' };
const char name2[5] = { 'K','Q','R','B','N' };

char map[40][40];
using namespace std;
//Ke1, Qd1, Ra1, Rh1, Bc1, Bf1, Nb1
struct wei
{
	int lie, hang;
}w1[6][70], w2[6][70];
bool cmp1(wei w1, wei w2)
{
	if (w1.hang < w2.hang)
		return true;
	if (w1.hang == w2.hang&&w1.lie < w2.lie)
		return true;
	return false;
}
bool cmp2(wei w1, wei w2)
{
	if (w1.hang > w2.hang)
		return true;
	if (w1.hang == w2.hang&&w1.lie < w2.lie)
		return true;
	return false;
}
int num1[6], num2[6];
int main()
{
	int i, j, k;
	memset(num1, 0, sizeof(num1));
	memset(num2, 0, sizeof(num2));
	for (i = 0; i < M; i++)
	{
		for (j = 0; j < N; j++)
		{
			cin >> map[i][j];
			//printf("i %d j%d\n;", i, j);
			switch (map[i][j])
			{
			case 'K':
				w1[0][num1[0]].lie = (j - 2) / 4;
				w1[0][num1[0]].hang = 9 - (i - 1) / 2 - 1;
				num1[0]++;
				break;

			case 'Q':
				w1[1][num1[1]].lie = (j - 2) / 4;
				w1[1][num1[1]].hang = 9 - (i - 1) / 2 - 1;
				num1[1]++;
				break;
			case 'R':
				w1[2][num1[2]].lie = (j - 2) / 4;
				w1[2][num1[2]].hang = 9 - (i - 1) / 2 - 1;
				num1[2]++;
				break;
			case 'B':
				w1[3][num1[3]].lie = (j - 2) / 4;
				w1[3][num1[3]].hang = 9 - (i - 1) / 2 - 1;
				num1[3]++;
				break;
			case 'N':
				w1[4][num1[4]].lie = (j - 2) / 4;
				w1[4][num1[4]].hang = 9 - (i - 1) / 2 - 1;
				num1[4]++;
				break;
			case 'P':
				w1[5][num1[5]].lie = (j - 2) / 4;
				w1[5][num1[5]].hang = 9 - (i - 1) / 2 - 1;
				num1[5]++;
				break;

			case 'k':
				w2[0][num2[0]].lie = (j - 2) / 4;
				w2[0][num2[0]].hang = 9 - (i - 1) / 2 - 1;
				num2[0]++;
				break;
			case 'q':
				w2[1][num2[1]].lie = (j - 2) / 4;
				w2[1][num2[1]].hang = 9 - (i - 1) / 2 - 1;
				num2[1]++;
				break;
			case 'r':
				w2[2][num2[2]].lie = (j - 2) / 4;
				w2[2][num2[2]].hang = 9 - (i - 1) / 2 - 1;
				num2[2]++;
				break;
			case 'b':
				w2[3][num2[3]].lie = (j - 2) / 4;
				w2[3][num2[3]].hang = 9 - (i - 1) / 2 - 1;
				num2[3]++;
				break;
			case 'n':
				w2[4][num2[4]].lie = (j - 2) / 4;
				w2[4][num2[4]].hang = 9 - (i - 1) / 2 - 1;
				num2[4]++;
				break;
			case 'p':
				w2[5][num2[5]].lie = (j - 2) / 4;
				w2[5][num2[5]].hang = 9 - (i - 1) / 2 - 1;
				num2[5]++;
				break;
			}
		}
		//cout << endl;
	}
	for (i = 0; i < 6; i++)
	{
		sort(w1[i], w1[i] + num1[i], cmp1);
		sort(w2[i], w2[i] + num2[i], cmp2);
	}
	//White: Ke1, Qd1, Ra1, Rh1, Bc1, Bf1, Nb1, a2, c2, d2, f2, g2, h2, a3, e4
		//Black : Ke8, Qd8, Ra8, Rh8, Bc8, Ng8, Nc6, a7, b7, c7, d7, e7, f7, h7, h6
	printf("White: ");
	int last1 = 0;
	for (i = 0; i < 5; i++)
	{
		if (num1[i] != 0)
			last1 = i;
	}
	bool flag1 = true;

	if (num1[5] == 0)
		flag1 = false;
	if (flag1)
	{
		for (i = 0; i <=last1; i++)
		{
			if (num1[i] == 0)
				continue;

			for (j = 0; j < num1[i]; j++)
			{
				printf("%c%c%d,", name1[i], char(w1[i][j].lie + 'a'), w1[i][j].hang);
			}
		}
		for (i = 0; i < num1[5] - 1; i++)
		{
			printf("%c%d,", char(w1[5][i].lie + 'a'), w1[5][i].hang);

		}
		printf("%c%d\n", char(w1[5][num1[5] - 1].lie + 'a'), w1[5][num1[5] - 1].hang);
	}
	else
	{
		for (i = 0; i <=last1 - 1; i++)
		{
			if (num1[i] == 0)
				continue;

			for (j = 0; j < num1[i]; j++)
			{
				printf("%c%c%d,", name1[i], char(w1[i][j].lie + 'a'), w1[i][j].hang);
			}
		}
		for (i = 0; i <num1[last1] - 1; i++)
		{
			printf("%c%c%d,", name1[last1], char(w1[last1][i].lie + 'a'), w1[last1][i].hang);

		}
		printf("%c%c%d\n", name1[last1], char(w1[last1][num1[last1] - 1].lie + 'a'), w1[last1][num1[last1] - 1].hang);

	}

	//Black
	printf("Black: ");
	int last2 = 0;
	for (i = 0; i < 5; i++)
	{
		if (num2[i] != 0)
			last2 = i;
	}
	bool flag2 = true;

	if (num2[5] == 0)
		flag2 = false;
	if (flag2)
	{
		for (i = 0; i <= last2; i++)
		{
			if (num2[i] == 0)
				continue;

			for (j = 0; j < num2[i]; j++)
			{
				printf("%c%c%d,", name2[i], char(w2[i][j].lie + 'a'), w2[i][j].hang);
			}
		}
		for (i = 0; i < num2[5] - 1; i++)
		{
			printf("%c%d,", char(w2[5][i].lie + 'a'), w2[5][i].hang);

		}
		printf("%c%d\n", char(w2[5][num2[5] - 1].lie + 'a'), w2[5][num2[5] - 1].hang);
	}
	else
	{
		for (i = 0; i <= last2 - 1; i++)
		{
			if (num2[i] == 0)
				continue;

			for (j = 0; j < num2[i]; j++)
			{
				printf("%c%c%d,", name2[i], char(w2[i][j].lie + 'a'), w2[i][j].hang);
			}
		}
		for (i = 0; i < num2[last2] - 1; i++)
		{
			printf("%c%c%d,", name2[last2], char(w2[last2][i].lie + 'a'), w2[last2][i].hang);

		}
		printf("%c%c%d\n", name2[last2], char(w2[last2][num2[last2] - 1].lie + 'a'), w2[last2][num2[last2] - 1].hang);

	}
}

