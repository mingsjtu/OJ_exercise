///¡¶ÍõµÀ¡·47Ò³
#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<functional>
#include<sstream>

#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<set>
#include<map>

using namespace std;
struct prom
{
	int sta, en;//kaishi and jieshu
	bool operator<(const prom &p1)
	{
		if (en < p1.en)
			return true;
		else return false;
	}
}buf[100];
int main()
{
	int num,i=0;
	while (cin >> num)
	{
		if (num == 0)
			break;
		for (i = 0; i < num; i++)
		{
			cin >> buf[i].sta >> buf[i].en;
		}
		sort(buf, buf + num);
		int whole_prom = 0,con=0;
		for (i = 0; i < num; i++)
		{
			if (buf[i].sta >= con) {
				whole_prom++;
				con = buf[i].en;
			}
		}
		cout << whole_prom << endl;
	}
	return 0;
}