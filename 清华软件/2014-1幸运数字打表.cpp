//https://blog.csdn.net/zhonghuan1992/article/details/39718161
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
int n;
int ser[98] = { 14,41,1144,1414,1441,4114,4141,4411,111444,114144,114414,114441,141144,141414,141441,144114,144141,144411,411144,411414,411441,414114,414141,414411,441114,441141,441411,444111,11114444,11141444,11144144,11144414,11144441,11411444,11414144,11414414,11414441,11441144,11441414,11441441,11444114,11444141,11444411,14111444,14114144,14114414,14114441,14141144,14141414,14141441,14144114,14144141,14144411,14411144,14411414,14411441,14414114,14414141,14414411,14441114,14441141,14441411,14444111,41111444,41114144,41114414,41114441,41141144,41141414,41141441,41144114,41144141,41144411,41411144,41411414,41411441,41414114,41414141,41414411,41441114,41441141,41441411,41444111,44111144,44111414,44111441,44114114,44114141,44114411,44141114,44141141,44141411,44144111,44411114,44411141,44411411,44414111,44441111 };
bool ok(int x)
{
	int x1=0, x4=0;
	int tmp;
	while (x > 0)
	{
		tmp = x % 10;
		if (tmp != 1 && tmp != 4)
			return false;
		if (tmp == 1)
			x1++;
		if (tmp == 4)
			x4++;
		x /= 10;
		
	}
	if (x1 == x4)
		return true;
	else
		return false;
}
int myfind(int s, int e)
{
	//printf("s %d,e %d\n", s, e);
	if (e - s <= 1)
	{
		if (ser[e] <= n)
			return e;
		else
			return s;
	}
	int m = (s + e) / 2;
	if (ser[m] <= n)
	{
		return myfind(m,e);
	}
	else
	{
		return myfind(s,m-1);
	}
}
int main()
{
	int i;
	int res = 0;
	while (cin >> n)
	{
		if (n < 14)
		{
			cout << -1 << endl;
			continue;
		}
		int res=myfind(0, 97);
		cout << ser[res] << endl;
	}
	
	/*for (i = 14; i < 1e9; i++)
	{
		if (ok(i))
		{
			printf("%d,", i);
			n++;
		}
	}*/
	return 0;
	/*while (cin >> n)
	{
		res = 1;
		if (n < 14)
		{
			printf("-1\n");
			return 0;
		}
		for (i = n; i >= 14; i--)
		{
			res = ok(i);
			if (res)
			{
				printf("%d\n", i);
				break;
			}
		}
	}*/
	
	return 0;
}