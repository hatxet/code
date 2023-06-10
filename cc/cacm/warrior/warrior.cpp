#include <cstdio>

typedef unsigned long ulong;

int main(){
	ulong num1,num2,*max,*min;
	while(scanf("%ld %ld",&num1,&num2)!=EOF){
		 if(num1 > num2){
			max = &num1; min = &num2;
		} else {
			max = &num2; min = &num1;
		}
		printf("%ld\n",*max-*min);
	}
	return 0;
}
