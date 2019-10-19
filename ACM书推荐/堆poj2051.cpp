//http://poj.org/problem?id=2051
#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;
int n, m;
int K;
struct item
{
	int index;
	int time;
	int cur;
	friend bool operator<(const item &a, const item &b)
	{
		if (a.cur > b.cur)
			return true;
		else
		{
			if (a.cur == b.cur&&a.index > b.index)
				return true;
			else return false;
		}
	}
	void operator=(const item &a)
	{
		cur = a.cur;
		time = a.time;
		index = a.index;
	}
		/*
	bool const operator<(const item &a)
	{
		if (cur < a.cur)
			return true;
		else return false;
	}*/
}yuan[1001];


priority_queue<item> q1;

string command;
int main()
{
	int i=0, j;
	while (cin >> command)
	{
		if (command == "#")
			break;
		cin >> yuan[i].index >> yuan[i].time;
		yuan[i].cur = yuan[i].time;
		q1.push(yuan[i]);
		i++;
	}
	//cout << "size" << q1.size() << endl;

	cin >> K;
	j = 0;
	item tmp;
	/*
	while (!q1.empty())
	{
		tmp=q1.top();
		printf("current index %d ,time %d ,cur %d .\n", tmp.index, tmp.time, tmp.cur);
		q1.pop();

	}*/
	
	while (j < K)
	{
		tmp=q1.top();
		//printf("current index %d ,time %d ,cur %d .\n", tmp.index, tmp.time, tmp.cur);
		q1.pop();
		cout << tmp.index << endl;
		tmp.cur = tmp.cur + tmp.time;
		q1.push(tmp);
		j++;
		
	}
	
	

}