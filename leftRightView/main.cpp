#include<iostream>
#include<queue>

struct node{
	int data;
	struct node* left;
	struct node* right;
	node(int d){
		this->data = d;
		left = right = NULL;
	}
};

typedef struct node Node;

void leftView(Node *root, int level, int *maxlevel){
	if(!root) return;
	if(*maxlevel < level){
		std::cout<<root->data<<" ";
		*maxlevel = level;
	}
	leftView(root->left,level+1, maxlevel);
	leftView(root->right, level+1, maxlevel);

}

void rightView(Node *root){
	if(root){
		std::cout<<"\nRight View:";
		std::queue<Node*> q;
		Node* prev = root;
		q.push(root);
		q.push(NULL);
		Node* temp;
		while(!q.empty()){
			temp = q.front();
			q.pop();
			if(temp == NULL){
				if(prev)
					std::cout<<prev->data<<" ";
				if(!q.empty())
					q.push(NULL);
			}
			else{
				if(temp->left)
						q.push(temp->left);		
				if(temp->right)
						q.push(temp->right);			
			}
			prev = temp;
		}
		std::cout<<std::endl;
	}
}


int main(){
struct node *root = new Node(12);
    root->left = new Node(10);
    root->right = new Node(30);
    root->right->left = new Node(25);
    root->right->right = new Node(40);
    std::cout<<"Printing left view of tree:";
    int level = 1; 
    int maxlevel = 0;
    leftView(root, level, &maxlevel);
    rightView(root);
    std::cout<<std::endl;
    return 0;
}
