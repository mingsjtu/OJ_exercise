//http://poj.org/problem?id=2503
#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
#include<string>
using namespace std;
string dic[100005];

int main()
{
	map<string, int> m1;
	string s1, s2;
	int i=0;
	char s[100],a[100],b[100];
	while (cin.getline(s,80)&&strlen(s)!=0)
	{
		//if (s1 == "\0")
		//	break;
		//cin >> s2;
		sscanf(s, "%s %s", a, b);
		s1 = a;
		s2 = b;
		//cout << s1 << endl<<s2<<endl;
		if (m1.find(s2) == m1.end())
		{
			m1[s2] = i;
			dic[i++] = s1;
			//cout << "cun  " << s2 << dic[m1[s2]] << endl;
		}
	}
	//cout << "ok" << endl;
	while (cin >> s2)
	{
		//cout << s2 << endl;
		if (m1.find(s2) == m1.end())
		{
			printf("eh\n");
			continue;
		}
		cout << dic[m1[s2]] << endl;
	}
}