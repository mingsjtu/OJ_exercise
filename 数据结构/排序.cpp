//≈≈–Ú
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
#include<time.h>
using namespace std;
const int maxn = 100;
int a[maxn];
//÷±Ω”≈≈–Ú
int* directsort(const int *a)
{
	int i, j, k;
	int *b=new int[maxn];
	
	for (i = 0; i < maxn; i++)
	{
		b[i] = a[i];
	}
	int tmp;
	for (i = 0; i < maxn; i++)
	{
		tmp = b[i];
		for (j = i - 1; j >= 0 && b[j] > tmp; j--)
		{
			b[j + 1] = b[j];
		}
		b[j + 1] = tmp;
	}
	return b;
}
//œ£∂˚≈≈–Ú
int* xiersort(const int* a)
{
	int i, j, k;
	int* b=new int[maxn];
	for (i = 0; i < maxn; i++)
	{
		b[i] = a[i];
	}
	int tmp;
	for (i = maxn/2; i >= 1; i/=2)
	{
		for (j = i; j < maxn; j += i)
		{
			tmp = b[j];
			for (k = j-i; k >= 0 && b[k] > tmp; k -= i)
			{
				b[k + i] = b[k];
			}
			b[k + i] = tmp;
		}
	}
	
	return b;
}
//÷±Ω”—°‘Ò≈≈–Ú
int* directxuansort(const int *a)
{
	int i, j, k;
	int minx;
	int *b = new int[maxn];
	int newp;
	for (i = 0; i < maxn; i++)
	{
		b[i] = a[i];
	}
	for (i = 0; i < maxn; i++)
	{
		minx = b[i];
		newp = i;
		for (j = i+1; j < maxn; j++)
		{
			if (b[j] < minx)
			{
				minx = b[j];
				newp = j;
			}
		}
		b[newp] = b[i];
		b[i] = minx;
	}
	return b;
}
//√∞≈›≈≈–Ú
int* maopaosort(const int *a)
{
	int i, j, k;
	int *b = new int[maxn];
	for (i = 0; i < maxn; i++)
	{
		b[i]=a[i];
	}
	int tmp;
	for (i = maxn-1; i >=0; i--)
	{
		for (j = 0; j < i; j++)
		{
			if (b[j] > b[j + 1])
			{
				tmp = b[j];
				b[j] = b[j + 1];
				b[j+1]=tmp;

			}
		}
	}
	return b;
}
//øÏÀŸ≈≈–Ú
int divide(int l, int h, int *b)
{
	int i, j, k;
	int tmp = b[l];
	int tmps;
	while (l < h)
	{
		while (b[h] >= tmp && h > l)
		{
			h--;
		}
		if (l < h)
		{
			b[l] = b[h];
		}
		while (b[l] <= tmp && l < h)
		{
			l++;
		}
		if (l < h)
		{
			b[h] = b[l];
		}
	}
	b[l] = tmp;
	return l;
}
void quicksort(int low, int high, int *b)
{
	if (low >= high)
		return;
	int i, j, k;
	int mid = divide(low, high, b);
	quicksort(low, mid-1, b);
	quicksort(mid + 1, high, b);
}
int* quicksort(const int *a)
{
	int i, j, k;
	int *b = new int[maxn];

	for (i = 0; i < maxn; i++)
	{
		b[i] = a[i];
	}
	quicksort(0, maxn-1, b);
	return b;
}
//πÈ≤¢≈≈–Ú
void merge(int low,int mid,int high,int* b)
{
	int i=0, j, k;
	int *tmp = new int[high-low+1];
	int p1 = low, p2 = mid + 1;
	while (p1 < mid+1&&p2 <=high)
	{
		if (b[p1] < b[p2])
		{
			tmp[i] = b[p1];
			p1++;
		}
		else
		{
			tmp[i] = b[p2];
			p2++;
		}
		i++;
	}
	while (p1 < mid + 1)
	{
		tmp[i++] = b[p1++];
	}
	while (p2 <=high)
	{
		tmp[i++] = b[p2++];
	}
	for (i = 0; i <= high-low; i++)
	{
		b[i+low] = tmp[i];
	}
}
void mergesort(int low, int high, int *b)
{
	if (low >= high)
		return;
	int mid = (low + high) / 2;
	mergesort(low, mid, b);
	mergesort(mid + 1, high, b);
	merge(low, mid, high, b);
}
int* mergesort(const int* a)
{
	int *b = new int[maxn];
	int i, j, k;
	for (i = 0; i < maxn; i++)
	{
		b[i] = a[i];
	}
	mergesort(0, maxn - 1, b);
	return b;
}
void display(int* a)
{
	int i, j, k;
	for (i = 0; i < maxn; i++)
	{
		cout << a[i] << ' ';
	}
	cout << endl;
}
int main()
{
	srand(time(NULL));
	int i, j, k;
	for (i = 0; i < maxn; i++)
	{
		a[i] = rand() % 100;
	}
	display(a);
	int* a1;
	a1= directsort(a);
	display(a1);
	a1 = xiersort(a);
	display(a1);
	a1 = directxuansort(a);
	display(a1);
	a1 = maopaosort(a);
	display(a1);
	a1 = quicksort(a);
	display(a1);
	a1 = mergesort(a);
	display(a1);
}