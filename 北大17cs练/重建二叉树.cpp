//http://bailian.openjudge.cn/practice/2255/
#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;
struct node
{
	node *lc, *rc;
	char zhi;

}tree[100];
int loc = 0;
node* create(char z='#')
{
	tree[loc].zhi = z;
	tree[loc].lc = NULL;
	tree[loc].rc = NULL;
	//cout << "loc" << loc<<endl;
	return &tree[loc++];

}

char str1[1000], str2[1000];
node* build(int s1, int e1, int s2, int e2)//
{
	char root = str1[s1];
	int ini=0;
	node* r=create(root);
	//cout <<"create"<< r->zhi<<' ';
	bool flag = false;
	for (ini = s2; ini <= e2; ini++)
	{
		if (str2[ini]==root)
		{
		//	cout << endl << "here" << ini << endl;
			flag = true;;
			break;
		}
	}
	if (!flag)
		return r;

	if (s2 < ini)//×ó×ÓÊ÷²»Îª¿Õ
	{
		//printf("create%c lc", str1[s1]);
		r->lc = build(s1 + 1, s1 + ini - s2, s2,ini-1);
	}
	if (e2 > ini)
	{
		//printf("create%c rc", str1[s1]);

		r->rc = build(s1 + (ini - s2) + 1, e1, ini + 1, e2);
	}
	//cout << r->zhi << "zhi" << endl;
	return r;
}
void back(node* root)
{
	if (root == NULL)
		return;
	if (root->lc != NULL)
	{
		back(root->lc);
	}
	if (root->rc != NULL)
	{
		back(root->rc);
	}
	cout << root->zhi;
	return;
}

int main()
{

	while (cin >> str1 >> str2) {
		int n1 = strlen(str1), n2 = strlen(str2);
		node *root;
		loc = 0;
		root = build(0, n1 - 1, 0, n2 - 1);
		//cout <<"zhi"<< root->zhi << endl;
		//cout << loc << endl;
		back(root);
		cout << endl;
	}
}
