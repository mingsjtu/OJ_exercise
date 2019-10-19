//http://poj.org/problem?id=1416
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<math.h>
using namespace std;
int tar = 0;
char ju[6];
int num[6];
int n;
int res = 0;
bool flag;
int fang = 0;
int sum;
void dfs(int sta, int left,int f)
{
	//printf("sta%d res%d,tar-left %d,f%d\n", sta,res,tar-left, f);
	if (sta == n)
	{
		if (tar - left == res && res != 0)
		{
			flag = true;
		}
		else
		{
			if (tar - left > res)
			{
				res = tar - left;
				flag = false;
				fang = f / 10;
				//printf("res %d,fang %d\n", res, fang);
			}
		}
		return;

	}
	
	int i, j, k;
	int cur = 0;
	/*if (num[sta] == 0)
	{
		//printf("0 fang%d,left%d, fang1%d\n", f,left, f*10+sta+1);
		dfs(sta + 1, left, f * 10 + sta + 1);
	}
	else
	{*/
	/*int tmp1 = n - 1 - sta;
	int tmp = sum % int(pow(10,tmp1));
	printf("tmp %d\n", tmp);
	if (tmp <= left)
	{
		if (tar - left + tmp > res)
		{
			res = tar - left + tmp;
			fang = f;
			flag = false;
			//printf("res %d,fang %d\n", res, fang);

			return;
		}
		
	}*/
	
	for (i = sta; i < n; i++)
		{
			if (cur * 10 + num[i] <= left)
			{
				dfs(i+1, left - cur * 10 - num[i],f*10+i+1);
			}
			/*if (cur * 10 + num[i] == left)
			{
				if (i == n - 1)
				{
					res = tar;
					return;
				}
				bool tmp = false;
				for (j = i+1; j < n; j++)
				{
					if (num[j] != 0)
					{
						tmp = true;
						break;
					}
				}
				if (tmp)
					break;
				else
				{
					printf("==\n", f);
					fang = f*10+i+1;
					res = tar;
					printf("res %d,fang %d\n", res, fang);

					return;
				}
				
			}
			*/
			if (cur * 10 + num[i] > left)
				break;
			cur = cur * 10 + num[i];
		}
	//}
}
void output(int f)
{
	bool vis[6];
	memset(vis, 0, sizeof(vis));
	while (fang > 0)
	{
		vis[fang % 10-1] = 1;
		fang /= 10;
	}
	for (int i = 0; i < n; i++)
	{
		printf("%d", num[i]);
		if (vis[i] == 1)
			cout << ' ';
	}
	cout << endl;
}
int main()
{
	int i, j, k;
	while (cin >> tar)
	{
		flag = false;
		res = 0;
		scanf("%s", ju);
		n = strlen(ju);
		for (i = 0; i < n; i++)
		{
			num[i] = ju[i] - '0';
		}
		sum = 0;
		for (i = 0; i < n; i++)
		{
			sum = sum * 10 + num[i];
		}
		if (sum == tar)
		{
			printf("%d %d\n", tar,tar);
			continue;
		}
		dfs(0, tar,0);
		if (!flag)
		{
			if (res > 0)
			{
				printf("%d ", res);
				//printf("fang %d\n", fang);
				output(fang);
			}
			else
				printf("error\n");
		}
		else
			printf("rejected\n");
	}


}