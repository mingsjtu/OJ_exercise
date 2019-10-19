#include<iostream>
#include<cstring>
#include<stdio.h>
#include<cstdio>

using namespace std;

struct bigdata
{
	const int maxn = 1010;
	int n, data[1010];
	bigdata &operator=(const bigdata d1)
	{
		n = d1.n;
		for (int i = 0; i < 1010 - 1; i++)
			data[i] = d1.data[i];
		return *this;
	}
	bool compare(const bigdata &d1)const//return true for d1>=this
	{
		if (d1.n != n)
		{
			if (d1.n > n)
				return true;
			else
				return false;
		}
		else
		{
			int i;
			for (i = d1.n - 1; i >= 0; i--)
			{
				if (d1.data[i] > data[i])
					return true;
				if (d1.data[i] < data[i])
					return false;
			}
			return true;
		}
	}
	bigdata operator-(const bigdata &d1)const
	{
		bigdata res;
		int beijian;
		if (compare(d1))
			beijian = 1;
		else beijian = 0;
		res.n = (d1.n > n) ? d1.n : n;
		memset(res.data, 0, sizeof(res.data));
		if (beijian)//d1-this
		{
			int tmp = 0;
			for (int i = 0; i<res.n; i++)
			{
				if (i > n-1)
				{
					res.data[i] = d1.data[i]+res.data[i];
				}
				else
				{
					tmp= d1.data[i] - data[i]+res.data[i];
					if (tmp < 0)
					{
						res.data[i + 1] = -1;
						res.data[i] = 10 + tmp;
					}
					else res.data[i] = tmp;

				}
			}
		}
		else
		{
			int tmp = 0;
			for (int i = 0; i < res.n; i++)
			{
				if (i > n - 1)
				{
					res.data[i] = data[i] + res.data[i];
				}
				else
				{
					tmp = data[i] - d1.data[i] + res.data[i];
					if (tmp < 0)
					{
						res.data[i + 1] = -1;
						res.data[i] = 10 + tmp;
					}
					else res.data[i] = tmp;

				}
			}

		}
		res.quling();
		return res;
	}
	void getinput()
	{
		memset(data, 0, sizeof(data));
		char tmp[205];
		int i = 0;
		cin >> tmp;
		int len = strlen(tmp);
		for (i = len - 1; i >= 0; i--)
		{
			data[i] = tmp[len - i -1 ]-'0';
		}
		n = len;
		cout << "get" << endl;

	}
	bigdata mul(const bigdata &obj,bigdata &res)const
	{
		//cout<<obj.n; 
		int i = 0, j = 0,tmp=0,jinwei=0;
		res.n = n + obj.n;
		memset(res.data, 0, sizeof(res.data));
		for (i = 0; i < obj.n; i++)
		{
			for (j = 0; j < n; j++)
			{
				//cout << data[j] << obj.data[i] << endl;
				tmp = data[j] * obj.data[i]+res.data[i+j];
				
				cout <<data[j] << obj.data[i]<< "tmp" << tmp << endl;
				if (tmp >=10)
				{
					res.data[j+i] = tmp%10;
					res.data[j+i+1]+= tmp / 10;
				}
				else
				res.data[i+j]=tmp;
			}
			
		}
		res.quling();

//		for (int i = res.n-1; i>=0; i--)
//		{
//			cout << char(res.data[i] + '0');
//		}

		return res;
	}
	void quling()
	{
		int i = n-1;
		while (data[i] == 0)
			i--;
		n = i+1;
	}
	void display()
	{

		for (int i =n-1; i>=0; i--)
		{
			cout << char(data[i] + '0');
		}
	}
	
};
int main()
{
	bigdata d1, d2,d3;
	d1.getinput();
	d2.getinput();
	d3=d1-d2;
	d3.display();
	return 0;
	
}
