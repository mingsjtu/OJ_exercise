//https://blog.csdn.net/da_kao_la/article/details/82425671
#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<map>
using namespace std;
int n;
map<int, int> m1;
struct path
{
	int en;
	int len;
	path* next;
};
int min[100];
bool marked[100];
vector<path> head[100];
void dj(int sta,int en)
{
	int i = 0;
	for (i = 0; i < n; i++)
	{
		min[i] = -1;
		marked[i] = 0;
	}
	min[sta] = 0;
	marked[sta] = 1;
	int newp = sta;
	
	int en1,len1;
	while(marked[en] == 0)
	{
		cout << "newp" << newp;
		int con = 10000;
		for (i = 0; i < head[newp].size(); i++)
		{
			en1 = head[newp][i].en;
			len1 = head[newp][i].len;
			if (marked[en1] == 1)
				continue;
			if (min[en1] == -1 || min[en1] > min[newp] + len1)
			{
				min[en1] = min[newp] + len1;
				

			}
			for (i = 0; i < n; i++)
			{
				if (marked[i] == 1 || min[i] == -1)
					continue;
				if (min[i] < con)
				{
					newp = i;
					con = min[i];
				}
			}
			marked[newp] = 1;
		}
	}

}

int main()
{
	int i, j, en, sta,len;
	int itr = 0;
	char c;
	while (cin>>sta>>en)
	{
		cin >> len;
		if(len == 0)
			break;
		while (m1.find(sta) == m1.end())
		{
			m1[sta] = itr++;
		}
		while (m1.find(en) == m1.end())
		{
			m1[en] = itr++;
		}
		path path1;
		en = m1[en];
		sta = m1[sta];
		path1.en = en;
		path1.len = len;
		head[sta].push_back(path1);
		
		path path2;
		path2.en = sta;
		path2.len = len;
		head[en].push_back(path2);
	}
	n = itr;
	en = m1[en];
	sta = m1[sta];
	cout << "search start\n";
	
	dj(sta,en);
	cout << min[en] << endl;
}