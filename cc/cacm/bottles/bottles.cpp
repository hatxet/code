#include <iostream>

using namespace std;

const int N=3,B=0,G=1,C=2;

char letter(int n){
	char ch =  '\0';
	switch(n){
		case 0: ch = 'B';
				break;
		case 1: ch = 'G';
				break;
		case 2: ch = 'C';
				break;
	}
	return ch;
}
int fact(int f){
	int t = 1;
	while(f > 1){
		t *= f--;
	}
	return t;
}

int index(int x, int y){
	return x*N+y;
}

int shift(int *a, int size){
	for(int i = 0; i<size; ++i)
		a[i] = (a[i]+1)%size;
}

int print_array(int *a, int size){
	for(int i =0; i<size;++i)
		cout << (a[i]) << " ";
	cout << endl;
}

int mod(int a, int m){
	if(a < 0) { 
		a = 0-a;
		a = a%m;
		a = (a == 0) ? a : m-a;
	} else { 
		a = a%m;
	}
	return a;
}
int main(){
	int temp,comb[N],nums[N*N];
	for(int i = 0; i<N*N; ++i){
		//cin >> nums[i];
	}
	comb[B] = B; comb[G] = G; comb[C] = C;
	for(int i = 0; i < N; ++i){
		for(int j = 0; j < 2; ++j){ 
			print_array(comb,N);
			temp = comb[1];
			comb[1] = comb[2];
			comb[2] = temp;
		}		
	}
}
