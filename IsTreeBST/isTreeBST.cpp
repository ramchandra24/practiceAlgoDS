#include <iostream>
#include <climits>

using namespace std;

typedef struct node{
	int data;
	struct node * left;
	struct node * right;
}NODE;

bool isBSTUtil(NODE * root, int minT, int maxT){


	if(NULL == root)
		return true;

    //cout << "data : " << root->data << " :: min : " << minT << " :: max : " << maxT << endl;

	if((root->data < minT) || (root->data > maxT))
		return false;

	return (isBSTUtil(root->left, minT, root->data) & isBSTUtil(root->right, root->data, maxT));
}

bool isBST(NODE * root){
	return isBSTUtil(root, INT_MIN, INT_MAX);
}

NODE * addNode(int data){
	NODE * nd = new NODE;
	nd->data = data;
	nd->left = NULL;
	nd->right = NULL;
	return nd;
}

int main(){
	NODE * root = addNode(4);
	NODE * a = addNode(2);
	NODE * b = addNode(3);
	NODE * c = addNode(5);
	NODE * d = addNode(6);
	root->left = b;
	root->right = c;
	b->left = a;
	c->right = d;

	cout << "isBST : " << (isBST(root) ? "true" : "false") << endl;

	return 0;
}

