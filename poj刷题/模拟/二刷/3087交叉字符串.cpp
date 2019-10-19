//http://poj.org/problem?id=3087
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<string>
#include<map>
using namespace std;
int main()
{
	int t, len, i, j, k;
	char arr1[105], arr2[105], res[220];
	map<string, bool> m1;
	int flag = 0;
	int tt = 0;
	cin >> t;
	while (t--)
	{
		tt++;
		cin >> len;
		scanf("%s", arr1);
		scanf("%s", arr2);
		scanf("%s", res);
		flag = 0;
		int bian = 0;
		int index = 0;
		while (flag == 0)
		{
			bian++;

			char arr[220];
			int pt = 0;
			i = 0;
			for (pt = 0; pt < len; pt++)
			{
				arr[i++] = arr2[pt];
				arr[i++] = arr1[pt];
			}
			arr[i] = '\0';
			//printf("%s\n", arr);
			if (strcmp(arr, res) == 0)
			{
				flag = 1;
				printf("%d %d\n", tt, bian);
				break;
			}
			if (m1[arr] != 0 && strcmp(arr, res) != 0)
			{
				flag = 2;
				printf("%d %d\n", tt, -1);
				break;
			}

			m1[arr] = true;

			i = 0;
			for (pt = 0; pt < len; pt++)
			{
				arr1[pt] = arr[i++];
			}
			for (pt = 0; pt < len; pt++)
			{
				arr2[pt] = arr[i++];
			}
		}

	}
}