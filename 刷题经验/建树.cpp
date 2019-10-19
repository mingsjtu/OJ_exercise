//https://www.nowcoder.com/practice/4b91205483694f449f94c179883c1fef?tpId=40&tqId=21342&tPage=1&rp=1&ru=/ta/kaoyan&qru=/ta/kaoyan/question-ranking
#include<iostream>	
#include<algorithm>
#include<cstring>
#include<string>
#include<cstdio>
#include<math.h>
using namespace std;
char tree[105];
int len = 0;
struct node
{
	char elem;
	node* ls, *rs;
	node(char x1, node* ls1, node* rs1)
	{
		elem = x1;
		ls = ls1;
		rs = rs1;
	}
	node() = default;
};
int pos = 0;
node* build()
{
	//printf("build %c\n", tree[pos]);
	if (pos == len)
		return NULL;
	int i, j, k;
	if (tree[pos] == '#')
	{
		pos++;
		return NULL;
	}
	node* r=new node(tree[pos],NULL,NULL);
	pos++;
	r->ls = build();
	//pos++;
	r->rs = build();
	return r;
}
void midsearch(node* r)
{
	if (r == NULL)
		return;
	if (r->ls != NULL)
		midsearch(r->ls);
	printf("%c ", r->elem);
	if (r->rs != NULL)
		midsearch(r->rs);
}
int main()
{
	cin >> tree;
	len = strlen(tree);
	int i, j, k;
	pos = 0;
	node* root=build();
	midsearch(root);
}