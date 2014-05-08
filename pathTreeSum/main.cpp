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

bool pathExists(Node *root, int sum){
	if(!root)
		return (sum == 0);
	int remaining = sum - root->data;

	if( (!root->left && !root->right) && (root->left && root->right)){
		return (pathExists(root->left,remaining) || pathExists(root->right, remaining));
	}
	else if(root->left)
		return pathExists(root->left, remaining);
	else
		return pathExists(root->right, remaining);
}

int main()
{
 
  int sum = 21;
 
  /* Constructed binary tree is
            10
          /   \
        8      2
      /  \    /
    3     5  2
  */
  struct node *root = new node(10);
  root->left        = new node(8);
  root->right       = new node(2);
  root->left->left  = new node(3);
  root->left->right = new node(5);
  root->right->left = new node(2);
 
  if(pathExists(root, sum))
	std::cout<<"There is a root-to-left path with sum "<<sum<<std::endl;
  else
	std::cout<<"There is no root-to-left path with sum "<<sum<<std::endl;
	
}
