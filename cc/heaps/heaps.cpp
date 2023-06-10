#include <iostream>
#include <vector>


class heap{
		// Atts
		std::vector<int> data_;
		bool (*comparison_func)(int, int);

		// Meth
		void build_heap(){

			for (int i = (data_.size()-1)/2; i >=0; --i){
				heapify(i);
			}
		}

		void heapify(int pos){
			int l, r, max;

			if (pos > data_.size()/2) return;
			std::cout << "Heapify at pos: " << pos << std::endl;
			print_data();
			l = left(pos);
			r = right(pos);

			if (default_cmp(data_[pos], data_[l])){
				swap(pos, l);
				max = l;
			}

			if (r < data_.size() && default_cmp(data_[pos], data_[r])){
				swap(pos, r);
				max = r;
			}

			heapify(max);
		}

		void swap(int a, int b){
			int t = data_[a];
			data_[a] = data_[b];
			data_[b] = t;
		}

		bool default_cmp(int a, int b){
			return a < b;
		}

		int left(int pos){
			return (pos << 1) + 1;
		}

		int right(int pos){
			return pos << 1;
		}
	
		int parent(int pos){
			return pos >> 1;
		}

	public:
		heap(){}

		heap(int *array, int size){
//			comparison_func = &default_cmp;
			data_.reserve(size);

			for (int i = 0; i < size; ++i)
				data_.push_back(array[i]);

			build_heap();
		}

		void insert(int a){
			data_.push_back(a);
			int i = data_.size();
			do{
				i = parent(i);	
				heapify(i);
			} while (i != 1);
		}

		void pop(){
			data_.front() = data_.back();
			data_.resize(data_.size()-1);
			heapify(0);	
		}

		int size(){ return data_.size(); }

		int top(){
			return data_.front();
		}

		void print_data(){
			std::cout << "Array: ["	;
			for (int i = 0; i < data_.size()-1; ++i)
				std::cout << data_[i] << ",";
			std::cout << data_.back() << "]\n";
		}

		void print(){
			if (data_.empty()) return;

			print_data();
			std::cout << "Heap: [";
			while (data_.size() > 1){
				std::cout << top() << ",";
				pop();
			}
			std::cout << data_.back() << "]\n";
			data_.clear();
		}
};


int main(){
	int a[] = {3,0,16,7, 9, 1};
	heap h(a, 6);
	h.insert(100);
	h.print();
}
