#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
int k, num,con=0;
int zhishu[105];
int main()
{
	int i, j;
	cin >> num >> k;
	for (i = 0; i < num; i++)
	{
		cin >> zhishu[i];
	}
	priority_queue<int, vector<int>, greater<int>> q1;
	for (i = 0; i < num; i++)
		q1.push(zhishu[i]);
	con = num;
	int tmp,new1,res=0;
	while (con < k)
	{
			tmp = q1.top();
			cout << tmp;
			q1.pop();
		for (i = 0; i < num; i++)
		{
			con++;
			new1 = tmp * zhishu[i];
			q1.push(new1);
			if (con == k)
			{
				res = new1;
				break;
			}
		}
		cout << res << endl;
	}
}