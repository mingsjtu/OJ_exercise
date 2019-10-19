//http://bailian.openjudge.cn/jssxly2016/C/
#include<iostream>
#include<cstring>

using namespace std;
int map[1005][1005];
int n,wl=0,hl=0;
int main()
{
	int i = 0, j = 0,i1=0,j1=0;
	cin >> n;
	bool flag = true;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 0&&flag)
			{
				wl = i;
				hl = j;
				flag = false;
			}
		}
	}
	//cout << wl << hl << endl;
	for (i1 = wl; map[i1][hl] == 0 &&i1 < n; i1++) {}
	for (j1 = hl; map[wl][j1] == 0&&j1<n; j1++) {}
	//cout << i1 << j1 << endl;
	cout << (i1 - wl-2)*(j1 - hl-2) << endl;
	return 0;

}