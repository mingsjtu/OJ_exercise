//http://poj.org/problem?id=1035
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<queue>
using namespace std;
char dic[10005][16];
int len[10005];
int n;
char br[2]="#";
bool huan(int index, char* s)
{
	int cuo = 0;
	int i, j, k;
	for (i = 0; i < len[index]; i++)
	{
		if (dic[index][i] != s[i])
		{
			cuo++;
			if (cuo > 1)
			{
				return false;
			}
		}
	}
	return true;
}
bool insert(int index, char* s)
{
	int cuo = 0, i, j=0, k;
	for (i = 0; i < len[index]; i++)
	{
		if (dic[index][i] != s[j])
		{
			j++;
			cuo++;
			if (cuo > 1)
				return false;
			if (dic[index][i] != s[j])
				return false;
		}
		j++;
	}
	return true;
}
bool del(int index, char* s)
{
	int cuo = 0, i, j=0, k;
	for (i = 0; i < len[index]; i++)
	{
		if (dic[index][i] != s[j])
		{
			i++;
			cuo++;
			if (cuo > 1)
				return false;
			if (dic[index][i] != s[j])
				return false;
		}
		j++;
	}
	return true;
}
int main()
{
	int i, j, k;
	int lei = 0;
	n = 0;
	int curlen = 0;
	char str[16];
	char per[10005][16];
	int pern = 0;
	while(cin>>dic[n])
	{
		if (strcmp(dic[n], br) == 0)
			break;
		len[n] = strlen(dic[n]);		
		//cout << dic[n] << endl;
		//cout<<strcmp(dic[n],br)<<endl;
		n++;
		
		
	}
	while (cin>>str)
	{
		lei = 0;
		pern = 0;
		memset(per, 0, sizeof(per));
		//cout << str << endl;
		//cout << strcmp(str, br) << endl;
		if (strcmp(str,br)==0)
			break;
		curlen = strlen(str);
		for (i = 0; i < n&&lei!=1; i++)
		{
			if (len[i] == curlen)
			{
				if (strcmp(str, dic[i])==0)
				{
					lei = 1;
					break;	
				}
				else
				{
					if (huan(i, str))
					{
						strcpy(per[pern++], dic[i]);
					}
				}
			}
			if (len[i] == curlen - 1)
			{
				if (insert(i, str))
				{
					strcpy(per[pern++], dic[i]);
				}
			}
			if (len[i] == curlen + 1)
			{
				if (del(i, str))
				{
					strcpy(per[pern++], dic[i]);
				}
			}
		}
		if (lei == 1)
		{
			printf("%s is correct\n", str);
		}
		else
		{
			printf("%s:", str);
			for (j = 0; j < pern; j++)
			{
				printf(" %s", per[j]);
			}
			cout << endl;
		}
	}
}