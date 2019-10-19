//http://poj.org/problem?id=2503
#include<iostream>
#include<cstring>
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;
char str[30];
struct s
{
	char to[30], from[30];
};
s s0[100005];
bool cmp(s s1, s s2)
{
	if (strcmp(s1.to, s2.to)>0)
	{
		return true;
	}
	return false;
}
char ori[30];
int myfind(int sta, int en,char* tar)
{
	int m;
	if (sta == en)
		return sta;
	m = (sta + en) / 2;
	if (s0[m].to == tar)
		return m;
	if (s0[m].to < tar)
		return myfind(sta, m,tar);
	if (s0[m].to > tar)
		return myfind(m, en, tar);
}
int main()
{
	int i = 0;
	while (cin.getline(str,30),strlen(str)!=0)
	{
		sscanf(str,"%s %s", s0[i].to, s0[i].from);
		i++;
		cout << s0[i].to << "  " << s0[i].from<<endl;
	}
	sort(s0, s0 + i, cmp);
	char tar[30];
	int res;
	while (scanf(tar))
	{
		res=myfind(0, i - 1, tar);
		printf("%s\n", s0[res].from);
	}
}