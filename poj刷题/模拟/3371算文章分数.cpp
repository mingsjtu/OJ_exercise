//http://poj.org/problem?id=3371
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<stack>
using namespace std;
int cnt1=0, cnt2=0, cnt3=0;//ju,word,syn
bool isw(char c)
{
	if (c >= 'a' && c <= 'z')
		return true;
	if (c >= 'A' && c <= 'Z')
		return true;
	return false;
}
bool isend(char c)
{
	if (c == '.' || c == '?' || c == ':' || c == '!' || c == ';')
		return true;
	return false;
}
bool isyuan(char c)
{
	if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y')
		return true;
	if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U'||c=='Y')
		return true;
	return false;
}

int main()
{
	int len,i,j,k,curlen=0,cursyn=0;
	char w[50];
	char w1[50], w2[50];
	char last[50];
	while (cin >> w)
	{
		strcpy(last, w);
		if (isw(w[0]))
			cnt2++;
		len = strlen(w);
		curlen = 0;
		cursyn = 0;
		for (i = 0; i < len; i++)
		{
			if (w[i] == 'e' && !isw(w[i + 1]) && w[i - 1] != 'l')
			{
				curlen++;
				continue;
			}
			if (w[i] == 'e' && (w[i + 1] == 's' || w[i + 1] == 'd') && !isw(w[i + 2]))
			{
				curlen++;
				continue;
			}
			if (w[i] == ','&&i!=len-1)
			{
				if (curlen <= 3)
					cursyn = 1;
				cnt2++;
				cnt3 += cursyn;
				cursyn = 0;
				curlen = 0;
			}
			if (isw(w[i]))
			{
				curlen++;
				if (isyuan(w[i])&&(i==0||!isyuan(w[i-1])))
				{
					cursyn++;
				}
			}
			if (isend(w[i]))
			{
				cnt1++;
				if (isw(w[i + 1]))
				{
					if (curlen <= 3)
						cursyn = 1;
					cnt2++;
					cnt3 += cursyn;
					cursyn = 0;
					curlen = 0;
				}
			}
		}
		if (curlen <= 3)
		{
			cnt3++;
			cursyn = 0;
			curlen = 0;
		}
		else
		{
			cnt3+=cursyn;
			cursyn = 0;
			curlen = 0;
		}
	}
	//cout << last << endl;
	if (isw(last[0]))
		cnt1++;
	double res;
	//res = 206.835 - 1.015*(double(cnt2) / double(cnt1)) - 84.6*(double(cnt3) / double(cnt2));
	cout << "cnt1 " << cnt1 << "  cnt2  " << cnt2 << "  cnt3  " << cnt3 << endl;
	printf("%.2f\n", res);
}