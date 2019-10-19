//http://poj.org/problem?id=1860
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<stack>
#include<vector>
using namespace std;
int n, m;
struct change
{
	int s, e;
	double rab, cab, rba, cba;
	change(int s1=0, int e1=0, double rab=0, double cab=0) :s(s1), e(e1), rab(rab), cab(cab){};
	void init(int s1, int e1, double rab1, double cab1)
	{
		s = s1;
		e = e1;
		rab = rab1;
		cab = cab1;
	}
}cc[305];
double mon[105];
//vector<change> v1[105];
int main()
{
	int i, j, k;
	memset(mon, 0, sizeof(mon));

	cin >> n >> m;
	int s, e;
	double t;
	double rab, cab, rba, cba;
	cin >> s >> t;
	mon[s] = t;
	i = 0;
	change c1, c2;
	while (i<m*2)
	{
		cin >> s >> e >> rab >> cab >> rba >> cba;
		c1.init(s,e,rab,cab);
		cc[i++] = c1;
		c2.init(e, s, rba, cba);
		cc[i++] = c2;
		//v1[s].push_back(c1);
	}
	//cout << i << endl;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < 2*m; j++)
		{
			c1 = cc[j];
			if (mon[c1.e] < (mon[c1.s] - c1.cab)*c1.rab)
			{
				mon[c1.e] = (mon[c1.s] - c1.cab)*c1.rab;
				//printf("update %d from %d is %f\n", c1.e, c1.s,mon[c1.e]);
			}
		}
	}
	bool res = 1;
	for (j = 0; j < 2*m; j++)
	{
		c1 = cc[j];
		if (mon[c1.e] < (mon[c1.s] - c1.cab)*c1.rab)
		{
			res = 0;
		}
	}
	if (!res)
	{
		cout << "YES\n";
	}
	else
	{
		cout << "NO\n";
	}
}