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
	for (i = 1; i <= m; i++)//һ��Ҫ���������ӵ�˳�򡣡���Ҳ��֪��Ϊʲô��˵�õ�����һ�������أ�
		cin >> b[i];
	cin >> n;
	for (i = 1; i <= n; i++)
		cin >> a[i];
	ans = 0;
	for (i = 1; i <= n; i++)//��i���ڣ���j��β
	{
		mx = 0; locay = 0;
		for (j = 1; j <= m; j++)
		{
			dp[i][j] = dp[i - 1][j];//���Ǽ��ˣ�����Ҫ��֤��i��jΪֹ����󳤶Ȳ�����С��i-1��j��
			pre[i][j] = j;//ֻҪ��һ������Ϊ׼��סpre�Ϳ���
			//i���䣬����j����ʱҪ��֤j����ֵҪС
			//�ſ������������У�����k��ѭ�����������������棩
			if (a[i] > b[j] && mx < dp[i - 1][j])
			{
				mx = dp[i - 1][j];//��¼dp[i-1][0~j]�����ֵ������ʡȥ�ڲ�k��ѭ��
				locay = j;//��¼��ʱ��jֵ
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
	for (j = 2; j <= m; j++)//����һλ���飬���������е�ĩβΪֹ��Ҳ�����������ans����ʱ��ס
		if (dp[n][j] > dp[n][t])
			t = j;
	int top = 0;
	i = n; j = t;
	while (dp[i][j])//=0Ϊֹ
	{
		while (a[i] != b[j] && i) i--;//�ҵ�һ����ȵ�ֵΪֹ
		z[top++] = b[j];
		j = pre[i][j];
	}
	for (i = top - 1; i >= 0; i--)
		cout << z[i] << " ";
	cout << endl;
	return 0;
}
