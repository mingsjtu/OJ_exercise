//http://poj.org/problem?id=2255
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
string pre, mid;
int gen = 0;
struct node
{
	node *left;
	node *right;
	char ele;
	
}tree[30];
node* create(char i)
{
	tree[gen].ele = i;
	tree[gen].left = NULL;
	tree[gen].right = NULL;
	return &tree[gen++];
}

node *root;
node* build(int s,int left, int right)
{
	//cout << "current s" << s << endl;
	node *n1 = create(pre[s]);
	if (left == right)
	{
		//printf("yezi %d\n", left);
		return n1;
	}
	char r = pre[s];
	int root1=mid.find(r);
	//cout << "find r" << r << " at " << root1 << endl;
	if (root1 == left)
	{
		//printf("left ok\n");
		n1->left = NULL;
	}
	else
	{
		//printf("root %c,left %d,right %d\n", n1->ele,left, root1);
		n1->left = build(s+1,left, root1);
	}
	if (root1+1 == right)
	{
		n1->right = NULL;
	}
	else
	{
		//printf("root %c,left %d,right %d\n", n1->ele,root1 + 1, right);
		//cout << "ceshi" << s + root1 - left + 1 << endl;
		n1->right = build(s+root1-left+1,root1+1, right);
	}
	return n1;
}
void postorder(node *n)
{
	if (n == NULL)
		return;
	postorder(n->left);
	postorder(n->right);
	cout <<n->ele;
}
int main()
{
	while (cin >> pre >> mid)
	{
		int l1 = pre.length();
		int l2 = mid.length();
		//cout << "l1" << l1 << "l2" << l2 << endl;
		gen = 0;
		int sta, en;
		sta = 0;
		en = pre.size();
		root = build(0, sta, en);
		postorder(root);
		cout << endl;
	}
	
}