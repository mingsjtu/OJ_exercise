//http://poj.org/problem?id=3253
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
using namespace std;
priority_queue<int,vector<int>,greater<int> > q1;
int a[20005];
int main()
{
	int n;
	cin >> n;
	int i, j, k;
	for (i = 0; i < n; i++)
	{
		cin >> a[i];
		q1.push(a[i]);
	}
	int a, b;
	long long res = 0;
	while (q1.size()>1)
	{
		a = q1.top();
		q1.pop();
		res += a;
		b = q1.top();
		q1.pop();
		res += b;
		q1.push(a + b);
		//printf("+ %d\n", a + b);
	}
	//res+= q1.top();
	cout << res << endl;
}