#include<iostream>
#include<algorithm>
#include<string.h>
#include<string>
using namespace std;
long long a[501], b[501], z[501];
int dp[501][501] = { 0 }, pre[501][501];
int main()
{
	int n, m, i, ans, j, mx, locay;
	cin >> m;
	for (i = 1; i <= m; i++)//一定要按输入例子的顺序。。。也不知道为什么，说好的任意一个序列呢！
		cin >> b[i];
	cin >> n;
	for (i = 1; i <= n; i++)
		cin >> a[i];
	ans = 0;
	for (i = 1; i <= n; i++)//在i以内，以j结尾
	{
		mx = 0; locay = 0;
		for (j = 1; j <= m; j++)
		{
			dp[i][j] = dp[i - 1][j];//忘记加了！首先要保证到i、j为止的最大长度不可能小于i-1，j的
			pre[i][j] = j;//只要以一个序列为准记住pre就可以
			//i不变，遍历j，此时要保证j序列值要小
			//才可以是上升序列（即把k的循环查找条件调到外面）
			if (a[i] > b[j] && mx < dp[i - 1][j])
			{
				mx = dp[i - 1][j];//记录dp[i-1][0~j]的最大值，可以省去内层k的循环
				locay = j;//记录此时的j值
			}
			else if (a[i] == b[j])
			{
				dp[i][j] = mx + 1;
				pre[i][j] = locay;
			}
			ans = max(ans, dp[i][j]);
		}
	}
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= m; j++)
		{
			printf("dp[%d][%d] is %d ,pre is %d\n", i, j, dp[i][j], pre[i][j]);
		}
	}
	cout << ans << endl;
	int t = 1;
	for (j = 2; j <= m; j++)//看作一位数组，找最大的序列的末尾为止，也可以在上面的ans更新时记住
		if (dp[n][j] > dp[n][t])
			t = j;
	int top = 0;
	i = n; j = t;
	while (dp[i][j])//=0为止
	{
		while (a[i] != b[j] && i) i--;//找到一个相等的值为止
		z[top++] = b[j];
		j = pre[i][j];
	}
	for (i = top - 1; i >= 0; i--)
		cout << z[i] << " ";
	cout << endl;
	return 0;
}
