//http://poj.org/problem?id=2082
#include<iostream>
#include<cstdio>
#include<cstring>
#include<stack>
using namespace std;

int n;
//int w[50005];
//int h[50005];
struct juxing
{
	int w, h;
}ju[50005];
int main()
{
	stack<juxing> s1;
	int i, j, k;
	int totalw = 0;
	int curm = 0;
	int ans=0;
	juxing tmp;
	int lasth;
	while (cin >> n)
	{
		totalw = 0;
		ans = 0;
		if (n == -1)
			return 0;
		lasth = 0;
		for (i = 0; i < n; i++)
		{
			cin >> ju[i].w >> ju[i].h;
				totalw = 0;
				while (!s1.empty()&&s1.top().h > ju[i].h)
				{
					totalw += s1.top().w;
					curm = totalw * s1.top().h;
					//cout << "current curm  " << curm << endl;
					ans = ans > curm ? ans : curm;
					s1.pop();
				}
				
				tmp.h = ju[i].h;
				tmp.w = totalw + ju[i].w;
				s1.push(tmp);
		}
		int totalw = 0;
		while (!s1.empty())
		{
			totalw += s1.top().w;
			int tmp = totalw * s1.top().h;
			//cout << "current curm  " << tmp << endl;

			if (tmp > ans)
				ans = tmp;
			s1.pop();

		}
		cout << ans << endl;
	}

}