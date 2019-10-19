//http://poj.org/problem?id=1936
#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
using namespace std;
char str1[100005], str2[100005];
bool check(char* s1, char* s2)
{
	int len1, len2;
	len1 = strlen(str1);
	len2 = strlen(str2);
	if (len1 > len2)
	{
		return false;
	}
	int i, j, k;
	i = 0;
	j = 0;
	while (i < len1&&j < len2)
	{
		/*if (s1[i] >= 'A'&&s1[i] <= 'Z')
		{
			s1[i]=s1[i] - 'A' + 'a';
		}
		if (s2[j] >= 'A'&&s2[j] <= 'Z')
		{
			s2[j] = s2[j] - 'A' + 'a';
		}*/
		if (s1[i] == s2[j])
		{
			i++;
		}
		j++;
	}
	if (i == len1)
	{
		return true;
	}
	else
		return false;
}
int main()
{
	int len1, len2;
	while (scanf("%s %s", str1, str2) != EOF)
	{
		bool res=check(str1, str2);
		if (res)
			printf("Yes\n");
		else
			printf("No\n");
	}
}