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


int maxSum(Node *root){
	if(!root)
		return 0;
	int leftSum = maxSum(root->left);
	int rightSum = maxSum(root->right);
	
	int max =( (leftSum > rightSum) ? leftSum:rightSum );
	
	return (max + root->data);
}

int main(){
    struct node *root = NULL;
 
    /* Constructing tree given in the above figure */
    root = newNode(10);
    root->left = newNode(-2);
    root->right = newNode(7);
    root->left->left = newNode(8);
    root->left->right = newNode(-4);
	
    std::cout<<"max root to leaf sum:"<<maxSum(root)<<std::endl;
    return 0;
}
