//BST
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<stack>
using namespace std;
template<class type>
class bst
{
private:
	int size;
	int maxsize;
	struct node
	{
		node* left;
		node* right;
		type elem;
		node(node* l, node* r, type e) :left(l), right(r), elem(e) {};
	};
	node* root=NULL;
	bool find(type x, node* cur)
	{
		if (cur == NULL)
			return false;
		else
		{
			if (x == cur->elem)
				return true;
			if (x < cur->elem)
				return find(x, cur->left);
			else
				return find(x, cur->right);
		}
	}
	bool insert(type x,node * &cur)
	{
		cout << 1 << endl;
		if (cur == NULL)
		{
			cur = new node(NULL, NULL, x);
			return true;
		}
		if (x == cur->elem)
			return false;
		if (x < cur->elem)
			return insert(x, cur->left);
		else
			return insert(x, cur->right);
	}
	bool remove(type x, node* &cur)
	{
		if (cur == NULL)
			return false;
		if (x < cur->elem)
			return remove(x, cur->left);
		if (x > cur->elem)
			return remove(x, cur->right);
		if (cur->left != NULL && cur->right != NULL)
		{
			node* t = cur->right;
			while (t->left != NULL)t = t->left;
			cur->elem = t->elem;
			return remove(t->elem, cur->right);
		}
		else
		{
			node* t = cur;
			cur = (cur->left != NULL)?cur->left:cur->right;
			//cur->elem = t->elem;
			delete t;
			return true;
		}
	}
public:
	bool find(type x)
	{
		return find(x, root);
	}
	bool insert(type x)
	{
		return insert(x, root);
	}
	bool remove(type x)
	{
		return remove(x, root);
	}
};
int main()
{
	int i, j, k;
	bst<int> t1;
	while (cin >> k)
	{
		if (k == 0)
			break;
		t1.insert(k);
	}
	while (cin >> k)
	{
		if (!k)
			break;
		if (t1.find(k))
			cout << "suc" << endl;
		else
			cout << "error" << endl;
	}
	while (cin >> k)
	{
		if (!k)
			break;
		if (t1.remove(k))
		{
			cout << "remove " << k << endl;
		}
		else
			cout << "no\n";
	}
	while (cin >> k)
	{
		if (!k)
			break;
		if (t1.find(k))
			cout << "suc" << endl;
		else
			cout << "error" << endl;
	}
}