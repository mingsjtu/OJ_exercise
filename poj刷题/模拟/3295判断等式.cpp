#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <string>
using namespace std;

string p;
bool v[5];

bool getValue(string p, int &end)
{
	bool a, b;
	int end1, end2;

	if (p[0] >= 'p')
	{
		end = 0;
		return v[p[0] - 'p'];
	}
	if (p[0] == 'N')
	{
		a = getValue(p.substr(1, p.length() - 1), end1);
		end = end1 + 1;
		return !a;
	}
	a = getValue(p.substr(1, p.length() - 1), end1);
	b = getValue(p.substr(end1 + 2, p.length()-end1-2), end2);
	end = 2 + end1 + end2;
	switch (p[0])
	{
	case 'K':
		return a && b;
	case 'A':
		return a || b;
	case 'C':
		return !a || b;
	case 'E':
		return !(a ^ b);
	}
	return 0;
}

int main()
{
	bool ok;

	//freopen("D:\\t.txt", "r", stdin);
	while (getline(cin, p) && p != "0")
	{
		ok = true;
		for (int i = 0; i < 32; i++)
		{
			for (int j = 0; j < 5; j++)
				v[j] = (i >> j) % 2;
			int x;
			if (!getValue(p, x))
			{
				ok = false;
				break;
			}
		}
		if (ok)
			cout << "tautology" << endl;
		else
			cout << "not" << endl;
	}
	return 0;
}