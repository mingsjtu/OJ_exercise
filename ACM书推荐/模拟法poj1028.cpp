//http://poj.org/problem?id=1028
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<stack>

using namespace std;
int len = 1;
string com[4] = { "BACK", "FORWARD", "VISIT", "QUIT" };
stack<string> f1;
stack<string> b1;
string cur = "http://www.acm.org/";
void deal(string juzi)
{
	int i, j, k;
	for (i = 0; i < 3; i++)
	{
		if (juzi.find(com[i]) != -1)
		{
			if (i == 0) {
				
				if (b1.empty())
				{
					cout << "Ignored" << endl;
				}
				else {
					f1.push(cur);
					cur = b1.top();
					cout << cur << endl;
					b1.pop();
				}
				break;
			}
			if (i == 1)
			{
				if (f1.empty())
				{
					cout << "Ignored" << endl;
				}
				else {
					b1.push(cur);

					cur = f1.top();
					cout << cur << endl;
					f1.pop();
				}
				break;
			}
			if (i == 2)
			{
				b1.push(cur);
				cur = juzi.substr(juzi.find(' ') + 1);
				//cout << "command" << com[i];
				cout << cur << endl;
				while (!f1.empty())f1.pop();
				break;
			}

		}
	}

}

string f[102];//wangzhi forword
string b[102];//wangzhi back
int main()
{
	string tmp;
	while (getline(cin, tmp))
	{
		if (tmp != "QUIT")
		{
			deal(tmp);
			cout << (tmp.find('a')==-1) << endl;
		}
		else break;
	}
	return 0;
}