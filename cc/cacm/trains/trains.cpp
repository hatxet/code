#include <iostream>

int main(){
	int num_cases, num_cars, swaps, *train;
	std::cin >> num_cases;
	for (int cases = 0; cases < num_cases; ++cases){
		swaps = 0;

		std::cin >> num_cars;
		train = new int[num_cars];
		for (int c = 0; c < num_cars; ++c){
			std::cin >> train[c];
		} 

		for (int i = 0; i < num_cars-1; ++i){
			for (int j = i+1; j < num_cars; ++j){
				if (train[i] > train[j]) ++swaps;
			}
		}
		std::cout << "Optimal train swapping takes "<<  swaps << " swaps.\n";
		delete[] train;
	}	
}
