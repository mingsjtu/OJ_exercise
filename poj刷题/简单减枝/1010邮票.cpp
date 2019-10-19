//http://poj.org/problem?id=1010
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
int xuan[4];
int type[1000];
int cnt = 0, cnt1 = 0;
int cum[1000];
int ccum = 0;
bool flag = false;
int res[4];
bool tie = false;
int typenum = 1;
int compare(int* a, int* b)
{
	int i, j, k;
	int typea = 1, typeb = 1, a0 = 0, b0 = 0;
	sort(a, a + 4);
	sort(b, b + 4);
	if (b[0] + b[1] + b[2] + b[3] == 0)
		return 1;
	if (a[0] == b[0] && a[1] == b[1] && a[2] == b[2] && a[3] == b[3])
	{
		return 0;
	}
	for (i = 0; i < 3; i++)
	{
		if (a[i] != a[i + 1] && type[a[i]] != 0 && type[a[i + 1]] != 0)
		{
			typea++;
		}
		if (b[i] != b[i + 1] && type[b[i]] != 0 && type[b[i + 1]] != 0)
		{
			typeb++;
		}
	}
	for(i=0;i<4;i++)
	{
		if (type[a[i]] == 0)
		{
			a0++;
		}
		if (type[b[i]] == 0)
		{
			b0++;
		}
	}
	typenum = max(typea, typeb);
	//printf("typea %d\n typeb %d\n", typea, typeb);
	int maxa=0, maxb=0;
	for (i = 0; i < 4; i++)
	{
		maxa = max(maxa, type[xuan[i]]);
		maxb = max(maxb, type[xuan[i]]);
	}
	printf("typea %d a0%d maxa%d\n", typea,a0,maxa);
	printf("typeb %d b0%d maxb%d\n", typeb,b0, maxb);

	if (typea > typeb)
		return 1;
	if (typeb > typea)
		return 0;
	if (a0 > b0)
		return 1;
	if (b0 > a0)
		return 0;
	if (maxa > maxb)
		return 1;
	if (maxa < maxb)
		return 0;
	if (typea == typeb && a0 == b0 && maxa==maxb)
	{
		return 2;
	}

}
void dfs(int total)
{
	int qian = 0;
	for (int i = 0; i < 4; i++)
		qian += type[xuan[i]];
	//printf("tes total%d , qian%d\n", total, qian);
	if (total == 4)
	{
		if (qian == ccum)
		{
			//printf("qian %d\n", qian);
			flag = true;
			for (int i = 0; i < 4; i++)
				printf("%d ", xuan[i]);
			cout << endl;
			
			int cres = compare(xuan, res);
			//printf("cres %d\n", cres);
			if (cres == 1)
			{
				cout << "success\n";
				for (int i = 0; i < 4; i++)
				{
					res[i] = xuan[i];
				}
			}
			if (cres == 2)
			{
				tie = true;
			}
			else
				tie = false;
			return;
		}
		return;
	}

	if (qian > ccum)
		return;
	int i, j, k;
	for (i = 0; i < cnt + 1; i++)
	{
		xuan[total] = i;
		dfs(total + 1);
	}
}


int main()
{
	int tmp;
	cnt = 0;
	cnt1 = 0;
	while (1)
	{
		while (cin >> tmp)
		{

			if (tmp == 0)
				break;
			type[cnt++] = tmp;
		}
		type[cnt] = 0;
		while (cin >> tmp)
		{
			if (tmp == 0)
				break;
			cum[cnt1] = tmp;
			cnt1++;
		}
		int i, j, k;
		//printf("cnt %d , cnt1 %d\n", cnt, cnt1);
		for (i = 0; i < cnt1; i++)
		{
			for (j = 0; j < 4; j++)
			{
				xuan[j] = cnt;
				res[j] = cnt;
			}
			flag = false;
			tie = false;
			ccum = cum[i];
			//printf("ccum %d\n", ccum);
			typenum = 1;
			//printf("zhong %d\n", cnt);
			dfs(0);
			sort(res, res + 4);
			if (!flag)
				printf("%d ---- none\n", ccum);
			else
			{
				if (tie)
					printf("%d (%d): tie\n", ccum, typenum);
				else
				{
					printf("%d (%d): ", ccum, typenum);
					for (j = 0; j < 4; j++)
						if (type[res[j]] > 0)
							cout << res[j] << ' ';
					cout << endl;
				}
			}
		}

		if (scanf("%d", &tmp) == EOF)
			break;
		else {
			cnt = 0;
			cnt1 = 0;
			type[cnt++] = tmp;
		}
	}

}