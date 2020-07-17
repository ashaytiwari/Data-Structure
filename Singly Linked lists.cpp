//C++ program to illustrate the Implementation of Linked List (Singly)
#include<iostream>
using namespace std;
class Node{
	public: 
	int data;
	Node* next;
};

//This fun. prints the values of the nodes
void printList(Node* n){
	cout << "Values of the Singly linked list nodes" << endl;
	while(n != NULL){
		cout << n->data << endl;
		n = n->next;
	}
}

//This fun. is to insert the node at the front position
void push(Node** head_ref, int new_data){
	Node* new_node = new Node();
	new_node->data = new_data;
	new_node->next = (*head_ref);
	(*head_ref) = new_node;
}

//This fun. insert the node after any node
void insertAfter(Node* prev_node, int new_data){
	if(prev_node == NULL){
		cout << "The given previous node can't be null" << endl;
		return;
	}
	Node* new_node = new Node();
	new_node->data = new_data;
	new_node->next = prev_node->next;
	prev_node->next = new_node;
}

//This fun. is to insert the node at last
void append(Node** head_ref, int new_data){
	Node* new_node = new Node();
	Node *last = *head_ref;
	new_node->data = new_data;
	new_node->next = NULL;
	if(*head_ref == NULL){
		*head_ref = new_node;
		return;
	}
	while(last->next != NULL)
		last = last->next; 
		
		last->next = new_node;
		return;

}

// This function is to delete the node from list
void deleteNode(Node** head_ref, int position) {
	if(*head_ref == NULL){
	cout << "List is empty" << endl;
	return;	
	}
	
	Node* temp = new Node();
	temp = *head_ref;
	
	if(position == 0){
		*head_ref = temp->next;
		delete(temp);
		return;
	}
	
	for(int i = 0; temp != NULL && i < position-1; i++){
		temp = temp->next;
	}
	
	if (temp == NULL || temp->next == NULL) {
		cout << "Position is not valid" << endl;
		return; 
	}
         
         
	Node* next = new Node();
	next = temp->next->next;
	delete(temp->next);
	temp->next = next;
}

//Program to create a three node linked list
int main(){
	Node* head = NULL;
	Node* second = NULL;
	Node* third = NULL;
	
	//allocate three nodes in heap
	head = new Node();
	second = new Node();
	third = new Node();
	
	//put the values in the nodes and linked them
	head->data = 100;
	head->next = second;
	
	second->data = 200;
	second->next = third;
	
	third->data = 300;
	third->next = NULL;
	  
	printList(head);
	
	//Inserting a node in Single linked list
	
	//At the front of the List
	push(&head, 500);
	printList(head);
	
	//At the required position
	insertAfter(second->next, 8);
	printList(head);
	
	//At the last position
	append(&head, 600);
	printList(head);
	
	//Delete Node
	deleteNode(&head, 4 );
	printList(head);
	
	return 0;
}

