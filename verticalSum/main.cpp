#include<iostream>
#include<map>

struct node{
	int data;
	struct node *left;
	struct node *right;
};

typedef struct node Node;
Node* newNode(int data){
	Node *temp = new Node;
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
}

void verticalSumUtil(Node *root, std::map<int,int>& m, int hd){
	if(!root)
		return;
	if(root->left){
		verticalSumUtil(root->left, m, hd-1);
	}
	std::map<int,int>::iterator it = m.find(hd);
	if(it != m.end()){
		m[hd] = (it->second) + root->data;
	}
	else
		m[hd] = root->data;
	if(root->right){
		verticalSumUtil(root->right, m, hd+1);
	}
}

void verticalSum(Node *root){
	std::map<int,int> m;
	verticalSumUtil(root, m, 0);
	std::map<int,int>::iterator it;
	std::cout<<"vertical Sum:";
	for(it = m.begin(); it != m.end(); ++it){
		std::cout<<it->second<<" ";
	}
	std::cout<<std::endl;
}

int main(){
	 Node *root = newNode(1);
        root->left = newNode(2);
        root->right = newNode(3);
        root->left->left = newNode(4);
        root->left->right = newNode(5);
        root->right->left = newNode(6);
        root->right->right = newNode(7);
	verticalSum(root);

	return 0;
}
