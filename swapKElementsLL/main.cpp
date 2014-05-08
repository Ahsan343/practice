#include<iostream>

struct node{
	int data;
	struct node *next;
};

typedef struct node Node;

Node* swapK(Node *list, int k){
	Node *head = list;
	Node *prev = list;
	Node *nextNode = head->next;
	int count = 1;
	while(nextNode){
		if(count == k) break;
		prev->next = nextNode->next;
		nextNode->next = head;
		head = nextNode;
		nextNode = prev->next;	
		count++;
	}
	if(nextNode){
		prev->next = swapK(nextNode, k);
	}	
	return head;
}

void insert(Node **head, int data){
	Node *newNode = new Node;
	newNode->data = data;
	newNode->next = NULL;
	if(*head == NULL){
		*head = newNode;
		return;
	}
	Node *temp = *head;
	while(temp->next)
		temp = temp->next;
	temp->next = newNode;
}

void printList(Node *head){
	if(head){
		Node *temp = head;
		while(temp){
			std::cout<<temp->data<<" ";
			temp = temp->next;
		}
	}
	std::cout<<std::endl;
}

int main(){
	Node *head;
	insert(&head, 1);
	insert(&head, 2);
	insert(&head, 3);
	insert(&head, 4);
	insert(&head, 5);
	insert(&head, 6);
	insert(&head, 7);
	printList(head);
        head = 	swapK(head, 3);
	printList(head);
	return 0;
}
