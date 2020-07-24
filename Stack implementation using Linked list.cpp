//Implementation of stack using linked list
#include<iostream>
using namespace std;
class Stack{
	public:
		int data;
		Stack* next;
};
Stack* head = NULL;

void printList(){
	Stack* new_node = head;
	cout << "Values of the Singly linked list nodes" << endl;
	while(new_node != NULL){
		cout << new_node->data << endl;
		new_node = new_node->next;
	}
} 

bool isEmpty(){
	if(head == NULL){
		return true;
	}
	else{
		return false;
	}
}

void push(int data){
	Stack* new_node = new Stack();
	new_node->next = head;
	new_node->data = data;
	head = new_node;
}

int pop(){
	if(isEmpty()){
		cout << "List is empty" << endl;
		return 0;
	}
	else{
		Stack* new_node = head;
		head = head->next;
		delete(new_node);
	}
}

int peek(){
	if(isEmpty()){
		cout << "Stack is empty" << endl;
		return 0;
	}
	else{
		return head->data;	
	}
	
}

int main(){
	push(10);
	push(20);
	push(30);
	printList();
	pop();
	pop();
	printList();
	return 0;
}

