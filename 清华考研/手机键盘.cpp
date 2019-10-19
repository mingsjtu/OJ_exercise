//https://www.nowcoder.com/practice/20082c12f1ec43b29cd27c805cd476cd?tpId=40&tqId=21337&tPage=1&rp=1&ru=%2Fta%2Fkaoyan&qru=%2Fta%2Fkaoyan%2Fquestion-ranking
#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
char tar[105];
const int dui[26] = { 1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,4,1,2,3,1,2,3,4 };
const int zu[26] = { 1,1,1,2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,6,7,7,7,8,8,8,8};
int main()
{
	int i, j, k, len;
	int res = 0;
	while (cin>>tar)
	{
		res = 0;
		len = strlen(tar);
		res+=dui[tar[0]-'a'];
		for (i = 1; i < len; i++)
		{
			if (zu[tar[i] - 'a']==zu[tar[i-1] - 'a'])
				res += 2;
			res += dui[tar[i] - 'a'];
			//cout << dui[tar[i] - 'a']<< endl;
		}
		cout << res << endl;
	}
}