//http://poj.org/problem?id=3122
#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
int r[10005]; 
int n, f;
const double pi = 3.14159265359;
bool check(double x)
{
	int i,j,k;
	int sum = 0;
	for (i = 0; i < n; i++)
	{
		if (r[i] >= x)
		{
			sum += int(r[i]/x );
			//printf("check %lf , sum %d\n", x, sum);

		}
	}
	//printf("check %lf , sum %d\n", x, sum);
	if (sum >= f)
		return true;
	return false;
}
int main()
{
	int t;
	
	cin >> t;
	int i, j, k,maxx=0;

	priority_queue<int,vector<int>,greater<int> > pie;
	while (t--)
	{
		maxx = 0;
		cin >> n >> f;
		f++;
		int rt;
		for (i = 0; i < n; i++)
		{
			cin >> rt;
			r[i]=rt*rt;
		
			if (maxx < r[i])
			{
				maxx = r[i];
			}
		}
		int sum = 0;
		
		double high = 2*maxx;
		double low = 0;
		double mid=0;
		while (high - low > 1e-8)
		{
			mid = (high + low) / 2;
			if (check(mid))
			{
				low = mid;
			}
			else
			{
				high = mid;
			}
		}
		cout << mid*pi << endl;
	}
}