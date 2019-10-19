#include<iostream>
#include<cstring>
using namespace std;
struct big
{
	int dig[1000];
	int len;//weishu
	void init()
	{
		memset(dig, 0, sizeof(dig));
	}
	big jiafa(big d1)
	{
		big res;
		int i, j,tmp,carry=0;
		res.init();
		int nlen = (len > d1.len) ? len : d1.len;
		for (i = 0; i < nlen; i++)
		{
			tmp = carry + dig[i] + d1.dig[i];
			res.dig[i] = tmp % 10;
			carry = tmp / 10;
		}
		if (carry > 0)
		{
			res.len = nlen + 1;
			res.dig[nlen] = carry;
		}
		else {
			res.len = nlen;
		}
		return res;

	}
	big chengfang(big d1)
	{
		big res,res1;
		res.init();
		res1.init();
		int i = 0, j = 0;
		int carry = 0;
		for (i = 0; i < len; i++)
		{
			carry = 0;
			res1.init();
			for (j = 0; j < d1.len; j++)
			{
				int tmp= dig[i] * d1.dig[j]+carry;
				res1.dig[i + j] = tmp % 10;
				carry = tmp / 10;
			}
			if (carry > 0)
			{
				res1.len = d1.len + i+1;
				res1.dig[res1.len - 1] = carry;
			}
			else res1.len = d1.len+i;
			res = res.jiafa(res1);
		}
		return res;
	}
	void display()
	{
		for (int i =len-1; i >= 0; i--)
			cout << dig[i];
		cout << endl;
	}
};
int main()
{
	big d1;
	char ch;
	int d,len=0,tmp[1000];
	int i=0;

	while (cin.get(ch))
	{
		if (ch == '\n')
			break;
		len++;
		tmp[i] = ch-'0';
		i++;

	}
	d1.init();
	d1.len = len;
	for (i = len-1; i >=0; i--)
	{
		d1.dig[len-1-i]=tmp[i];
	}
	cout << "d1 is" << endl;
	d1.display();
	big res=d1.chengfang(d1);
	res = res.chengfang(d1);
	res.display();
}