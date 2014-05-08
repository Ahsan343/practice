#include<iostream>

struct node{
	int data;
	struct node* next;
};

typedef struct node Node;


void insert(Node** head, int data){
	Node* newNode = new Node;
	newNode->data = data;
	newNode->next = NULL;
	if(!(*head)){
		*head = newNode;
	}
	else{
		Node *current = *head;
		while(current->next){
			current = current->next;
		}
		current->next = newNode;
	}

}


Node* swapPairs(Node **head){
	Node *newHead = NULL;
	if(*head){
		Node *prev = *head;
		newHead = prev->next;
		Node *current = newHead;
		Node *nextNode = NULL;
		bool done = true;	
		while(done){
			nextNode = current->next;
			current->next = prev;
			if(nextNode == NULL || nextNode->next == NULL){
				prev->next = nextNode;
				done = false;
			}
			else{
				prev->next = nextNode->next;
				prev = nextNode;
				current = nextNode->next;
			}

		}
	}
	return newHead;
}

Node* reverse(Node *head){
	Node *nextNode = NULL;
	Node *temp = NULL;
	while(head){
		nextNode = head->next;
		head->next = temp;
		temp = head;
		head = nextNode;
	}
	return temp;
}

void printList(Node* head){
	if(head){
		Node *current = head;
		std::cout<<"Current List:";
		while(current){
			std::cout<<current->data<<" ";
			current = current->next;
		}
		std::cout<<std::endl;
	}
}

int main(){
	Node *head = NULL;
	insert(&head , 1);
	insert(&head , 2);
	insert(&head , 3);
	insert(&head , 4);
	insert(&head , 5);
	insert(&head , 6);
	insert(&head , 7);
	printList(head);
	head = swapPairs(&head);
	printList(head);
	head = swapPairs(&head);
	printList(head);
	head = reverse(head);
	printList(head);
	return 0;
}
