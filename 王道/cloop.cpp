//http://bailian.openjudge.cn/practice/2115/
#pragma warning(disable:4996)
#include<iostream>
#include<cstdio>
#include<math.h>
typedef long long ll;
using namespace std;
ll a, b, c, d;
ll exgcd(ll a, ll b, ll& x, ll& y)
{
	if (!b) { x = 1, y = 0; return a; }
	ll d, tx, ty;
	d = exgcd(b, a%b, tx, ty);//bx'+(a%b)y'=1(mod p)
	x = ty, y = tx - (a / b)*ty;//ay'+b(x'-t*y')=1(mod p)
	return d;
}
int main()
{
	while (true) {
		scanf("%lld %lld %lld %lld", &a, &b, &c, &d);
		if (!(a||b||c||d))return 0;
		if (a == b) { cout << 0; continue; }
		ll rex=0, rey=0, gcd;
		int d1 = 2;
		for (int i = 0; i < d; i++)
			d1 = d1 << 1;
		cout << "d1" << d1 << endl;
		gcd = exgcd(c, d1, rex, rey);
		cout << "rex" << rex << endl;
		cout << gcd << "gcd" << endl;
		if ( (a - b)%gcd == 0)
		{
			ll each = d / gcd;
			rex = rex * (b - a) / gcd;
			while (rex < 0)
			{
				rex += each;
			}
		}
		cout << rex << endl;
	}
}
