//http://poj.org/problem?id=1083
#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
int t;
int n;
struct even
{
	int sta, en;
	friend bool operator<(const even &e,const even &e1)
	{
		if (e.en > e1.en)
			return false;
		else return true;
	}
};
even e1[202];

int main()
{
	int i, j, k;
	cin >> t;
	while (t-- > 0)
	{
		cin >> n;
		int a,b;
		for (i = 0; i < n; i++)
		{
			scanf("%d %d", &a,&b);
			if(a<b)
            {
               e1[i].sta=a; e1[i].en=b;
            }
            else
                {
                    e1[i].sta=b; e1[i].en=a;
                }

		}
		sort(e1, e1 + n);
		int ans = 10;
		for (i = 1; i < n; i++)
		{
			if (e1[i].sta <= e1[i - 1].en)
				ans += 10;
		}
		cout << ans << endl;
	}
}
