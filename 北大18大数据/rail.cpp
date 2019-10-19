//http://bailian.openjudge.cn/practice/1363/
#include<iostream>
#include<cstdio>
#include<stack>
using namespace std;
int n;
int arr[1000];
int main()
{
	int i,j;
	stack<int> s1;
	while (1) 
	{
		cin >> n;
		if (!n)
			break;
		while (1)
		{
			bool flag = true;
			while (!s1.empty())s1.pop();//qingkong zhan
			cin >> arr[0];
			if (!arr[0])
				break;

			for (i = 1; i < n; i++)
			{
				cin >> arr[i];
	
			}
			

			int idx = 0;//chu qu de
			s1.push(1);
			i = 2;
			while (idx < n)
			{
				if (!s1.empty() && s1.top() == arr[idx])
				{
					{
						s1.pop();
						idx++;
						//cout << "idx"<<idx << endl;
					}
				}
				else
				{
					if (i <= n)
					{
						s1.push(i++);
					}
					else
					{
						flag = false;
						//cout << "err" << endl;
						break;
					}
				}
			}
			if (!flag)
				cout << "No" << endl;
			else
			{
				cout << "Yes" << endl;
			}
		}
		cout << endl;
	}
}