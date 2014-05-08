#include<iostream>

struct node{
	int data;
	struct node *left;
	struct node *right;
};

typedef struct node Node;
struct node* newNode(int data)
{
  struct node* node = new Node;
  node->data = data;
  node->left = NULL;
  node->right = NULL;
 
  return(node);
}


int height(Node* root){
     if(root==NULL)
          return 0;
    else{
         return (1 + ((height(root->left) > height(root->right))? height(root->left):height(root->right)));   
    }
    
}

int diameterOfTree(node * root) {
    if(!root)
           return 0;
    else{
	int leftHeight = height(root->left);
	int rightHeight = height(root->right);
	
	int diameterLeft = diameterOfTree(root->left);
	int diameterRight = diameterOfTree(root->right);
	
	int max = diameterLeft >= diameterRight ? diameterLeft:diameterRight;
	if(max < (leftHeight + rightHeight + 1))
		max = leftHeight + rightHeight + 1;
	
	return max;  
        
    }
}

int main(){
struct node *root = newNode(1);
  root->left        = newNode(2);
  root->right       = newNode(3);
  root->left->left  = newNode(4);
  root->left->right = newNode(5);

std::cout<<"height of tree:"<<height(root)<<std::endl;
std::cout<<"Diameter:"<<diameterOfTree(root)<<std::endl;
return 0;
}
