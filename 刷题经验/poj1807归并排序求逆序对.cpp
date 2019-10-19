//http://poj.org/problem?id=1804
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
int a[1005];
int n;
int cnt = 0;
void merge(int low,int high,int mid)
{
	int i=low, j=mid+1, k=0;
	int *tmp = new int[high - low + 1];
	while (i <= mid && j <= high)
	{
		if (a[i] <=a[j])
		{
			tmp[k++] = a[i++];
		}
		else
		{
			tmp[k++] = a[j++];
			cnt += mid-i+ 1;
			//printf("cnt+ %d\n", mid-i + 1);
		}
	}
	while (i <= mid) 
	{
		tmp[k++] = a[i++];
	}
	while(j<=high)
	{
		tmp[k++] = a[j++];
	}
	for (i = 0, k = low; k <= high; i++, k++)
	{
		a[k] = tmp[i];
	}
	delete []tmp;
}
void merge_sort(int low, int high)
{
	if (high - low < 1)
	{
		return;
	}
	int mid = (low + high) / 2;
	merge_sort(low, mid);
	merge_sort(mid + 1, high);
	merge(low,high,mid);
}

int main()
{
	int i, j=1, k;
	int t;
	cin >> t;
	while (t--)
	{
		cin >> n;
		cnt = 0;
		for (i = 0; i <n ; i++)
		{
			scanf("%d", &a[i]);
		}
		merge_sort(0,n-1);
		printf("Scenario #%d:\n%d\n\n", j++, cnt);
	}
}