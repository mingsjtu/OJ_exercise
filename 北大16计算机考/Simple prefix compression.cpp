//http://bailian.openjudge.cn/practice/2334/
#include<iostream>
#include<cstring>
using namespace std;
char con[260], pre[260],tmp[260];
int n;
int solve(char p[], char c[])
{
	int len1 = strlen(p), len2 = strlen(c);
	int len = len1 < len2 ? len1:len2;
	int i=0;
	while (i < len && p[i] == c[i])
	{
		i++;
	}
	return len2-i+1;

}
int main()
{
	cin >> n;
	int i,s=0;
	cin >> con;
	s += strlen(con);
	for (i = 1; i < n; i++)
	{
		strcpy_s(pre, con);
		cin >> con;
		s+=solve(pre, con);
	}
	cout << s << endl;
}