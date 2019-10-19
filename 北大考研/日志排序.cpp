//https://www.nowcoder.com/practice/0f64518fea254c0187ccf0ea05019672?tpId=40&tqId=21363&tPage=2&rp=2&ru=%2Fta%2Fkaoyan&qru=%2Fta%2Fkaoyan%2Fquestion-ranking
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
//hs_10000_p   2007-01-17 19:22:53,315     253.035(s)
struct pix
{
	char name[12];
	int year, month, day, hour, min, second, msecond;
	double length;
	int begin;
}p[10005];
bool cmp1(pix p1, pix p2)
{
	if (p1.length > p2.length)
		return false;
	if (p1.length < p2.length)
		return true;
	if (p1.year > p2.year)
		return false;
	if (p1.year < p2.year)
		return true;
	if (p1.month > p2.month)
		return false;
	if (p1.month < p2.month)
		return true;
	if (p1.day > p2.day)
		return false;
	if (p1.day < p2.day)
		return true;
	if (p1.hour > p2.hour)
		return false;
	if (p1.hour < p2.hour)
		return true;
	if (p1.min > p2.min)
		return false;
	if (p1.min < p2.min)
		return true;
	if (p1.second > p2.second)
		return false;
	if (p1.second < p2.second)
		return true;
	if (p1.msecond > p2.msecond)
		return false;
	if (p1.msecond < p2.msecond)
		return true;
	return false;

}
//class cmp
//{
//public:
//	bool cmp1(pix p1, pix p2)
//	{
//		if (p1.length > p2.length)
//			return false;
//		if (p1.length < p2.length)
//			return true;
//		if (p1.year > p2.year)
//			return false;
//		if (p1.year < p2.year)
//			return true;
//		if (p1.month > p2.month)
//			return false;
//		if (p1.month < p2.month)
//			return true;
//		if (p1.day > p2.day)
//			return false;
//		if (p1.day < p2.day)
//			return true;
//		if (p1.hour > p2.hour)
//			return false;
//		if (p1.hour < p2.hour)
//			return true;
//		if (p1.min > p2.min)
//			return false;
//		if (p1.min < p2.min)
//			return true;
//		if (p1.second > p2.second)
//			return false;
//		if (p1.second < p2.second)
//			return true;
//		if (p1.msecond > p2.msecond)
//			return false;
//		if (p1.msecond < p2.msecond)
//			return true;
//		return false;
//
//	}
//};
int main()
{
	char rub;
	int i=0, j, k;
	//while (cin >> p[i].name >> p[i].year >> rub >> p[i].month >> rub >> p[i].day >> p[i].hour >> rub >> p[i].min >> rub >> p[i].second >> rub >> p[i].msecond >> rub >> p[i].length >> rub >> rub >> rub)
	while(scanf("%s %4d-%2d-%2d %2d:%2d:%2d,%3d %f(s)",&p[i].name,&p[i].year,&p[i].month,&p[i].day,&p[i].hour,&p[i].min,&p[i].second,&p[i].msecond,&p[i].length)!=EOF)
	{
		
		cout << p[i].name << p[i].year << '+' << p[i].month << '+' << p[i].day << '+' << p[i].hour << '+' << p[i].min << '+' << p[i].second << '+' << p[i].msecond << '+' << p[i].length << endl;
		i++;
		//p[i].begin=p[i].year*20+p[i].month*
	}
	cout << "ok\n";
	j = i;
	sort(p, p + i, cmp1);
	for (i = 0; i < j; i++)
	{
		printf("%s   %4d-%2d-%2d %2d:%2d:%2d,%3d     %lf(s)\n", p[i].name, p[i].year, p[i].month, p[i].day, p[i].hour, p[i].min, p[i].second, p[i].msecond, p[i].length);
	}
}