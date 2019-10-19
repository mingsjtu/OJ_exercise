#pragma warning(disable:4996)
#include<iostream>
#include<cstdio>
///王道考研论坛，第23页
using namespace std;
int weekday[5000][12][32];
bool isrun(int y)
{
	if (y % 4 == 0 && y % 100 != 0||y%400==0)
		return true;
	else
		return false;
}
const int m_day[12][2] = {
	31,31,
	28,29,
	31,31,
	30,30,
	31,31,
	30,30,
	31,31,
	31,31,
	30,30,
	31,31,
	30,30,
	31,31,
};
char month[12][10] = { "January","February","March","April", "May", "June", "July", "August", "September", "Octomber", "November", "December" };
char week1[7][10]={ "Monday", "Tuseday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday" };
void solve()
{
	int cnt = 0;
	memset(weekday, 0, sizeof(weekday));
	for(int i=0;i<5000;i++)
		for(int j=0;j<12;j++)
			for (int r = 0; r<m_day[j][isrun(j)]; r++)
			{
				cnt++;
				weekday[i][j][r] = cnt;
			}
}
int main()
{
	//solve();
	int i, j, k, r;
	char s[10];
	int y1, y2,m1,m2,d1,d2;
	scanf("%d %s %4d", &d1, s,100 ,&y1);
	for (i = 0; i < 12; i++)
	{
		if (strcmp(s, month[i]))
		{
			m1 = i;
			break;
		}
	}
	fflush(stdin);
	scanf_s("%d %s %4d", &d2, s, &y2);
	for (i = 0; i < 12; i++)
	{
		if (strcmp(s, month[i]))
		{
			m2 = i;
			break;
		}
	}
	printf("%d %d %d\n", d1, m1, y1);
	printf("%d %d %d\n", d2, m2, y2);
	return 0;
}