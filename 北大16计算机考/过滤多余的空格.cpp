//B:过滤多余的空格
#include<iostream>
#include<cstring>
using namespace std;
char ju[205];
int main()
{
	cin.getline(ju,205,'\n');
	int n = strlen(ju), i = 0;
	bool flag = false;
	for (i = 0; i < n; i++)
	{
		if (ju[i] == ' ' && flag == false)
		{
			cout << ' ';
			flag = true;
		}
		if (ju[i] != ' ') 
		{
			cout << ju[i]; 
			flag = false;
		}
	}
}