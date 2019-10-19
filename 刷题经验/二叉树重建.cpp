//
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<math.h>
using namespace std;
char str1[30], str2[30];
struct node
{
	char elem;
	node* lc, *rc;
	node(char e, node* l, node* r)
	{
		elem = e;
		lc = l;
		rc = r;
	}
};
node* build(int s1, int e1, int s2, int e2)//qian,zhong
{
	int i, j, k;
	node* res=new node(str1[s1],NULL,NULL);

	for (i = s2; i <= e2; i++)
	{
		if (str1[s1] == str2[i])
		{
			break;
		}
	}
	int zhong = i;
	int ll = zhong-s2;
	int rl = e2-zhong;
	if (ll>0)
		res->lc = build(s1 + 1, s1 + ll, s2, zhong - 1);
	if (rl > 0)
		res->rc = build(s1 + ll+1, e1, zhong + 1, e2);
	return res;
}
void display(node* root)
{
	if (root == NULL)
		return;
	display(root->lc);
	display(root->rc);
	cout << root->elem << ' ';
}
int main()
{
	int len;
	while (scanf("%s%s", str1, str2) != EOF)
	{
		len = strlen(str1);
		node* root = build(0, len - 1, 0, len - 1);
		display(root);
		cout << endl;
	}
}