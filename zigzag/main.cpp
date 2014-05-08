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

int height(Node *root){
	if(!root)
		return 0;
	int leftHeight = height(root->left);
	int rightHeight = height(root->right);
	
	if(leftHeight > rightHeight)
		return (leftHeight + 1);
	else
		return (rightHeight + 1);
}

void printLevel(Node *root, int level, int flag){
	if(!root)
		return;
	if(level == 0){
		std::cout<<root->data<<" ";
	}else if(level > 0){
		if(flag){
			printLevel(root->left, level-1, flag);
			printLevel(root->right,level-1, flag);
		}	
		else{
			printLevel(root->right, level-1, flag);
			printLevel(root->left, level-1, flag);
		}
	}
}

void zigzag(Node *root){
	if(!root) return ;
	std::cout<<"ZigZag:";
	int h = height(root);
	int flag = 0;
	for(int i =0; i < h; ++i){
		printLevel(root,i, flag);
		flag = !flag;
	}
	std::cout<<std::endl;
}

int main(){
	 struct node *root = newNode(1);
    root->left        = newNode(2);
    root->right       = newNode(3);
    root->left->left  = newNode(7);
    root->left->right = newNode(6);
    root->right->left  = newNode(5);
    root->right->right = newNode(4);
    zigzag(root);
}
