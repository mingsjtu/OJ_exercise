//ÍõµÀ 59Ò³
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<queue>
using namespace std;
int n;
int a[1000];
int main()
{
	cin >> n;
	int i, j, k;
	priority_queue<int, vector<int>, greater<int>> q1;
	for (i = 0; i < n; i++)
	{
		cin >> a[i];
		q1.push(a[i]);
	}
	int b, c;
	int res = 0;
	while (q1.size()>=2)
	{
		b = q1.top();
		q1.pop();
		c = q1.top();
		q1.pop();
		res += b + c;
		q1.push(b + c);
	}
	//res += q1.top();
	cout << res << endl;
	


}