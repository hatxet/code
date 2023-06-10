#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class estado{
        vector<int> _v;
    public:
        estado(vector<int>& v){
			for(int i =0; i<v.size(); ++i)	
				for(int j =i+1; j<v.size(); ++j)	
					_v.push_back(v[i]+v[j]);	
			sort(_v.begin(), _v.end());
        }
        int size(){
            return _v.size();
        }
        int operator[](int pos) const{
            return _v[pos];
        }
		int &operator[](int pos){
			return _v[pos];
		}
        bool operator==(estado& a){
            for(int i=0;i<_v.size();++i){
                if(_v[i]!=a[i]){
                    return false;
                }
            }
            return true;
        }
		void print(){
			cout << "[";
			for(int i = 0; i< _v.size(); ++i) 
				cout << _v[i] << ",";
			cout << "]\n";
		}
};

int main(){
	vector<int> a,b;
	int M = 4;
	for(int i = 0; i < 4; ++i)	{
		a.push_back(i);
		cout << "a.push(" << i << ")"<<endl;
	}
	estado x(a),y(b);
	x.print();
	cout << endl;
}

