//http://poj.org/problem?id=1860
#include<iostream>
#include<cstring>
#include<cstdio>
#include<string>
#include<vector>
using namespace std;
int S, N, M;
double V;
struct edge
{
	int sta, en;
	float rab, cab;

}e[105];
int d[105];
bool flag = false;
int cs, ce;
float crab, ccab, crba, ccba;
int main()
{
	cin >> N >> M >> S >> V;
	int i, j, k;
	
	i = 0;
	for (j = 0; j < M; j++)
	{
		cin >> cs >> ce >> crab >> ccab >> crba >> ccba;
		e[i].sta = cs;
		e[i].en = ce;
		e[i].rab = crab;
		e[i].cab = ccab;
		i++;
		e[i].sta = ce;
		e[i].en = cs;
		e[i].rab = crba;
		e[i].cab = ccba;
		i++;

	}
	cout << "I" << i << endl;
	memset(d, 0, sizeof(d));
	d[S] = V;
	bool wending = true;
	for (i = 0; i < N-1; i++)
	{
		wending = true;
		for (j = 0; j < M*2; j++)
		{
			if (d[e[j].en] < (d[e[j].sta] - e[j].cab)*e[j].rab)
			{
				d[e[j].en] = (d[e[j].sta] - e[j].cab)*e[j].rab;
				//wending = false;
			}
		}
		//if (wending)
			//break;
	}
	for (i = 0; i < M*2; i++)
	{
		if (d[e[j].en] < (d[e[j].sta] - e[j].cab)*e[j].rab)
			flag = true;
	}
	if (flag)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
}
