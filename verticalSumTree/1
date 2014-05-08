#include<iostream>

struct node{
	int data;
	struct node *left;
	struct node *right;
	node(int d){
		data = d;
		left = right = NULL;
	}
};

typedef struct node Node;
void vsum(Node *root, int* vsum1, int hd, int size){
	if(!root) return;
	int index = hd + size/2;
	vsum1[index] += root->data;
	if(root->left)
		vsum(root->left, vsum1, hd-1, size);
	if(root->right)
		vsum(root->right, vsum1, hd+1,size);
}

int size(Node *root){
	if(!root) return 0;
	return 1+size(root->left)+size(root->right);
}

int main(){
	Node *root = new Node(1);
        root->left = new Node(2);
        root->right = new Node(3);
        root->left->left =  new Node(4);
        root->left->right = new Node(5);
        root->right->left= new Node(6);
        root->right->right=new Node(7);
	int s = size(root);
	int vsum1[16] = {0};
	vsum(root, vsum1, 0, size(root));
	for(int i = 0; i < size(root); ++i){
		std::cout<<vsum1[i]<<" ";
	}
	std::cout<<std::endl;
	return 0;
}
