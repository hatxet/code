#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>

struct node{
	int val;
	node *next, *prev;
};

struct node_comp{
	bool operator() (node* a, node* b){
		return a->val < b->val;
	}
};

class List{
		node *first, *last, *limit;
		int size_;
	public:
		List(){
			first = NULL;
			last = NULL;
			limit = NULL;
			size_ = 0;
		}

		void clear(){
			for (node *n = first; n != NULL; n = n->next)
				delete n;
			first = NULL;
			last = NULL;
			limit = NULL;
			size_ = 0;

		}

		int rotate(node *n){
			if (n == last) return 0;
			//if this is necessary (limit == first->next) return 0;
			int swaps = 0;	
			for (node *i = n; i->next != limit; i = i->next)
				++swaps;	

			if (n==first){
				n->next->prev = NULL;
				first = n->next;
			} else {
				n->next->prev = n->prev;
				n->prev->next = n->next;	
			}
			push_before_limit(n);
			--size_;
			return swaps;
		}
		void print(int n){
			std::cout << "[";
			if (size_ > 0){
				node *n = first;
				for ( ; n->next != NULL; n = n->next){
					std::cout << n->val << "," ;
				}		
				std::cout << n->val;
			}
			std::cout << "]: " << n <<"\n";
		}

		void push(node *n){
			if(size_==0){
				n->next = NULL;
				n->prev = NULL;
				first = n;
				last = n;
			} else{
				n->prev = last;
				last->next = n;
				last = n;
				last->next = NULL;
			}	
			++size_;
		}
		
		void push_before_limit(node *n){
			if (size_ < 2 ){
				push(n);
			} else if (limit == NULL){
				limit = n;
				push(n);
			} else {
				limit->prev->next = n;
				n->prev = limit->prev;	
				limit->prev = n;
				n->next = limit;
				limit = n;
				++size_;
			}
		
		}
		int size(){
			return size_;
		}
};

int main(){
	int num_cases, num_cars, swaps, car;
	List train;
	std::priority_queue<node*, std::vector<node*>, node_comp> p_queue;

	std::cin >> num_cases;
	for (int cases = 0; cases < num_cases; ++cases){
		swaps = 0;
		train.clear();
		while (!p_queue.empty()) p_queue.pop();

		std::cin >> num_cars;
		for (int c = 0; c < num_cars; ++c){
			std::cin >> car;
			node *n = new node;
			n->val = car;
			train.push(n);
			p_queue.push(n);
		} 
		while (p_queue.size() > 1){
			swaps += train.rotate(p_queue.top());
			train.print(swaps);
			p_queue.pop();
		}
		std::cout << "Optimal train swapping takes "<<  swaps << " swaps.\n";
	}	
}
