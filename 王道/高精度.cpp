#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;
class bigdigit
{

public:

	int digit[1000];
	int size;
	void init()
	{
		memset(digit, 0, sizeof(digit));
		size = 0;
	}
	void set(int x)
	{
		init();
		while (x >= 10000)
		{
			digit[size] = x % 10000;
			x /= 10000;
			size++;
		}
		digit[size++] = x;
	}
	void display()
	{
		for (int i = size - 2; i >= 0; i--)
		{
			printf("%04d", digit[i]);
		}
		printf("%4d", digit[size - 1]);
	}
	bigdigit operator+(const bigdigit &d1)const
	{
		bigdigit res;
		res.init();
		int carry = 0;
		for (int i = 0; i < size; i++)
		{
			carry = (digit[i] + d1.digit[i]) / 10000;
			res.digit[res.size++] = (digit[i] + d1.digit[i]+ carry) % 10000 ;
		}
		if (carry > 0)
			res.digit[res.size++] = carry;
		return res;
	}
	bigdigit operator*(int x)const
	{
		bigdigit res;
		res.init();
		int carry = 0, i = 0, tmp;
		for (i = 0; i < size; i++)
		{
			tmp = digit[i] * x + carry;
			carry = tmp / 10000;
			res.digit[res.size++] = tmp % 10000;
		}
		if (carry != 0)
		{
			res.digit[res.size++] = carry;
		}
		return res;
	}
	int operator%(const int x)const
	{
		int i = 0;
		int re = 0;
		for (i = size - 1; i >= 0; i--)
		{
			int t = (re * 10000 + digit[i]) / x;
			int r = (re * 10000 + digit[i]) % x;
			re = r;
		}
		return re;
	}
	bigdigit operator/(const int x)const
	{
		int i = 0;
		int re = 0;
		bigdigit res;
		res.init();
		for (i = size - 1; i >= 0; i--)
		{
			int t = (re * 10000 + digit[i]) / x;
			int r = (re * 10000 + digit[i]) % x;
			res.digit[i] = t;

			re = r;
		}
		int tmp = size;
		res.size = 0;
		for (i = 0; i <=tmp; i++)
		{
			if (res.digit[i] != 0)
				res.size = i;
		}
		res.size++;
		return res;
	}


}a, b, c;
char str[1000];
char ans[1000];
int main()
{
	int n, m, i = 0, j = 0, t, r;
	bigdigit a, b;
	a.init();
	b.init();
	while (cin >> m >> n)
	{
		cin >> str;
		int len = strlen(str);
		a.set(0);
		b.set(1);
		for (i = 0; i < len; i++)
		{
			if (str[i] <= '9')
				t = str[i] - '0';
			else
			{
				t = str[i] - 'A' + 10;
			}
			a = a + b * t;
			b = b * m;
		}

		char arr[1000];
		i = 0;
		do
		{
			t = a % n;
			a = a / n;
			a.display();
			if (t >= 10)
				arr[i] = t + 'A' - 10;
			else
				arr[i] = t + '0';
			i++;
		} while (a.digit[0] != 0 || a.size !=1);
		int en = i;
		for (i = en - 1; i >= 0; i--)
			cout << arr[i];
	}
	return 0;
}

