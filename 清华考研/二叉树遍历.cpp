//https://www.nowcoder.com/practice/4b91205483694f449f94c179883c1fef?tpId=40&tqId=21342&tPage=1&rp=1&ru=/ta/kaoyan&qru=/ta/kaoyan/question-ranking
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>

using namespace std;

struct node
{
	node* left;
	node* right;
	char fa;
};
int sta = 0;
char s[105];
int len = 0;
node *create()
{
	node* node1= (node*)malloc(sizeof(node));//ռλ��ʼ��
	node1->left = NULL;
	node1->right = NULL;
	return node1;
}
node* build()//һ��Ҫ����ָ��
{
	if (sta >= len)
		return NULL;
	if (s[sta] == '#')
	{
		//cout << sta << endl;
		sta++;
		return NULL;
	}
	//cout << sta << endl;
	node* r=create();//һ��Ҫ��ָ�룬������node������&rҲ����
	r->fa = s[sta];
	sta++;
	r->left=build();
	r->right=build();
	return r;
}
void bianli(node* r)
{
	if(r->left!=NULL)bianli(r->left);
	cout << r->fa << ' ';
	if (r->right!= NULL)bianli(r->right);
}
void clear(node* r)
{
	if (r == NULL)
		return;
	clear(r->left);
	r->left = NULL;
	clear(r->right);
	r->right = NULL;

	free(r);// delete(r);
}
int main()
{
	int i, j, k;
	while (scanf("%s", s)!=EOF)
	{
		sta = 0;
		len = strlen(s);
		node* root=create();
		root=build();
		//cout << root->left->fa << endl;
		bianli(root);
		cout << endl;
		clear(root);
	}
}