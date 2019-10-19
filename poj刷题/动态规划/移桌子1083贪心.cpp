//http://poj.org/problem?id=1083
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
ll cishu[202];//0- 0-1
int n,t;
int sta[202];
int en[202];
int main()
{
	cin >> t;
	int i, j, k;
	while (t-- > 0) 
	{
		memset(cishu, 0, sizeof(cishu));
		cin >> n;
		int a, b;
		for (i = 0; i < n; i++)
		{
			scanf("%d %d", &a, &b);
			sta[i] = a / 2;
			en[i] = b / 2;
			if (sta[i] > en[i])
				swap(sta[i], en[i]);
			//cout << "jiaohuan"<<sta[i] << en[i] << endl;
			for (j = sta[i]; j <= en[i];j++)
			{
				cishu[j]++;
			}
		}
		int res = 0;
		ll mcishu = 0;
		for (i = 0; i < 202; i++)
		{
			if (cishu[i] > mcishu)
			{
				mcishu = cishu[i];
			}
		}
		cout << 10*mcishu << endl;

	}
	

}