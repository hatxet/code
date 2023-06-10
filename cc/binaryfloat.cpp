#include <iostream>
#include <cstdio>
#include <iomanip>
#include <vector>

#define DOUBLE 1
using namespace std;

const char CHARBITS = 8;
const char DOUBLEBYTES = 8;
const char FLOATBYTES = 4;

void fill_array(char* pointc, char* binary, char max_bytes){
	for (int byte = 0; byte < max_bytes; ++byte){
		for (int cbit = 0; cbit < CHARBITS; ++cbit){
			int i = ((pointc[byte] >> cbit) &1);
			binary[byte*CHARBITS+cbit] = i; 
		}
	}
}

void float_number(){
	char *pointc, binary[FLOATBYTES*CHARBITS]; // max 64bits = 8 bytes * 8 bits;
	float pointf, man, temp;
	int exp;

    while (scanf("%f", &pointf) != EOF){
		man = 1;
		exp = 0;
		pointc = reinterpret_cast<char*>(&pointf);
		fill_array(pointc, binary, FLOATBYTES);

		// print sign
		printf("%d ", binary[31]);

		// print exp
		for (int i = 30; i >= 23; --i){
			if (binary[i]){
				exp += 1 << (8-(31-i));
			}
			printf("%d", binary[i]);
		}
		putchar(' ');

		// print mantissa		
		for (int i = 22; i >= 0; --i){
			if (binary[i]){
				temp = 1 << (23-i);
				man += 1 / temp;
			}
			printf("%d", binary[i]);
		}
		printf("\ns: %d ",-1 * binary[31]);	
		printf(" | exp: 2^(%d)", exp-127); 
		printf(" | man: %f", man);
		printf(" | r: %f\n", (1.0/(1<<(127-exp))) * man);
		putchar('\n');
	}
}

void double_number(){
	char *pointc, binary[DOUBLEBYTES*CHARBITS]; // max 64bits = 8 bytes * 8 bits;
	double pointd;

    while (scanf("%lf", &pointd) != EOF){
		pointc = reinterpret_cast<char*>(&pointd);
		fill_array(pointc, binary, DOUBLEBYTES);

		// print sign
		printf("%d ", binary[63]);
		
		// print exp
		for (int i = 62; i >= 52; --i)
				printf("%d", binary[i]);
		putchar(' ');

		// print mantissa		
		for (int i = 51; i >= 0; --i){
				printf("%d", binary[i]);
		}
		putchar('\n');
	}
}
int main(int argc, char** argv)
{
	if(argc >= 2 && *argv[1] == 'f')
		 float_number();
	else
		 double_number(); 
}
