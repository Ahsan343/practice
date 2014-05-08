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

Node* binaryTree2DLLUtil(Node *root){
	if(!root){
		return root;
	}
	if(root->left){
		Node *ltree = binaryTree2DLLUtil(root->left);
		while(ltree->right)
			ltree = ltree->right;
		ltree->right = root;
		root->left = ltree;
	}
	if(root->right){
		Node *rtree = binaryTree2DLLUtil(root->right);
		while(rtree->left){
			rtree = rtree->left;
		}
		rtree->left = root;
		root->right = rtree;
	}
	return root;
}

Node* binaryTree2DLL(Node *root){
	root = binaryTree2DLLUtil(root);
	while(root->left) 
		root = root->left;
	return root;
}

void printlist(Node *head){
	if(head){
		std::cout<<"List:";
		Node *current = head;
		while(current){
			std::cout<<current->data<<" ";
			current = current->right;
		}
		std::cout<<std::endl;
	}
}


int main(){
    Node *root        = new Node(10);
    root->left        = new Node(12);
    root->right       = new Node(15);
    root->left->left  = new Node(25);
    root->left->right = new Node(30);
    root->right->left = new Node(36);
 
    // Convert to DLL
    node *head = binaryTree2DLL(root);
 
    // Print the converted list
	printlist(head);
	return 0;
}
