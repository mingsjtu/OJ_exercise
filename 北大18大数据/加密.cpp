//http://bailian.openjudge.cn/dsj2018xly/B/
#include<iostream>
#include<cstring>
#include<cstdio>
#include<math.h>
using namespace std;

char map[26];//map[1]->Ademizi
char str1[105], str2[105], str3[105],des[105];
int main()
{
	bool flag = true;
	memset(map, '#', sizeof(map));
	while (cin >> str1 >> str2 >> str3) {
		memset(map, '#', sizeof(map));
		flag = true;
		int l1 = strlen(str1), i;
		for (i = 0; i < l1; i++)
		{
			if (map[str1[i] - 'A'] == '#')
			{
				map[str1[i] - 'A'] = str2[i];
			}
			else
			{
				if (map[str1[i] - 'A'] == str2[i])
					continue;
				else
				{
					flag = false;
					//cout << "pengzhuang" << endl;
					break;
				}
			}
		}
		for (i = 0; i < 26; i++)
		{
			if (map[i] == '#')
			{
				flag = false;
				//cout << "buquan" << endl;
				break;
			}
		}
		if (!flag)
			cout << "failed" << endl;
		else
		{
			int l3 = strlen(str3);
			for (i = 0; i < l3; i++)
			{
				cout << map[str3[i] - 'A'];
			}
		}
	}
	return 0;
}