#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
typedef  long long ll;
ll num;//��ǰ�ҵ���ͬ����������
ll con_dp[100];//��ǰͬ����
ll dp[100];//�ҵ���ͬ����
ll pre_dp[100];//shang yige weishu de tonggoushu
int main()
{
	int m, n;//m���ƣ�di n ge
	cin >> m >> n;
	memset(dp, 0, sizeof(dp));
	memset(pre_dp, 0, sizeof(pre_dp));
	num = 0;
	ll prev = 1,weishu=1,jinzhi=1,con=0;
	do
	{
		//for (int i = 1; i < m; i++)
		//{
		//	if ((i*i) % m == i)
		//	{
		//		cout << i << "is tonggoushu" << endl;
		//		dp[num] = i;
		//		num++;
		//	}//�ҵ���λ����
		//}
		con = 0;
		memset(con_dp, 0, sizeof(con_dp));
		for (int j = 1; j < m; j++)
		{
			for (ll i = 0; i < prev; i++)
			{
				ll tmp = j * jinzhi + pre_dp[i];
				if ((tmp*tmp) % (jinzhi*m) == tmp)
				{
					con_dp[con] = tmp;
					dp[num] = tmp;
					num++;
					
					con++;
					cout << tmp << "is tonggoushu" << endl;
				}
			}
			if (num >= n)
				break;
		}
		prev = con;
		for (ll i = 0; i < con; i++)
		{
			pre_dp[i] = con_dp[i];//shangyige weishu cunru pre_dp

		}
		
		jinzhi *= m;
	} while (num < n);
	cout << dp[n - 1];
}