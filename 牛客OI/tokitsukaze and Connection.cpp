//https://ac.nowcoder.com/acm/contest/1080/A
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
bool use[30];
int main()
{
	char ori[105];
	int i, j, k, n;
	bool flag;
	while (cin >> n >> ori)
	{
		memset(use, 0, sizeof(use));
		flag = true;
		//int len = strlen(ori);
		use[ori[0] - 'a'] = 1;
		for (i = 1; i < n; i++)
		{
			//cout << ori[i] << ' ' << use[ori[i] - 'a'] << endl;
			if (ori[i] != ori[i - 1] && use[ori[i] - 'a'] == 1)
			{
				cout << "NO" << endl;
				flag = false;
				break;
			}
			use[ori[i] - 'a'] = 1;
		}
		if(flag)
		cout << "YES\n";
	}
	
}