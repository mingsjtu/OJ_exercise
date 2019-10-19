//http://poj.org/problem?id=1035
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
struct mystr
{
	string str;
	int hao;
};
vector<mystr> dic[16];
vector<mystr> per;

int lei;
void cun(string s,int hao)
{
	int len = s.length();
	mystr s1 = { s,hao };
	dic[len].push_back(s1);
}

void find(string s)
{
	lei = 1;
	int len0 = s.length();
	string tmps;
	mystr s1;
	int i, j, k;
	int cuo = 0;
	for(i=0;i<dic[len0].size();i++)
	{
		tmps = dic[len0][i].str;
		//printf("dic0\n");
		cuo = 0;
		if (tmps == s)
		{
			lei = 0;
			return;
			//break;
		}
		k = 0;
		bool ok = true;
		while (k < len0)
		{
			if (tmps[k] != s[k])
			{
				cuo++;
				if (cuo > 1)
				{
					ok = false;
					break;
				}
			}
			k++;
		}
		if (ok)
		{
			per.push_back(dic[len0][i]);
		}
	}
	if (len0 - 1 > 0)
	{
		for (i = 0; i < dic[len0 - 1].size(); i++)
		{
			tmps = dic[len0-1][i].str;
			//printf("dic-1\n");
			k = 0,j=0;
			bool ok = true;
			cuo = 0;
			/*while (k < len0 - 1)
			{
				if (tmps[k] != s[j])
				{
					tmps.insert(k, 1, s[j]);
					if (tmps == s)
						ok = true;
					else
						ok = false;
					break;
				}
				k++;
				j++;
			}*/
			while (k < len0-1)
			{
				if (tmps[k] != s[j])
				{
					cuo++;
					if (cuo > 1)
					{
						ok = false;
						break;
					}
					if (tmps[k] == s[j + 1])
					{
						j++;
					}
					else
					{
						ok = false;
						break;
					}
				}
				k++;
				j++;
			}
			if (ok)
			{
				per.push_back(dic[len0 - 1][i]);
			}
		}
	}
	if (len0 + 1 <= 15)
	{
		for (i = 0; i < dic[len0+1].size(); i++)
		{
			tmps = dic[len0+1][i].str;
			//cout << "tmps  " << tmps << endl;
			//printf("dic1\n");
			k = 0, j = 0;
			bool ok = true;
			cuo = 0;
			/*while (k < len0)
			{
				if (tmps[k] != s[j])
				{
					//printf("k: %d\n", k);
					tmps.erase(k, 1);
					//printf("cur tmps  ");
					//cout << tmps << endl;
					if (tmps == s)
						ok = true;
					else
						ok = false;
					break;
				}
				k++;
				j++;
			}
			*/
			while (j <len0)
			{
				if (tmps[k] != s[j])
				{
					cuo++;
					if (cuo > 1)
					{
						ok = false;
						break;
					}
					if (tmps[k+1] == s[j])
					{
						k++;
					}
					else
					{
						ok = false;
						break;
					}
				}
				k++;
				j++;
			}
			
			if (ok)
			{
				per.push_back(dic[len0+1][i]);
			}
		}
	}
}
bool cmp(mystr s1, mystr s2)
{
	if (s1.hao < s2.hao)
		return true;
	else
		return false;
}
int main()
{
	int len, i, j, k;
	string str;
	int hao = 0;
	while (cin >> str)
	{
		if (str == "#")
		{
			break;
		}
		cun(str,hao++);
	}
	while (cin >> str)
	{
		per.clear();
		if (str == "#")
		{
			break;
		}
		find(str);
		if (lei)
		{
			cout << str << ":";
			sort(per.begin(), per.end(), cmp);
			for (i = 0; i < per.size(); i++)
				cout <<' '<< per[i].str;
		}
		else
		{
			cout << str;
			printf(" is correct");
		}
		cout << endl;
	}
}