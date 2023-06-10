#include <iostream>
#include <cmath>

int main(){
	int v=0;
	unsigned int i,a = 83;
	i = 0;
	do {
		v = (v*10+1) % a;
		std::cout << "v: " << v << std::endl;
		++i;	
	}while(v!=0);
	std::cout << "i: " << i << std::endl;
	return 0;
}
