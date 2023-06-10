#include <iostream>

long lazy(long n){
 return (n*(n-1)/2)+1;
}

int main(){
long n;
while(std::cin >> n){
 if(n < 0) break;
 std::cout << lazy(n+1) << '\n';
}
return 0;
}
