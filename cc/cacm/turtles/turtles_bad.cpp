#include <cstdio>
#include <iostream>
#include <map>

using namespace std;

typedef unsigned int uint;

class node{
		uint _value;
		string _name;
		node* _next;
		node* _prev;
		node* _suc;
		node* _pred;
		bool _static;
	public:
		node(){}
		node(string n, int v){
			_value = v;
			_name = n;
			_next = NULL;
			_prev = NULL;
			_suc = NULL;
			_pred = NULL;
		}
		uint value(){ return _value; }
		string name() { return _name; }
		node* next(){ return _next; } 
		node* prev(){ return _prev; }
		node* suc() { return _suc; }
		node* pred() { return _pred; }
		void setv(uint v){ _value = v; } 
		void link_prev(node* p){
		}
		void link_next(node *n){
			_next = n;
		}
		void link_suc(node *s){
			_suc = s;
		}
		void link_pred(node *p){
			_pred = p;
		}
		bool ispred(node *p){
			return _value == p->value() -1;
		}
		bool issuc(node *s){
			return _value == s->value()+1;
		}
};

class list{
		uint _size;
		node* _first;
		node* _last;
		node* _max;
		node* _limit;
	public:
		list(){ _size = 0; _first = NULL; _last = NULL; }
		node* first() { return _first; }
		node* last() { return _last; }
		int size() { return _size; }
		void push_back(node* n){
			if(_size == 0) {
				_first = n;
				_last = n;
				_max = n;
			} else {
				_last->link_next(n);			
				n->link_prev(_last);
				_last = n;
				_limit = n;
				if(_max->value() < n->value()) _max = n;
			}
			if(n->issuc(_last)){ // n is right after "last" in value (n=3, last=2, this would be true);
				_last->link_suc(n);
				n->link_pred(_last);
			}	
			++_size;
		}
		
		void check_limit(){
			if(_max->value() == _limit->value()){
				for( node *n = _max; n != null; n = n->pred() )
					_limit = n;
			}
			
		}
		int sort(){
			check_limit();
			if(_limit != _last){
				node *candidate = _max->next();	
				for(node *n = _max->next(); n != NULL;  n = n->next() ){
				}
			} 
				
		}
		
		void print(){
			for(node *n = first(); n != NULL; n = n->next())
			cout << n->name() << " (" << n->value() << ")\n";
		}
};



int main() {
	int num_cases, num_turtle_stack;
	char c;
	
	map<string,node> turtle_map;
	list turtle_stack;

	cin >> num_cases;
	cout << "N cases: " << num_cases << '\n';
	cin >> num_turtle_stack;
	while(c=getchar() == '\n');

	for(int c = 0; c < num_cases; ++c){
		cout << "Case " << c+1 << '\n';
		for(int t = 0; t < num_turtle_stack; ++t){
			string tname;
			getline(cin,tname);
			node n (tname, t);
			pair<map<string,node>::iterator,bool> ret;
			ret = turtle_map.insert (pair<string,node>(tname,n));
			//turtle_map[tname] = n;
			turtle_stack.push_back(&(ret.first->second));
			//cout << "Creating turtle node (" << n.name() << "," << n.value() << ")\n";
		}	
		
		for(int t = 0; t < num_turtle_stack; ++t){
			string tname;
			getline(cin,tname);
			node *n = &turtle_map[tname];
			n->setv(t);
			//cout << "Pushing (" << n->name() << ") to the stack.\n";
		}
	}
	turtle_stack.print();
}
