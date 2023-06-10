#include <iostream>
#include <cstdio>
#include <sstream>


int main(){
	unsigned long t, n[2];	
	std::cin >> t;
	std::stringstream ss;
	while(scanf("%ld %ld", &n[0], &n[1])!= EOF){
		if(n[0]>n[1]) ss << ">" << '\n';
		else if(n[0]<n[1]) ss << "<" << '\n';
		else if(n[0]==n[1]) ss << "=" << '\n';
	}
	std::cout << ss.str();
}
