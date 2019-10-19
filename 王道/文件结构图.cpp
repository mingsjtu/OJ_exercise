//http://bailian.openjudge.cn/xlylx2017/D/
#pragma warning(disable:4996)
#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
#include<string>
using namespace std;
priority_queue <string, vector<string>, greater<string> > q1[1005];
//queue<string> q1[100];
int d_num=0;
int f_num[100];

int main()
{
	int mark=1;
	bool flag = false;
	int tab = 1;
	string tmp,tmp1;
	while (cin >> tmp)
	{
		if (d_num == 0&&flag==false)
		{
			printf("DATA SET %d:\nROOT\n", mark);
			flag = true;
			mark++;
		}
		if (tmp[0] == 'd')
		{
			
			for (int i = 0; i < tab; i++)
			{
				printf("|"); 
				cout << "     ";
			}
			cout << tmp << endl;
			d_num++;
			tab++;
		}
		if (tmp[0] == 'f')
		{
			
			q1[d_num].push(tmp);
			f_num[d_num]++;
		}
		if (tmp[0] == ']')
		{
			while (!q1[d_num].empty())
			{
				for (int i = 0; i < tab-1; i++)
				{
					printf("|");
					cout << "     ";
				}
				tmp1 = q1[d_num].top();
				cout << tmp1<<endl;
				q1[d_num].pop();
			}
			d_num--;
			tab--;
		}
		if (tmp == "*")
		{
			while (!q1[d_num].empty())
			{
				tmp1 = q1[d_num].top();
				cout << tmp1 << endl;
				q1[d_num].pop();
			}
			tab = 0;
			flag = false;
			d_num = 0;
			cout << endl;
		}
		if (tmp == "#")
			break;
	}
	return 0;
}