#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<stack>
using namespace std;
class cal 
{
	enum Type{DATA,ADD,SUB,MUL,DIV,OPAREN,CPAREN};
	struct node
	{
		Type type;
		int value;
		node* ls;
		node* rs;
		node(Type t, int v, node* l=NULL, node* r=NULL)
		{
			type= t;
			value = v;
			ls = l;
			rs = r;
		};
	public:
		cal(char * s); 
		node* root;
		node* create(char* &s);
		Type getc(char* &s, int &value);
		int result(node* t);
		
		int result()
		{
			if (root == NULL)return 0;
			return result(root);
		}
	};
};
cal::node *cal::create(char* &s)
{

}
