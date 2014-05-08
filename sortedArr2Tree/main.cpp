#include<iostream>


struct node{
	int data;
	struct node *left;
	struct node *right;
};

typedef struct node Node;

Node* convert(int *arr, int start, int end){
   if (start > end)
	return NULL;
   else
    {
	int mid = (start+end)/2;
	Node *root = new Node;
	root->data = arr[mid];
	root->left = convert(arr,start, mid-1);
	root->right = convert(arr,mid+1,end);
	return root;
   }
   return NULL;

}

void inOrder(Node *root){
	if(root){
		inOrder(root->left);
		std::cout<<root->data<<" ";
		inOrder(root->right);
	}
}


int main(){
	int arr[] = {1,2,3,4,5,6};
	Node *root = convert(arr, 0 , 5);
	std::cout<<"Inorder:";
	inOrder(root);
	std::cout<<std::endl;

}
