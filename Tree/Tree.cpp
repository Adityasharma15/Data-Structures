#include<bits/stdc++.h>
#include"Treeclass.h"
using namespace std;

template<typename T>
struct treenode
{
	T data;
	vector<treenode<T>*> children;
	
};

treenode* addValue(treenode* node, T data)
{
	node->data= data;
	return node;
}

treenode* addChildren(treenode* parent, treenode* child)
{
parent->children.push_back(child);
return parent;
}

int main()
{
	treenode<int> parent = new treenode
}
