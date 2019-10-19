#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>

using namespace std;
struct big
{
	int len;
	int digit[100];

};
char d[100];
int n;
bool cmp(int a, int b)
{
	return (a < b);
}
big solve(big b)
{
	int i, j, k,min,index;
	bool flag = 0;
	int index1;
	for (i=b.len-2;i>=0;i--)
	{
		if(b.digit[i]<b.digit[i+1])
		{
			flag = 0;
			index = i;
			cout << i << endl;
			int tmp = b.digit[i];
			sort(b.digit + i, b.digit + n,cmp);
			if (b.digit[i] = tmp)
			{
				b.digit[i] = b.digit[i + 1];
				b.digit[i + 1] = tmp;
			}
			break;
		}
	}


	return b;
}
void display(const big res)
{
	if (res.len != 0)
	{
		for (int i = 0; i < res.len; i++)
			cout << res.digit[i];
	}
}

int main()
{
	int i, j, k;
	cin>>d;
	n = strlen(d);
	big b1;
	for (i = 0; d[i] != '\0'; i++)
	{
		b1.digit[i] = d[i]-'0';
	}
	b1.len = n;
	big res=solve(b1);
	display(res);
}