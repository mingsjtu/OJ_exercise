//http://acm.hdu.edu.cn/showproblem.php?pid=1230
#pragma warning(disable:4996)
#include<iostream>
#include<cstring>
#include<cmath>
#include<string>
using namespace std;
int pri[25];
bool isprime(int n)
{
	int i = 2,bound=sqrt(n)+1;
	if (n == 2)return true;
	for (i = 2; i <= bound; i++)
	{
		if (n%i == 0)
			return false;
	}
	return true;
}
void prime()
{
	int i = 2,cnt=0;
	for (i = 2; cnt < 25; i++)
	{
		if (isprime(i))
		{
			pri[cnt] = i;
			cnt++;
		}
		
	}
}
struct lll
{
	int leng;
	int digit[100];
	void init()
	{
		leng = 0;
		memset(digit, 0, sizeof(digit));
	}
	lll operator+(lll &num)
	{
		lll res;
		int i, j;
		res.init();
		int carry = 0;
		int leng1 = (leng > num.leng) ? leng:num.leng;
		for (i = 0; i < leng1; i++)
		{
			int tmp = digit[i] + num.digit[i] + carry;
			carry = tmp / pri[i];
			res.digit[i] = tmp % pri[i];
		}
		
		res.leng = leng1;
		if (carry > 0)
		{
			res.leng++;
			res.digit[res.leng - 1] = carry;
		}
		return res;
	}
	void display()
	{
		if (leng > 1) {
			for (int i = leng - 1; i > 0; i--)
				cout << digit[i]<<',';
			cout<< digit[0] << endl;
		}
		else cout << digit[0] << endl;

	}
};
lll change(char* s)
{
	int l = strlen(s),dq = 0;//dangqian shuzi weidian
	int i, j,w=1;
	int num = 0;
	lll res;
	res.init();
	for (i = 0; i < l; i++)
	{
		if (s[i] == ',')
			res.leng++;
	}
	res.leng++;
	int con=res.leng-1;
	for (i = 0; i <=l; i++)
	{
		if (s[i] == ','||s[i]=='\0')
		{
			
			num = 0;
			for (j = dq; j < i; j++)
			{
				num = num * 10 + (s[j] - '0');
			}
			res.digit[con--] = num;
			dq = i + 1;
		}
	}
	
	return res;
}
char s1[105], s2[105];

int main()
{
	prime();
	lll n1, n2;
	n1.init();
	n2.init();
	char ch;
	int con;
	int leng1=0, leng2=0;
	for (int i = 0; i < 25; i++)
	while (cin>>s1>>s2)
	{

		int sl1 = strlen(s1), sl2 = strlen(s2);
		n1 = change(s1);
		n2 = change(s2);
		lll res = n1 + n2;
		res.display();
	}
}