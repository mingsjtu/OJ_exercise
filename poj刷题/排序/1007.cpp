//http://poj.org/problem?id=1007
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
int n, m;
struct mys
{
	char s[55];
	int sor;
}dic[105];
//char dic[105][55];
int compute(char s[])
{
	int i,j, k;
	int sum = 0;
	for (i = 0; i < n-1; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			if (s[i] > s[j])
			{
				//printf("%c %c\n", s[i], s[j]);
				sum++;
			}
		}
	}
	return sum;
}
bool cmp(mys s1, mys s2)
{
	if (s1.sor < s2.sor)
		return true;
	else
		return false;
}
int main()
{
	cin >> n >> m;
	int i, j, k;
	for (i = 0; i < m; i++)
	{
		scanf("%s", dic[i].s);
		dic[i].sor=compute(dic[i].s);
		//printf("%d\n", dic[i].sor);
	}
	sort(dic, dic + m, cmp);
	for (i = 0; i < m; i++)
		cout << dic[i].s << endl;
		//printf("%s\n", &dic[i].s);

}