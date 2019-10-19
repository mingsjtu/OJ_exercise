//https://www.nowcoder.com/practice/761fc1e2f03742c2aa929c19ba96dbb0?tpId=40&tqId=21343&tPage=1&rp=1&ru=%2Fta%2Fkaoyan&qru=%2Fta%2Fkaoyan%2Fquestion-ranking
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<map>
#include<algorithm>
#include<queue>
using namespace std;
int n;
char arr[19];
const char tar[5] = "2012";
struct mys
{
	string s; int test;
};
void dfs(int x)
{
	map<string, bool> m1;
	int i, j, k;
	queue<mys> q1;
	while (!q1.empty())
		q1.pop();
	mys my1;
	my1.s = arr;
	my1.test = 0;
	q1.push(my1);
	m1[arr] = true;
	//printf("n %d\n", n);
	while (!q1.empty())
	{
		my1 = q1.front();
		q1.pop();
		//cout << my1.s << endl;
		
		string newa;
		char tmp;
		for (i = 0; i < n - 1; i++)
		{
			newa=my1.s;
			tmp = newa[i + 1];
			newa[i + 1] = newa[i];
			newa[i] = tmp;
			//if(i==0)
			//cout << newa << endl;
			//cout << newa.find(tar) << endl;
			if (newa.find(tar) != -1)
			{
				//cout << newa << endl;
				printf("%d\n", my1.test + 1);
				return;
			}
			if (m1[newa] == false)
			{
				m1[newa] = true;
				//cout << newa << endl;
				mys my2;
				my2.s = newa;
				my2.test=my1.test+1;
				q1.push(my2);
			}
		}
		//printf("size %d\n", q1.size());
	}
	cout << -1 << endl;
	return;
}
int main()
{
	int i, j, k;
	while (cin >> n)
	{
		cin >> arr;
		if (strstr(arr, tar) != NULL)
		{
			cout <<0<< endl;
			continue;
		}
		char tmp;
		int test = 0;
		bool flag = true;
		
		dfs(1);

	}
}