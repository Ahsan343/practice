#include<iostream>

struct node{
	char ch;
	struct node *next;
	node(char c){
		ch = c;
		next = NULL;
	}
};
typedef struct node Node;

void insert(Node **head, Node *n){
	if(*head){
		Node *current = *head;
		while(current->next){
			current = current->next;
		}
		current->next = n;
	}
	else
		*head = n;
}

void transform(Node **head){
	if(*head){
		Node *current = *head, *prev = NULL;
		Node *vowel = NULL;
		while(current->next){
			if(current->ch == 'a' || current->ch == 'e' || current->ch == 'i' || current->ch == 'o' || current->ch=='u'){
					if(prev == NULL){
						*head = current->next;
						 current->next = NULL;
						 insert(&vowel, current);
						 current = *head;
					}
					else{
						prev->next = current->next;
						current->next = NULL;
						insert(&vowel, current);
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
	std::cout<<"List:";
	if(head){
		Node *current = head;
		while(current){
			std::cout<<current->ch<<" ";
			current = current->next;
		}
		std::cout<<std::endl;
	}
}

int main(){

	Node *head = NULL;
	Node *node1 = new node('a');
	Node *node2 = new node('b');
	Node *node3 = new node('c');
	Node *node4 = new node('d');
	Node *node5 = new node('e');
	Node *node6 = new node('f');
	insert(&head, node1);
	insert(&head, node2);
	insert(&head, node3);
	insert(&head, node4);
	insert(&head, node5);
	insert(&head, node6);
	printList(head);
	transform(&head);
	printList(head);
	return 0;
	
}
