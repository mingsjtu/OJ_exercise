//https://blog.csdn.net/da_kao_la/article/details/82464298
#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>

using namespace std;
int n, k;
int prime[105];
int main()
{
	int i, j;
	cin >> n >> k;
	priority_queue<int,vector<int>,greater<int>> q;
	for (i = 0; i < n; i++)
	{
		cin >> prime[i];
		q.push(prime[i]);
	}
	int con = 0;
	int tmp,tmp1;
	int last=0;
	while (con <k)
	{
		tmp=q.top();
		q.pop();
		if (tmp == last)
			continue;
		con++;
		cout << "no. " << con << "is " << tmp << endl;
		last = tmp;
		for (i = 0; i < n; i++)
		{
			tmp1 = tmp * prime[i];
			q.push(tmp1);
		}
	}
	cout << last << endl;
}