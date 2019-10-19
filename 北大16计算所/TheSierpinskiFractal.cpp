//http://bailian.openjudge.cn/practice/1941/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<math.h>
using namespace std;
int num;
char a[3000][3000];
void draw(int n,int x,int y)
{
	if (n == 1)
	{
		a[x][y] = '/';a[x][y+1]='\\';
		a[x+1][y-1] = '/'; a[x+1][y] = '_'; a[x + 1][y + 1] = '_'; a[x + 1][y + 2] = '\\';
	}
	else
	{
		int index = pow(2, n - 1);
		draw(n - 1,x,y);
		draw(n - 1,x+index, y-index);
		draw(n - 1,x+index, y+index);
	}
}
int main()
{
	while (1) {
		cin >> num;
		if (!num)break;
		memset(a,' ', sizeof(a));
		int all = pow(2, num);
		draw(num, 0, all-1);

		for (int i = 0; i < all; i++)
		{
			for (int j = 0; j <= all * 2; j++)
				cout << a[i][j];
			cout << endl;
		}
		cout << endl;
	}
}