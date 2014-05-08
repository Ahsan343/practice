/*

Given a BST , replace a node value with the sum of all the elements larger than the current node

*/

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

void transform(Node *root, int* currSum){
	if(!root)
		return;
	if(root->right){
		transform(root->right, currSum);
	}	
	
	*currSum += root->data;
	root->data = *currSum;

	if(root->left){
		transform(root->left, currSum);
	}

}

void inOrder(Node *root){
	if(root){
		inOrder(root->left);
		std::cout<<root->data<<" ";
		inOrder(root->right);		
	}
}

int main(){
	
    Node *root = newNode(5);
    root->left = newNode(2);
    root->right = newNode(13);

    std::cout<<"Inorder:";
    inOrder(root);
    std::cout<<std::endl;

    int sum = 0;
    transform(root,&sum);
    std::cout<<"Inorder:";
    inOrder(root);
    std::cout<<std::endl;
	return 0;
}
