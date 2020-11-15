#include <iostream>
#include <stack> 
using namespace std; 

void print_stack(stack<int> s) { 
	while (!s.empty()) { 
		cout << " " << s.top(); 
		s.pop(); 
	} 
	cout << '\n'; 
} 

int main () 
{ 
	stack<int> s; 
	s.push(12); 
	s.push(3); 
	s.push(21); 
	s.push(6); 
	s.push(13); 

	cout << "The stack is : "; 
	print_stack(s); 
	cout << endl;

	cout << "size : " << s.size() << endl; 
	cout << "top element : " << s.top() << endl; 

	cout << "After popping : "; 
	s.pop(); 
	print_stack(s); 
	cout << endl;
	return 0; 
} 
