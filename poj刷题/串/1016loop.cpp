//http://poj.org/problem?id=1016
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
#include<stack>
using namespace std;
int lei;//
//0-n is self-inventorying 
//1-n is self - inventorying after j steps
//2-n enters an inventory loop of length k
//3-n can not be classified after 15 iterations
int dfs(string s1)
{
	int len=s1.length();
	lei = 0;
	int i, j, k;
	int geshu[10];
	string con[16];
	int t=0;
	con[0] = s1;
	string tmp;
	int res;
	memset(geshu, 0, sizeof(geshu));
	stack<int> getmp;
	while (t < 15)
	{
		len = s1.length();
		res = -1;
		memset(geshu, 0, sizeof(geshu));
		t++;
		for (i = 0; i < len; i++)
		{
			//cout << s1[i] - '0' << endl;
			geshu[int(s1[i] - '0')]+=1;
		}
		for (i = 0; i <=9; i++)
		{
			//printf("geshu[%d] is %d\n", i, geshu[i]);
			if (geshu[i] == 0)
				continue;
			while (!getmp.empty())
				getmp.pop();
			while (geshu[i] > 0)
			{
				getmp.push(geshu[i] % 10);
				geshu[i] /= 10;
			}
			while (!getmp.empty())
			{
				con[t].append(1, getmp.top() + '0');
				getmp.pop();
			}
			con[t].append(1, i + '0');
		}
		
		s1 = con[t];
		//cout << s1 << endl;
		for (i = t-1; i>=0; i--)
		{
			if (s1 == con[i])
			{
				res = i;
				if (res ==0&&t==1)
				{
					lei = 0;
					return 0;
				}
				if (res == t - 1)
				{
					lei = 1;
					return t-1;
				}
				else
				{
					lei = 2;
					return t-res;
				}
			}
		}
	}
	if (res == -1)
	{
		lei = 3;
		return 0;
	}
}
int main()
{
	string ori;
	while (1)
	{
		cin >> ori;
		if (ori == "-1")
		{
			//cout << endl;
			break;
		}
		int result = dfs(ori);
		cout << ori;
		switch (lei)
		{
		case 0:
			printf(" is self-inventorying \n");
			break;
		case 1:
			printf(" is self-inventorying after %d steps \n",result);
			break;
		case 2:
			printf(" enters an inventory loop of length %d \n",result);
			break;
		case 3:
			printf(" can not be classified after 15 iterations \n");
			break;
		}
	}
	
}