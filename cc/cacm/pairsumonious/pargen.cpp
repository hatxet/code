#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

int main(){
	vector<int> sums;
	int *input_numbers;
	int n, max_nums,i=0;	
	
	cin >> max_nums;
	input_numbers = new int[max_nums];

	while(i < max_nums){
		cin >> n;
		input_numbers[i++] = n;	
	} 			

	for(int j = 0; j < i; ++j){
		for(int k = j+1; k < i; ++k){
			sums.push_back(input_numbers[j] + input_numbers[k]);	
		}	
	}	

	//srand(unsigned (time(0)));
	//random_shuffle( sums.begin(), sums.end() );		
	cout << sums.size() << ' ';
	for(vector<int>::iterator it = sums.begin(); it != sums.end(); ++it){
		cout << *it << ' '; 
	}
	cout << endl;
	delete[] input_numbers;
}
