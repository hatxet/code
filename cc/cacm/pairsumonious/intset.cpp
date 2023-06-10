#include <iostream>

using namespace std;

void binary(int number) {
	int remainder;

	if(number <= 1) {
		cout << number;
		return;
	}

	remainder = number%2;
	binary(number >> 1);    
	cout << remainder;
}
void unset(int &n, int pos){
	n &= ~(1 << pos);
}
void set(int& n, int pos){
	n |= 1<<pos;
}

bool test(int& n, int pos){
	
}
bool check(int n, int b){
	int mask = (1<<(b))-1;
	n &= mask;
	return n==mask;
}

int main(){
	int n = 0;
	int t = 4;

	for(int i = 0; i < t; ++i){
		set(n,i);
		binary(n);	
		cout << endl;
		cout << check(n, t);
		cout << endl;
	}	
	unset(n,2);
	binary(n);	
	cout << endl;
	cout << check(n, t);
	cout << endl;
}

