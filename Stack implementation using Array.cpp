//Implementation of Stack using Array
#include<iostream>
using namespace std;
#define MAX 1000

class Stack{
	int top;
	
	public: 
	int a[MAX];
	Stack(){
		top = -1;
	}
	
	bool push(int x);
	int pop();
	int peek();
	bool isEmpty();
}; 

bool Stack :: push(int x){
	if(top >= MAX-1){
		cout << "Stack Overflow" << endl ;
		return false;
	}
	else{
		a[++top] = x;
		cout << x << " Pushed" << endl;
		return true;
	}
}

int Stack :: pop(){
	if(top < 0 ){
		cout << "Stack underflow" << endl ; 
		return 0;
	}
	else{
		int x = a[top--];
		cout << x << " Popped" << endl;
	}
}

int Stack :: peek(){
	if(top < 0){
		cout << "Stack is Empty" << endl;
		return 0;
	}
	else{
		int x = a[top];
		cout << x << " Top Element" << endl;
	}
}

bool Stack :: isEmpty(){
	return (top > 0);
}

int main(){
	class Stack object;
	object.push(10);
	object.push(20);
	object.push(30);
	object.peek();
	object.pop();
	object.peek();
	cout << "Stack is empty " << object.isEmpty();
	
	return 0;
}
