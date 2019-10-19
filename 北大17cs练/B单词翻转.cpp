//http://bailian.openjudge.cn/practice/4104/
#include<iostream>
#include<cstdio>
#include<stack>
#include<cstring>
using namespace std;
char juzi[505];
char word[505];
char kongge;
stack<char> w;
int main()
{
	int n,i=0;
	int kong = 0;
	cin.getline(juzi, 505, '\n');
	//getchar();
	n = strlen(juzi);
	//cout << n << endl;
	for (int i = 0; i < n; i++)
	{
		//cout << i << endl;
		
		if (juzi[i] != ' ')
			w.push(juzi[i]);
		else
		{
			while (!w.empty())
			{
				cout << w.top();
				w.pop();
			}
			cout << ' ';
		}
	}
	while (!w.empty())
	{
		cout << w.top();
		w.pop();
	}
	cout << endl;
	return 0;


}