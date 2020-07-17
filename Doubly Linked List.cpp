//C++ program to illustrate the Implementation of Linked List (Doubly)
#include<iostream>
using namespace std;
class Node{
	public: 
	int data;
	Node* next;
	Node* prev;
};

//This fun. prints the values of the nodes
void printList(Node* node){
	Node* last;
	cout << "Traversal in forward Direction" << endl;
	while(node != NULL){
		cout << node->data << endl;
		last = node;
		node = node->next;
	}
	
	cout << "Traversal in reverse Direction" << endl;
	while(last != NULL){
		cout << last->data << endl;
		last = last->prev;
	}
	cout << "\n";
}

//This fun. is to insert the node at the front position
void push(Node** head_ref, int new_data){
	Node* new_node = new Node();
	new_node->data = new_data;
	
	new_node->next = (*head_ref);
	new_node->prev = NULL;
	
	if((*head_ref) != NULL){
		(*head_ref)->prev = new_node;
	}
	
	(*head_ref) = new_node;
}

//This fun. insert the node after any node
void insertAfter(Node* prev_node, int new_data){
	if(prev_node == NULL){
		cout << "Prev_node can't be null" << endl;
		return;
	}
	
	Node* new_node = new Node();
	new_node->data = new_data;
	new_node->next = prev_node->next;
	prev_node->next = new_node;
	new_node->prev = prev_node;
	
	if(new_node->next != NULL){
		new_node->next->prev = new_node;
	}
}

//This fun. is to insert the node at last
void append(Node** head_ref, int new_data){
	Node* new_node = new Node();
	Node* last = *head_ref;
	new_node->data = new_data;
	new_node->next = NULL;
	
	if(*head_ref == NULL){
		new_node->prev = NULL;
		*head_ref = new_node;
		return;
	}
	
	while(last->next != NULL){
		last = last->next;
	}
	
	last->next = new_node;
	new_node->prev = last;
	
	return;
}

//This fun. insert the node before any node
void beforeNode( Node** head_ref, Node* next_node, int new_data){
	if(next_node == NULL){
		cout << "Next_node can't be null";
		return;
	}
	
	Node* new_node = new Node();
	new_node->data = new_data;
	
	new_node->prev = next_node->prev;
	next_node->prev = new_node;
	new_node->next = next_node;
	if (new_node->prev != NULL)  
        new_node->prev->next = new_node; 
    else
        (*head_ref) = new_node; 
      
}

// This function is to delete the node from list
void deleteNode(Node** head_ref, Node* del){
	if(*head_ref == NULL || del == NULL){
		return;
	}
	
	if(*head_ref == del){
		*head_ref = del->next;
	}
	
	if(del->next != NULL){
		del->next->prev = del->prev;
	}
	
	if (del->prev != NULL)  
        del->prev->next = del->next; 
        
    delete(del);
    return;
}

int main(){
	Node* head = NULL;
	//Inserting a node in Single linked list 
	
   //At the starting position
	push(&head, 10);
	push(&head, 5);
	printList(head);
	
	//Insert after any position 
	insertAfter(head->next, 15);
	printList(head);
	
	//At the last position
	append(&head, 20);
	printList(head);
	
	//Insert before any position 
	beforeNode(&head, head, 25);
	printList(head);
	
	//Delete Node
	deleteNode(&head, head->next);
	printList(head);
}
