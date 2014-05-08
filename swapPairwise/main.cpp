#include<iostream>

struct node{
	int data;
	struct node *next;
};

typedef struct node Node;

void insert(Node** head, int data){
	Node *newNode = new Node;
	if(!newNode){
		std::cout<<"memory error\n";
		return;
	}
	newNode->data;
	newNode->next = NULL;
	if(!(*head)){
		*head = newNode;
		return;
	}
	else{
		Node *current = *head;
		while(current->next){
			current = current->next;
		}
		current->next = newNode;
	}
}

Node* pairWiseSwap(Node **head){
	Node* newHead = NULL;
	if(*head){
			Node *prev = *head;
			newHead = prev->next;
			Node *current = newHead;
			Node *nextNode = NULL;
			bool done = true;
			while(done){
				nextNode = current->next;
				current->next = prev;
				if(nextNode == NULL || nextNode->
			

			}



	}
	return newHead;

}

void printList(Node *head){
	if(head){
		std::cout<<"Current List:"
		Node *current = head;
		while(current){
			std::cout<<current->data<<" ";
			current = current->next;
		}
		std::cout<<std::endl;
	}
}

int main(){

}
