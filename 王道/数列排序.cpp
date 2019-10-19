#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>

using namespace std;
int main()
{
	char s1[1000];
	cin >> s1;
	int arr[1000];
	int i=0,num=strlen(s1);
	for (i = 0; i < num; i++)
	{
		arr[i] = s1[i] - '0';
	}
	bool flag = true;//shi zuidazhi
	for (i = 0; i < num-2; i++)
	{
		if (arr[i] < arr[i + 1])
		{
			flag = false;
			break;
		}
	}
	if (flag)//shi zuichangde 
	{
		for (i = 0; i < num - 1; i++)
			cout << arr[i];
		return 0;
	}

	int min = 9,min_index=num-1;
	for (i = num - 2; i >=0; i--)
	{
		
		if (arr[i] < arr[i + 1])
		{
			for (int j = i + 1; j < num; j++)
			{
				if (arr[j]<min&&arr[j]>arr[i])
				{
					min = arr[j];
					min_index = j;
				}

			}
			arr[min_index] = arr[i];
			arr[i] = min;
			break;
		}
		
	}

	for (int i = 0; i < num; i++)
		cout << arr[i];
	return 0;

}