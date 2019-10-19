//http://bailian.openjudge.cn/xly2019/C/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
struct state
{
	int e, step;
	string sol;
	state(int e1, int s1, string ss1)
	{
		e = e1;
		step = s1;
		sol = ss1;
	}
	state() = default;
};
vector<string> result;
queue<state> qs;
int main()
{
	int i, j, k,s,e;
	while (cin >> s >> e)
	{
		if (!result.empty())
			result.clear();
		while (!qs.empty())
			qs.pop();
		state cur(s, 0, "");
		qs.push(cur);
		int res = 0;
		//state n1, n2;
		bool flag = false;
		int minn = 100000;
		while (!qs.empty())
		{
			cur = qs.front();
			qs.pop();
			//printf("cur e%d cur step%d\n", cur.e, cur.step);
			if (cur.e == e && cur.step <= minn)
			{
				flag = true;
				minn = cur.step;
				//cout << "ok " << cur.sol << endl;
				result.push_back(cur.sol);
			}
			if (!flag)
			{
				if (cur.e / 2 > 0)
				{
					state n1(cur.e / 2, cur.step + 1, cur.sol + "O");
					qs.push(n1);
				}
				if (cur.e * 3 < e * 9)
				{
					state n1(cur.e * 3, cur.step + 1, cur.sol + "H");
					qs.push(n1);
				}
			}

		}
		string mins = result[0];
		//printf("result %d\n", result.size());
		for (i = 1; i < result.size(); i++)
		{
			mins = min(mins, result[i]);
		}
		cout << mins << endl;
	}
	
}