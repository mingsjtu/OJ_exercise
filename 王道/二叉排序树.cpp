#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<functional>
#include<sstream>

#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<set>
#include<map>
using namespace std;
struct node
{
	node* lc;
	node* rc;
	int value;

}tree[100];
int flag = 0;
node* create()
{
	tree[flag].lc = NULL;
	tree[flag].rc = NULL;
	printf("flag=%d\n", flag);
	return (&tree[flag++]);
}
node* insert(node* &n1,int v1)
{
	if (n1 == NULL)
	{
		n1=create();
		n1->value = v1;
		return n1;
	}
	else if (v1 < n1->value)
		n1->lc = insert(n1->lc, v1);
	else if (v1 > n1->value)
		n1->rc = insert(n1->rc, v1);
    return n1;
}
void mid1(node* &n)
{
	if (n == NULL)
		return;
	mid1(n->lc);
	cout << n->value << ' ';
	mid1(n->rc);
}
void back1(node* &n)
{
	if (n == NULL)
		return;
	back1(n->lc);
	back1(n->rc);
	cout << n->value << ' ';
}
void front1(node* &n)
{
	if (n == NULL)
		return;
    cout << n->value << ' ';
	front1(n->lc);
	front1(n->rc);

}
int main()
{
	flag = 0;
	node *root=NULL;
	int num,tmp;
	cin >> num;
	for (int i = 0; i < num; i++)
	{
		cin >> tmp;
		insert(root, tmp);
	}
	front1(root);
	cout<<endl;
	mid1(root);
	cout<<endl;
	back1(root);
	cout<<endl;
	return 0;

}
