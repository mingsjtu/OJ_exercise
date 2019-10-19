//http://poj.org/problem?id=2305
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<stack>
using namespace std;
int digit1[2005];
int digit2[15];
char d1[2005];
char d2[15];
int b;
int zhuan(char* x,int l)
{
	int i, j, k;
	int res=0;
	int w = 1;
	for(i=0;i<l;i++)
	{
		res = res * b + int(x[i] - '0');
		//w *= b;
	}
	return res;
}
void ni(int x, int b)
{
	stack<int> s;
	int i = 0;
	while (x > 0)
	{
		//r[i++]=x%b;
		//printf("%d", x%b);
		s.push(x%b);
		x /= b;
	}
	while (!s.empty())
	{
		cout << s.top();
		s.pop();
	}
	cout << endl;
}
int main()
{
	int i, j, k,a;
	int len1, len2;
	while (cin >> b)
	{
		if (!b)
			break;
		int res = 0;
		scanf("%s %s", d1, d2);
		len1 = strlen(d1);
		len2 = strlen(d2);
		int a=zhuan(d2,len2);
		//cout << a << endl;
		int w = 1;
		for (i = len1-1; i>=0; i--)
		{
			//printf("+ %d", (d1[i] - '0')*w);
			res += (d1[i] - '0')*w;
			res %= a;
			w = (w*b) % a;
		}
		res %= a;
		//cout << res << endl;
		if (!res)
			cout << 0 << endl;
		else
			ni(res, b);
	}
}