#include <iostream>
#include <iomanip>
#include <vector>
#include <sys/time.h>

typedef std::vector<int (*)(int, int)> fint_v;
typedef std::vector<std::string> fname_v;

int plus(int a, int b){
	return a+b;
}

int mult(int a, int b){
	return a*b;
}

int diff(int a, int b){
	return a-b;
}

	
double current_time () { //returns current time in seconds
	timeval tv;
	gettimeofday(&tv, NULL);
	double rtn_value = (double) tv.tv_usec;
	rtn_value /= 1e6;
	rtn_value += (double) tv.tv_sec;
	return rtn_value;
}

void tester(fint_v& funcs, fname_v& names,unsigned long nreps){
	if (funcs.size() != names.size()) return;
	int a=2, b=3;	
	double start, stop;
	std::cout << "Arguments: a="<<a<<", b="<<b<<'\n';
	for (int i = 0; i < funcs.size(); ++i){
		start = current_time();	
		for(int n = 0; n < nreps; ++n){
			funcs[i](a,b);
		}
		stop = current_time();
		std::cout << std::setprecision(3) << names[i] << ": " << funcs[i](a,b) << " avg: " << ((stop-start)/nreps) << '\n';
	}
			
}
int main(){
	
	fint_v fvector {plus, mult, diff};
	fname_v fnames {"Plus", "Mult", "Diff"};
	tester(fvector, fnames, 10000);
//	int(*fplus)(int,int) = plus;
//	int(*fmult)(int,int) = mult;
//	int(*fdiff)(int,int) = diff;
//	fvector.push_back(plus);
//	fvector.push_back(mult);
//	fvector.push_back(diff);

		
}
