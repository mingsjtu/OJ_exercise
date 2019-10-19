//http://poj.org/problem?id=1850
#include<iostream>
#include<cstring>
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;
char word[15];
int c[35][35];
void init()
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
int main()
{
	init();
	/*for (int i = 1; i <= 26; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			cout << c[i][j] << ' ';
		}
		cout << endl;
	}*/
	scanf("%s", word);
	if (strlen(word) < 2)
	{
		cout << word[0] - 'a' + 1 << endl;
		return 0;
	}
	int len = strlen(word);
	int i = 0, j, k;
	int res = 0;
	for (i = 1; i < len; i++)
	{
		if (word[i] <= word[i - 1])
		{
			cout << 0 << endl;
			return 0;
		}
	}
	//printf("len %d\n", len);
	for (i = 1; i <= len - 1; i++)
		res += c[26][i];
	for (i = 0; i < word[0] - 'a'; i++)
	{
		res += c[26 - i-1][len-1];
	}
	for (i = 1; i < len-1; i++)
	{
		for (j = word[i-1]-'a'+1; j < word[i] - 'a'; j++)
		{
			res += c[26-j-1][len-i-1];
		}
	}
	res += word[len - 1]-word[len - 2];
	cout << res << endl;
	
}