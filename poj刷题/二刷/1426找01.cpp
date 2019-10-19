//http://poj.org/problem?id=1426
#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
#include<bitset> 
#include<vector> 
using namespace std;
int n;
struct a
{
	int yu;
	long long hao;
	//int wei;
};
void BinaryVector(long long n)
{
	long long temp;
	temp = n;
	vector<long long> L;
	while (temp != 0)
	{
		L.push_back(temp % 2);
		temp = temp>>1;
	}
	int leng = L.size(),i;
	for (i=leng-1;i>=0;i--)
		cout<<L[i];
	cout<<endl;
}

void bfs(int x)
{
	a a1 = { 1 % x,1 };
	queue<a> q;
	q.push(a1);
	//printf("shou %d\n",a1.shu[0]);
	a tmpa, tmpn;
	int tmp;
	while (!q.empty())
	{
		tmpa = q.front();
		int yu = tmpa.yu;
		//int wei = tmpa.wei;
		long long hao = tmpa.hao;
		q.pop();
		tmpa.hao = hao * 2;
		//tmpa.wei = wei + 1;
		tmpa.yu = (yu * 10) % x;
		if (!tmpa.yu)
		{
			BinaryVector(tmpa.hao);
			//cout << endl;
			return;
		}
		q.push(tmpa);
		tmpa.hao = hao * 2+1;
		tmpa.yu = (yu * 10+1) % x;
		if (!tmpa.yu)
		{
			BinaryVector(tmpa.hao);

			//cout << endl;
			return;
		}
		q.push(tmpa);
	}

}
int main()
{
	long long  res;
	while (cin >> n)
	{
		bfs(n);
		//printf("%lld\n", res);
		//cout << res << endl;
	}
}