#include<iostream>

struct node{
	int data;
	struct node* left;
	struct node* right;
};

typedef struct node Node;

Node* newNode(int d){
	Node* temp = new Node;	
	temp->data = d;
	temp->left = temp->right = NULL;
	return temp;
}

void mirror(Node *root){
	if(!root) return;
	mirror(root->left);
	mirror(root->right);
	Node *temp;
	temp = root->left;
	root->left = root->right;
	root->right = temp;
}

void inOrder(Node *root){
	if(root){
		inOrder(root->left);
		std::cout<<root->data<<" ";
		inOrder(root->right);
	}
}

int main(){
	struct node *root = newNode(1);
  root->left        = newNode(2);
  root->right       = newNode(3);
  root->left->left  = newNode(4);
  root->left->right = newNode(5); 

  std::cout<<"InOrder before mirror:";
  inOrder(root);
  std::cout<<std::endl;
  mirror(root);
  std::cout<<"InOrder after  mirror:";
  inOrder(root);
  std::cout<<std::endl;

   return 0;
	
}
