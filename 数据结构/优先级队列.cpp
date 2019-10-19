//
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<random>
#include<time.h>
using namespace std;
template<class type>
class pqueue
{
private:
	int size;
	int maxsize;
	type* elem;
	void down(int x)
	{
		int i, j, k;
		i = x;
		type tmp = elem[x];
		//cout << x << endl;
		int c;
		while (2 * x <=size)
		{
			c = 2 * x;
			if (2 * x + 1 <=size&&elem[2 * x + 1] < elem[2 * x])
			{
				c++;
			}
			if (elem[c] < tmp)
			{
				elem[x] = elem[c];
				x = c;
			}
			else
				break;
		}
		//cout << "new " << x << endl;
		elem[x] = tmp;
	}
	void doublespace()
	{
		type* tmp = new type[maxsize];
		int i;
		for (i = 1; i <= size; i++)
			tmp[i] = elem[i];
		maxsize *= 2;
		elem = new type[maxsize];
		for (i = 1; i <= size; i++)
		{
			elem[i] = tmp[i];
		}
		delete tmp;
	}
	void up(int x)
	{
		type tmp = elem[x];
		int f;
		for (; x>1&&elem[x/2]>tmp; x/=2)
		{
			elem[x] = elem[x/2];
		}
		elem[x] = tmp;
	}

public:
	pqueue(int s, int ms,type* a)
	{
		int i, j, k;

		cout <<'s'<< s << "ms " << ms << endl;
		cout << "old\n";
		
		size = s;
		maxsize = ms;
		elem = new type[ms];
		for (i = 1; i <=s; i++)
		{
			elem[i] = a[i-1];
		}
		for (i = 1; i <= size; i++)
		{
			cout << elem[i] << ' ';
		}
		cout << endl;
		for (i = s; i >= 1; i--)
		{
			down(i);
		}
		cout << "new\n";
		for (i = 1; i <= size; i++)
		{
			cout << elem[i] << ' ' ;
		}
		cout << endl;
	}
	type pop()
	{
		type tmp = elem[1];
		elem[1] = elem[size];
		down(1);
		size--;
		//cout << "size " <<size<< endl;
		return tmp;
	}
	void insert(type x)
	{
		if (size + 2 == maxsize)
			doublespace();
		size++;
		elem[size] = x;
		up(size);
	}
	bool isempty()
	{
		return size == 0;
	}
};
int main()
{
	int i, j, k;
	int maxsize = 100;
	int size = 50;
	int a[100];
	srand(time(NULL));
	for (i = 0; i < size; i++)
	{
		a[i] = rand() % 100;
	}
	//cout << "size" << size << "maxsize" << maxsize<<endl;
	pqueue<int> q1(size,maxsize,a);
	while (!q1.isempty())
	{
		cout << q1.pop() << endl;
	}
	int x;
	while (cin >> x)
	{
		q1.insert(x);
	}
	while (!q1.isempty())
	{
		cout << q1.pop() << endl;
	}

}