#include<iostream>

struct node {
	int data;
	struct node *left;
	struct node *right;
};
typedef struct node Node;

Node* newNode(int d){
	
	Node* temp = new Node;
	temp->data = d;
	temp->left = temp->right = NULL;
	return temp;
}
void printLeftSide(Node *root){
	if(!root) return;
	if(root->left){
		std::cout<<root->data<<" ";
		printLeftSide(root->left);
	}
	else if(root->right){
		std::cout<<root->data<<" ";
		printLeftSide(root->right);
	}
}

void leavesNodes(Node *root){
	if(!root)
		return;
	if(!root->left && !root->right)
		std::cout<<root->data<<" ";
	if(root->left)
		leavesNodes(root->left);
	if(root->right)
		leavesNodes(root->right);
}

void printRightSide(Node *root){
	if(!root) 
		return;
	if(root->right){
		printRightSide(root->right);
		std::cout<<root->data<<" ";
	}
	else if(root->left){
		printRightSide(root->left);
		std::cout<<root->data<<" ";
	}

}

void printPerimeter(Node *root){
	if(root){
		std::cout<<root->data<<" ";
		printLeftSide(root->left);
		leavesNodes(root->left);
		leavesNodes(root->right);
		printRightSide(root->right);
	}
}

int main(){
	struct node *root         = newNode(20);
    root->left                = newNode(8);
    root->left->left          = newNode(4);
    root->left->right         = newNode(12);
    root->left->right->left   = newNode(10);
    root->left->right->right  = newNode(14);
    root->right               = newNode(22);
    root->right->right        = newNode(25);

    std::cout<<"Perimeter:";
    printPerimeter(root);
    std::cout<<std::endl;

	return 0;
}
