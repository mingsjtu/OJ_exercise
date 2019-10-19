//
#include<iostream>
#include<cstring>
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;
int n=0;
int num[1000];
char tmp[1000];
int main()
{
	int tmp1;
	int i=0, j, k;
	cin >> tmp;
	n = strlen(tmp);
	for (i = 0; i < n; i++)
	{
		tmp1 = tmp[i] - '0';
		num[i] = tmp1;
	}
	bool flag = false,flag1=false;
	for (i = n - 2; i >= 0 && !flag1; i--)
	{
		cout << i << endl;
		if (num[i + 1] <= num[i])
			continue;
		tmp1 = num[i];
		flag1 = true;
		cout << "find1" << endl;
		for (j = n - 1; j > i && !flag; j--)
		{
			if (tmp1 <num[j])
			{
				cout << "find\n";
				num[i] = num[j];

				num[j] = tmp1;
				flag = true;
			}
		}

	}
	cout << "qidian" << i << endl;
	sort(num + i+2, num + n);
	for (i = 0; i < n; i++)
		cout << num[i];
	cout << endl;
}
	