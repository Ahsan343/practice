#include<iostream>

struct node{
	int data;
	struct node *left;
	struct node *right;
};

typedef struct node Node;

Node* newNode(int d){
	Node *temp = new Node;
	temp->data = d;
	temp->left = temp->right = NULL;
	return temp;
}

Node* convert2DLL(Node* root){
	if(!root) return root;
	if(root->left){
		Node *lnode = convert2DLL(root->left);
		while(lnode->right)
			lnode = lnode->right;
		lnode->right = root;
		root->left = lnode;
	}

	if(root->right){
		Node *rnode = convert2DLL(root->right);
		while(rnode->left)
			rnode = rnode->left;
		rnode->left = root;
		root->right = rnode;
	}
	return root;
}

Node* convert(Node *root){
	root = convert2DLL(root);
	while(root->left)
		root= root->left;
	return root;
}

void printList(Node *head){
	Node *temp = head;
	while(temp){
		std::cout<<temp->data<<" ";
		temp = temp->right;
	}
}

int main(){

	node *root        = newNode(10);
    root->left        = newNode(12);
    root->right       = newNode(15);
    root->left->left  = newNode(25);
    root->left->right = newNode(30);
    root->right->left = newNode(36);
 
    // Convert to DLL
    node *head = convert(root);
    printList(head);
    std::cout<<std::endl;
	return 0;
}
