#include <cmath>

void swap(T* array, int pos_a, int pos_b){
	T temp = array[pos_a];
	array[pos_a] = array[pos_b];
	array[pos_b] = temp;
}

void introsort(T* array, int a_size, int maxdepth, int left, int right){
	if (a_size <= 1){
		return;
	} else if (maxdepth == 0){
		heapsort(array, size, left, right);
	} else {
		int p = 
		introsort(array, a_size, --maxdepth, )
	}
}
