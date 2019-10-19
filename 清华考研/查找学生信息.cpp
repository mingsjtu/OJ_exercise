//https://www.nowcoder.com/practice/fe8bff0750c8448081759f3ee0d86bb4?tpId=40&tqId=21358&tPage=2&rp=2&ru=/ta/kaoyan&qru=/ta/kaoyan/question-ranking
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<map>
#include<algorithm>
using namespace std;
int N;
int M;
string xin[1005];
string hao[1005];
struct xin
{
	int hao;
	string xinxi;
};
int main()
{
	int i=0, j, k;
	map<string,int> x;
	cin >> N;
	int index = 0;
	for (i = 0; i < N; i++)
	{
		cin >> hao[i];
		x[hao[i]] = i;
		getline(cin, xin[i]);
		//cout << hao[i] << xin[i];
	}
	cin >> M;
	string cur;
	while (M--)
	{
		cin >> cur;
		if (x.find(cur) != x.end())
		{
			int tmp = x[cur];
			cout << hao[tmp] << xin[tmp] << endl;
		}
		else
			cout << "No Answer!\n";
	}
}
