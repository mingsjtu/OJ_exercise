//http://poj.org/problem?id=1013
#include<iostream>
#include<cstdio>
#include<cstring>
#include"math.h"
using namespace std;
char l[3][15], r[3][15], ba[3][5];
//int a[12];
int yi[12];
int main()
{
	int t, i, j, k;
	cin >> t;
	while (t--)
	{
		memset(yi, 0, sizeof(yi));
		for (i = 0; i < 3; i++)
		{
			cin >> l[i] >> r[i] >> ba[i];
			//cout << l[i] << endl << r[i] << endl<<ba[i]<<endl;
			
			if (strcmp(ba[i], "up") == 0)
			{
				for (j = 0; j < strlen(l[i]); j++)
				{
					yi[l[i][j] - 'A']++;				
				}
				for (j = 0; j < strlen(r[i]); j++)
				{
					yi[r[i][j] - 'A']--;

				}
			}
			if (strcmp(ba[i], "down") == 0)
			{
				for (j = 0; j < strlen(l[i]); j++)
				{
					yi[l[i][j] - 'A']--;
				}
				for (j = 0; j < strlen(r[i]); j++)
				{
					yi[r[i][j] - 'A']++;

				}
			}
		}
		for (i = 0; i < 3; i++)
		{
			if (strcmp(ba[i], "even") == 0)
			{
				for (j = 0; j < strlen(l[i]); j++)
				{
					
					yi[l[i][j] - 'A'] = 0;
					
				}
				for (j = 0; j < strlen(r[i]); j++)
				{

					yi[r[i][j] - 'A'] = 0;

				}
			}
		}
		
		int maxn = 0, res = -1,tmp;
		for (i = 0; i < 12; i++)
		{
			if (yi[i] < 0)
				tmp = 0 - yi[i];
			if (tmp > maxn)
			{
				maxn = tmp;
				res = i;
			}
		}
		if (yi[res]>0)
		{
			printf("%c is the counterfeit coin and it is heavy.\n", char(res + 'A'));
			break;
		}
		if (yi[res]<0)
		{
			printf("%c is the counterfeit coin and it is light.\n", char(res + 'A'));
			break;
		}


	}

}