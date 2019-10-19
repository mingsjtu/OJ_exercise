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
		if (t1[0] == 2 && t1[1] == 3 && t1[2] * 10 + t1[3] > 44)
			return false;
		int carry = 0;
		//int t2[4];
		if (t1[3] + 5 >= 10)
		{
			t2[3] = t1[3] + 5 - 10;
			carry = 1;
		}
		else
			t2[3] = t1[3] + 5;
		t2[2] = t1[2] + 1 + carry;
		if (t2[2] >= 6)
		{
			t2[1] = t1[1] + 1;
			t2[2] -= 6;
			if (t2[1] >= 10)
			{
				t2[1] -= 10;
				t2[0] = t1[0] + 1;
			}
			else
				t2[0] = t1[0];
		}
		else
		{
			t2[1] = t1[1];
			t2[0] = t1[0];
		}
		return true;
	}
	int main()
	{
		int a1[4], a2[4];
		for (int i = 0; i < 4; i++)
			cin >> a1[i];
		//cout << 1;
		bool flag = time15(a1, a2);
		if (flag)
		{
			for (int i = 0; i < 4; i++)
				cout << a2[i];
			cout << endl;
		}
		else cout << "no" << endl;

	}
