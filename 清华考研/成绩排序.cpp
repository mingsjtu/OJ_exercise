//https://www.nowcoder.com/practice/0383714a1bb749499050d2e0610418b1?tpId=40&tqId=21333&tPage=1&rp=1&ru=/ta/kaoyan&qru=/ta/kaoyan/question-ranking
#include<iostream>
#include<cstdio>
#include<queue>
#include<algorithm>
#include<string>

using namespace std;
typedef long long ll;

struct stu
{
	string name;
	int score;
	int xu;
};
class cmp1
{
public:
	bool operator()(stu s1, stu s2) const
	{
		if (s1.score < s2.score)
		{
			return false;
		}

		if (s1.score == s2.score&&s1.xu < s2.xu)
			return false;
		return true;
	}
};
class cmp0
{
public:
	bool operator()(stu s1, stu s2) const
	{
		if (s1.score < s2.score)
		{
			return true;
		}

		if (s1.score == s2.score&&s1.xu > s2.xu)
			return true;
		return false;
	}
};

priority_queue<stu, vector<stu>, cmp0> q0;
priority_queue<stu, vector<stu>, cmp1> q1;

int main()
{
	stu s[105];
	//char n[20];
	int i = 0, num, moshi;
	stu tmp;
	while (cin >> num) {
		int type;
		cin >> type;
		if (type == 0)
		{
			for (i = 0; i < num; i++)
			{
				cin >> tmp.name >> tmp.score;
				tmp.xu = i;
				q0.push(tmp);
				//printf("name %d score %d\n",s[i].name,s[i].score);
			}
			while (!q0.empty())
			{
				tmp = q0.top();
				cout << tmp.name <<' '<< tmp.score << endl;
				q0.pop();
			}
		}
		else
		{
			for (i = 0; i < num; i++)
			{
				cin >> tmp.name >> tmp.score;
				tmp.xu = i;
				q1.push(tmp);
				//printf("name %d score %d\n",s[i].name,s[i].score);
			}
			while (!q1.empty())
			{
				tmp = q1.top();
				cout << tmp.name <<' '<< tmp.score << endl;
				q1.pop();
			}
		}

	}
	return 0;
}
