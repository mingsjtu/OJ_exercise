//http://poj.org/problem?id=1008
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
using namespace std;
int h1;//day
char h2[20];//month
int h3;//year
const char tmonth[20][12] = { "imix", "ik", "akbal", "kan","chicchan","cimi","manik","lamat","muluk","ok","chuen","eb","ben","ix","mem","cib","caban","eznab","canac","ahau" };
const char hmonth[19][8] = { "pop", "no", "zip", "zotz", "tzec", "xul", "yoxkin", "mol", "chen", "yax", "zac", "ceh", "mac", "kankin", "muan", "pax", "koyab", "cumhu","uayet"};
int ch()
{
	int res = 0;
	res += h3 * 365;
	int i, j, k;
	int mon=-1;
	for (i = 0; i < 19; i++)
	{
		if (strcmp(h2, hmonth[i])==0)
		{
			mon = i;
			//printf("h2 is %d\n", mon);
			break;
		}
	}
	res += mon * 20;
	res += h1;
	return res;
	

}
void ct(int num)
{
	int t3 = num / 260;
	int t1= num % 13+1;
	char t2[12]="12345";
	strcpy(t2,tmonth[num % 20]);
	printf("%d %s %d\n", t1, t2, t3);
}
int main()
{
	int t;
	cin >> t;
	int i, j, k;
	int res;
	printf("%d\n", t);
	while (t--)
	{
		char rub;
		//fflush(stdout);
		scanf("%d%c%s%d", &h1,&rub,h2,&h3);
		/*printf("h1 %d\n", h1);
		printf("h2 %s\n", h2);
		printf("h3 %d\n", h3);*/
		res=ch();
		//cout << res << endl;
		ct(res);
	}
}