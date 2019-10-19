//http://bailian.openjudge.cn/jssxly2016/B/
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

char ju[205];
int max = 0;
int min = 150;
int main()
{
	cin.getline(ju, 210, '\n');
	int i = 0,con=0,sta1=0,en1,sta2,en2,j=0;
	for (i = 0; ju[i] != '\0'; i++)
	{
		if (ju[i] != ' '&&ju[i] != ',')
			con++;
		else 
		{
			if (con > max)
			{
				en1 = i;
				max = con;
			}
			if (con < min)
			{
				en2 = i;
				min = con;
			}
			con = 0;
		}
	}

	for (i = en1 - max; i <= en1; i++)
		cout << ju[i];
	cout << endl;
	for (i = en2 - min; i <= en2; i++)
		cout << ju[i];
	cout << endl;


}