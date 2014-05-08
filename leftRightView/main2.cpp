#include<iostream>
#include<queue>

struct node{
	int data;
	struct node* left;
	struct node* right;
};

typedef struct node Node;

Node* newNode(int d){
	Node *newNode = new Node;
	newNode->data = d;
	newNode->left = newNode->right = NULL;
	return newNode;
}

void leftView(Node *root, int level, int *maxlevel){
	if(!root) return;
	if(*maxlevel < level){
		std::cout<<root->data<<" ";
		*maxlevel = level;
	}

	leftView(root->left, level+1, maxlevel);
	leftView(root->right, level+1, maxlevel);
}


void leftView2(Node *root){
	if(root){
		std::cout<<"Left View :";
		std::queue<Node*> q;
		Node *temp;
		q.push(NULL);
		q.push(root);
		while(!q.empty()){
			temp = q.front();
			q.pop();
			if(temp== NULL){
				if(!q.empty())
				{
					std::cout<<q.front()->data<<" ";
					q.push(NULL);
				}
			}
			else{
				if(temp->left) q.push(temp->left);
				if(temp->right) q.push(temp->right);
			}
		}
		std::cout<<std::endl;
	}


}

int main(){
    struct node *root = newNode(12);
    root->left = newNode(10);
    root->right = newNode(30);
    root->right->left = newNode(25);
    root->right->right = newNode(40);
  
    int level = 1;
    int maxlevel = 0;
    std::cout<<"Left View1:";
    leftView(root,level, &maxlevel);
    std::cout<<std::endl;
    leftView2(root);
    return 0;
}
