#include<iostream>

struct node{
	int data;
	struct node *next;
	node(int d){
		data = d;
		next = NULL;
	}
};


typedef struct node Node;

void insert(Node **head, int data){
	Node *newNode = new Node(data);
	if(*head == NULL){
		*head = newNode;
		return;
	}
	else{
		Node *curr = *head;
		while(curr->next){
			curr = curr->next;
		}
		curr->next = newNode;
	}
}

Node* swapK(Node *head, int k){
	Node *prev = NULL;
	Node *curr = head;
	Node *nextNode = NULL;
	int count = 0;
	while(curr && count < k){
		nextNode = curr->next;
		curr->next = prev;
		prev = curr;
		curr = nextNode;
		++count;
	}
	if(head){
		head->next = swapK(nextNode, k);
	}
	return prev;

}

void printList(Node *head){
	std::cout<<"List:";
	Node *curr = head;
	while(curr){
		std::cout<<curr->data<<" ";
		curr=curr->next;
	}
	std::cout<<std::endl;
}

int main(){
	Node *head = NULL;
	insert(&head, 1);
	insert(&head, 2);
	insert(&head, 3);
	insert(&head, 4);
	insert(&head, 5);
	insert(&head, 6);
	insert(&head, 7);
	printList(head);
	head =swapK(head, 3);
	printList(head);
	return 0;
}
