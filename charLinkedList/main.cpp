/*
Given a linked list containing character in each node, segregate its nodes in such a way that all nodes containing a vowel are moved to the end of the linked list. We will have to maintain the order.

*/

#include<iostream>

struct node{
	char character;
	struct node *next;
	node(char c){
		character = c;
		next = NULL;
	}
};

typedef struct node Node;

void insertAtEnd(Node **head, char c){
	Node *newNode = new node(c);
	if( !(*head)){
		*head = newNode;
		 return;
	}
	else{
		Node *temp = *head;
		while(temp->next != NULL){
			temp = temp->next;
		}
		temp->next = newNode;
	}
}

void insertNode(Node **head, Node *n){
	if(*head){
		Node* current = *head;
		while(current->next){
			current = current->next;
		}
		current->next = n;
	}
	else
		*head = n;
}

void transform(Node **head){
 	if(head){
		Node *current= NULL, *prev = NULL;
		Node *vowel = NULL;
		current = *head;
		while(current->next){
			if(current->character == 'a' || current->character=='e' || current->character=='i' || current->character == 'o' || current->character == 'u'){
					if(prev == NULL){
							*head = current->next;
							current->next = NULL;
							insertNode(&vowel, current);
							current = *head;
					}
					else{
							prev->next = current->next;
							current->next = NULL;
							insertNode(&vowel, current);			
							current = prev->next;
					}
	}
	else{
			prev = current;
			current = current->next;
	}
	
		}
		current->next = vowel;
	}
}

void printList(Node *head){
	Node *current = head;
	std::cout<<"List:";
	while(current){
		std::cout<<current->character<<" ";
		current = current->next;
	}
	std::cout<<std::endl;
}



int main(){
	Node *head = NULL;
	insertAtEnd(&head, 'a');
	insertAtEnd(&head, 'a');
	insertAtEnd(&head, 'b');
	insertAtEnd(&head, 'c');
	insertAtEnd(&head, 'i');
	insertAtEnd(&head, 'd');
	insertAtEnd(&head, 'e');
	insertAtEnd(&head, 'f');
	insertAtEnd(&head, 'e');
	insertAtEnd(&head, 'g');
	printList(head);
	transform(&head);
	printList(head);
	return 0;
}
