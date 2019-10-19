//http://bailian.openjudge.cn/jssxlylx2016/C/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
#include<string>
#include<algorithm>
using namespace std;
map<string, int> m1;
int n;
struct bing
{
	string index;
	int year;
	int hao;
}b[101];
bing b1[101];//laoren
bing b2[101];//nianqing
bool cmp1(bing b1, bing b2)
{
	if (b1.year > b2.year)
		return true;
	if (b1.year == b2.year && b1.hao < b2.hao)
		return true;
	else return false;
}
bool cmp2(bing b1, bing b2)
{
	if (b1.hao < b2.hao)
		return true;
	else return false;
}
int main()
{
	int i, j=0, k=0;
	cin >> n;
	string str;
	int y;
	for (i = 0; i < n; i++)
	{
		cin >> str >> y;
		b[i].index = str;
		b[i].year = y;
		b[i].hao = i;
		if (y >= 60)
		{
			b1[j++] = b[i];
		}
		else
		{
			b2[k++] = b[i];
		}
	}
	int n1 = j, n2 = k;
	sort(b1, b1 + n1, cmp1);
	for (i = 0; i < n1; i++)
	{
		cout << b1[i].index << endl;
	}
	for (i = 0; i < n2; i++)
	{
		cout << b2[i].index << endl;
	}
}