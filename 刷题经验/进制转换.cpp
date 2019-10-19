//
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
using namespace std;
int n, m;
string conversion(string a,int n,int m)
{
	string b = "";
	int i, j, k;
	int len = a.length();
	int tmp = 0,jin=0;
	for (i = 0; i < len;)
	{
		jin = 0;
		cout << a << endl;
		for (j = i; j < len; j++)
		{
			tmp = a[j] - '0' + jin * n;
			jin = tmp % m;
			a[j] = tmp / m+'0';
		}
		
		b += jin + '0';
		i = 0;
		while (a[i] == '0')
			i++;
	}
	reverse(b.begin(), b.end());
	return b;
}
int main()
{
	string str1, str2;
	cin >> str1;

	scanf("%d %d", &n, &m);
	cout << str1 <<n<<m<< endl;
	str2=conversion(str1, n, m);
	cout << str2 << endl;
}