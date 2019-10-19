#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;
char map[100][22];
char qian[202];
int hang, lie,num;
int main()
{
	cin >> lie;
	cin>>qian;
	num=strlen(qian);
	hang = num / lie;
	//cout << hang << "hang" << endl;
	int i, j,k=0;
	for (i = 0; i < hang; i++)
	{
		if (i % 2 == 0) 
		{
			for (j = 0; j < lie; j++)
			{
				map[i][j] = qian[k++];
			}
		}
		else
		{
			for (j = lie - 1; j >= 0; j--)
			{
				map[i][j] = qian[k++];
			}
		}
	}
	for (j = 0; j < lie; j++)
	{
		for (i = 0; i < hang; i++)
			cout << map[i][j];

	}
}