//http://bailian.openjudge.cn/dsj2018xly/E/
#include<iostream>
#include<cstring>
using namespace std;
const char line1[] = { " _     _  _     _  _  _  _  _ " }, lin2[] = { "| |  | _| _||_||_ |_   ||_||_|" }, lin3[] = { "|_|  ||_  _|  | _||_|  ||_| _|" };


bool arr1[8][10];
int des[8];
char str[80];
bool time15(int t1[4], int t2[4])
{
	int time1, time2;
	time1 = t1[3] + t1[2] * 10 + t1[1] * 60 + t1[0] * 600;
	time2 = time1 - 15;
	if (time2 <0)
		//return false;
	time2 += 1440;
	t2[3] = time2 % 10;
	time2 -= t2[3];
	time2 /= 10;
	t2[2]=time2 % 6;
	time2 =(time2-t2[2])/6;
	t2[1] = time2 % 10;
	t2[0] = time2 / 10;
	return true;
}

bool solve(int res[4])
{
	bool flag=false;
	int i0,i1, i2, i3, i4;

	//0--4
	for (i0 = 0; i0 <= 2; i0++)
	{
		for(i1=0;i1<10;i1++)
			for(i2=0;i2<=6;i2++)
				for (i3 = 0; i3 <= 9; i3++)
				{
					if (arr1[0][i0] == 1 && arr1[1][i1] == 1 && arr1[2][i2] == 1 && arr1[3][i3] == 1)
					{
						int tmp1[4], tmp2[4];
						tmp1[0] = i0; tmp1[1] = i1; tmp1[2] = i2; tmp1[3] = i3;
						bool f1 = time15(tmp1, tmp2);
						if (f1)
						{
							if (arr1[4][tmp2[0]] == 1 && arr1[5][tmp2[1]] == 1 && arr1[6][tmp2[2]] == 1 && arr1[7][tmp2[3]] == 1)
							{
								//cout << i0 << i1 << i2 << i3 << endl;
								if (!flag) 
								{
									flag = true;
									res[0] = i0; res[1] = i1; res[2] = i2; res[3] = i3;
								}
								else 
								{
									flag = false;
									return false;
								}
							}

						}
						else continue;
					}
				}
	
	}
	return flag;
	//1--5

}
int main()
{

	int i, j,c,k;
	cin >> c;
	getchar();
	while (c > 0)
	{
		c--;
		
		//111 diyihang
		cin.getline(str, 80);
		memset(arr1, true, sizeof(arr1));
		//cout << strlen(str) << endl;
		for (j = 0; j < 4; j++)
		{
			if (str[j * 3 + 1] == '_')
			{
				arr1[j][1] = 0; arr1[j][4] = 0;
			}
		}
		for (j = 4; j < 8; j++)
		{
			if (str[j * 3 + 2] == '_')
			{
				arr1[j][1] = 0; arr1[j][4] = 0;
			}
		}
		//cout << strlen(str) << endl;

		//222
		cin.getline(str, 80);

		for (j = 0; j < 4; j++)
		{
			if (str[j * 3 + 1] == '_')
			{
				arr1[j][0] = 0; arr1[j][1] = 0; arr1[j][7] = 0;
			}
			if (str[3 * j] == '|')
			{
				arr1[j][1] = 0; arr1[j][2] = 0; arr1[j][3] = 0; arr1[j][7] = 0;
			}
			if (str[3 * j + 2] == '|')
			{
				arr1[j][5] = 0; arr1[j][6] = 0;
			}

		}
		for (j = 4; j < 8; j++)
		{
			if (str[j * 3 + 2] == '_')
			{
				arr1[j][0] = 0; arr1[j][1] = 0; arr1[j][7] = 0;
			}
			if (str[3 * j + 1] == '|')
			{
				arr1[j][1] = 0; arr1[j][2] = 0; arr1[j][3] = 0; arr1[j][7] = 0;
			}
			if (str[3 * j + 3] == '|')
			{
				arr1[j][5] = 0; arr1[j][6] = 0;
			}

		}

		//333
		cin.getline(str, 80);
		for (j = 0; j < 4; j++)
		{
			if (str[j * 3 + 1] == '_')
			{
				arr1[j][4] = 0; arr1[j][1] = 0; arr1[j][7] = 0; 
			}
			if (str[3 * j] == '|')
			{
				arr1[j][1] = 0; arr1[j][3] = 0; arr1[j][4] = 0; arr1[j][5] = 0; arr1[j][7] = 0; arr1[j][9] = 0;
			}
			if (str[3 * j + 2] == '|')
			{
				arr1[j][2] = 0;
			}
		}
		for (j = 4; j < 8; j++)
		{
			if (str[j * 3 + 2] == '_')
			{
				arr1[j][4] = 0; arr1[j][1] = 0; arr1[j][7] = 0; 
			}
			if (str[3 * j + 1] == '|')
			{
				arr1[j][1] = 0; arr1[j][3] = 0; arr1[j][4] = 0; arr1[j][5] = 0; arr1[j][7] = 0; arr1[j][9] = 0;
			}
			if (str[3 * j + 3] == '|')
			{
				arr1[j][2] = 0;
			}
		}
		int res[4];
		bool flag = solve(res);
		if (flag)
		{
			for (i = 0; i < 4; i++)
				cout << res[i];
		}
		else cout << "Not Sure"<<endl;
	}
	
}