//#pragma warning(disable:4996)
//¡¶ÍõµÀ¿¼ÑÐ¡·76Ò³
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;

char word1[20], word2[20];
int shu1[20], shu2[20];
int main()
{
	int i, j,zong1=0,zong2=0;
	while (cin>>word1>>word2)
	{
		for (i = 0; word1[i] != '\0'; i++)
		{
			cout << "word1" << word1[i] << endl;
			shu1[i] = int(word1[i] - '0');
			zong1 += shu1[i];
		}
		for (i = 0; word2[i] != '\0'; i++)
		{
			cout << "word2" << word2[i] << endl;

			shu2[i] = int(word2[i] - '0');
			zong2 += shu2[i];

		}
		printf("%d", zong1*zong2);


	}
	return 0;
}
