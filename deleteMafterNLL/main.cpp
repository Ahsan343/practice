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
		Node *temp = *head;
		while(temp->next){
			temp = temp->next;
		}
		temp->next = newNode;
	}

}

void printList(Node *head){
	Node *curr = head;
	std::cout<<"List:";
	while(curr){
		std::cout<<curr->data<<" ";
		curr = curr->next;
	}
	std::cout<<std::endl;
}


void deleteNafterM(Node *head, int N, int M){
	Node *curr = head;
	Node *temp = NULL;
	Node *delNode = NULL;
	int count;
	while(curr){
		count = 1;
		while(curr && count < M){
			curr = curr->next;
			++count;
		}
		if(!curr)
			return;
		temp = curr->next;
		count = 1;
		while(temp && count <= N){
			delNode = temp;
			temp = temp->next;
			delete(delNode);
			++count;
		} 
		curr->next = temp;
		curr = temp;
	}
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
	insert(&head, 8);
	insert(&head, 9);
	insert(&head, 10);
	printList(head);
	deleteNafterM(head, 3, 2);
	printList(head);
	return 0;
}
