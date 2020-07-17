//C++ program to illustrate the dynamic memory allocation using new and delete operator
#include<iostream>
using namespace std;
int main(){
	int size;
	
	cout << "Enter the size for dynamic allocation \n" ;
	cin >> size ;

	int *p = new(nothrow) int;
	if(!p){
		cout << "Memory Full \n" ;
	}
	else{
		*p = 29;
		cout << "Value of p : " << *p << endl;
	}
	
	float *r = new float(75.35);
	cout << "Value of r : " << *r << endl;
	
	int *q = new(nothrow) int[10];
	if(!q){
		cout << "Memory Full \n";
	}
	else{
		for(int i = 0; i < size; i ++){
			q[i] = i+1 ; 
		}
		cout << "Value of the block q : \n";
		for(int i = 0; i < size; i ++){
			cout << q[i] << endl;
		} 
	}
}
