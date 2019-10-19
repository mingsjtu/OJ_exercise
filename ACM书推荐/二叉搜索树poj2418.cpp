//http://poj.org/problem?id=2418
#include<iostream>
#include<cstdio>
#include<string>
#include<map>
#include<algorithm>
#include<cstring>

using namespace std;
int s = 0;
string name[10005];

map<string, int> m1;
int geshu[10005];
int main()
{
	char tmp1[40];
	int num = 0;
	string tmp;
	memset(geshu, 0, sizeof(geshu));
	while (scanf("%[^\n]", tmp1)!=EOF)
	{
		getchar();
		s++;
		tmp = tmp1;
		if (m1.find(tmp) == m1.end())
		{
			m1[tmp] = num;
			geshu[m1[tmp]]++;
			name[num] = tmp;
			num++;
		}
		else
		{
			geshu[m1[tmp]]++;
		}
		//cout << "ok" << endl;
	}

	sort(name, name + num);
	for (int i = 0; i < num; i++)
	{
		//strcmp(tmp,name[i]);
		tmp = name[i];
		double a = geshu[m1[tmp]];
		double b = s;
		cout << tmp << ' ';
		printf("%.4f\n", a / b*100);
	}
}
