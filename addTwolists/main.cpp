#include<iostream>
struct node{
	int data;
	struct node *next;
};
typedef struct node Node;

void insert(Node **head, int data){
	Node *newNode = new Node;
	newNode->data = data;
	newNode->next = NULL;
	if(*head == NULL){
		*head = newNode;
	}
	else{
		Node *temp = *head;
		while(temp->next)
			temp= temp->next;
		temp->next = newNode;
	}
}

Node* addLists(Node *list1, Node *list2){
	Node *res = NULL;
	int sum = 0;
	int carry = 0;
	while(list1 || list2){
		sum = carry + (list1 ? list1->data:0) + (list2 ? list2->data:0);
		carry = sum >= 10 ?  1: 0;
		sum = sum % 10;
		insert(&res, sum);
		if(list1) list1 = list1->next;
		if(list2) list2 = list2->next;
	}

	if(carry > 0)
		insert(&res,carry); 
	return res;
}

void printList(Node *list, int i){
	Node *temp = list;
	std::cout<<"List "<<i<<":";
	while(temp){
		std::cout<<temp->data<<" ";
		temp = temp->next;
	}
	std::cout<<std::endl;
}

int main(){
	Node *head1 = NULL;
	insert(&head1, 5);
	insert(&head1, 6);
	insert(&head1, 3);
	printList(head1, 1);
	Node *head2 = NULL;
	insert(&head2, 8);
	insert(&head2, 4);
	insert(&head2, 2);
	printList(head2, 2);
	
	Node *res = addLists(head1, head2);
	printList(res,3);
	return 0;
}
