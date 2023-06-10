#include <iostream>
#include <deque>
#include <map>
#include <cstdio>

typedef unsigned int uint;

using namespace std;

struct turtle{
	uint value;
	string name;
	bool operator<(const turtle& t) const {
		return value < t.value;
	}
};	

int main() {
	uint num_cases, num_turtles, low, mid, up, low_pos, mid_pos, up_pos;
	uint *aturtle;
	map<uint,uint> turtle_to_aindex;
	//uint *turtle_to_aindex;
	char ch = '\t';
	int x;
	string trash;
	//string *code_to_name_map;
	map<uint, string> code_to_name_map;
	map<string, uint> name_to_code_map;
	deque<string> temp_names;

	cin>>num_cases;
	//cout << "N cases: " << num_cases << '\n';
	
	for(uint c = 0; c < num_cases; ++c){
		cin >> num_turtles;
		//if(num_turtles < 3) return -1;
		getline(cin,trash);
        //cout << "Case " << c+1 << " with "<< num_turtles << '\n';
		temp_names.clear();
		aturtle = new uint[num_turtles];
		//turtle_to_aindex = new uint[num_turtles];
		//code_to_name_map = new string[num_turtles];
    	for(uint t = 0; t < num_turtles; ++t){
        	string tname;
			getline(cin,tname,'\n');
			temp_names.push_back(tname);
			//cout << "name: \"" << tname <<"\"\n";
    	}

    	for(uint t = 0; t < num_turtles; ++t){
    		string tname;
			getline(cin,tname,'\n');
			name_to_code_map[tname] = t;	
			code_to_name_map[t] = tname;
    	}

		for(uint t = 0; t < num_turtles; ++t){
			uint t_code = name_to_code_map[temp_names.front()];
			aturtle[t] = t_code; 
			turtle_to_aindex[t_code] = t;
			//cout << "a["<<t<<"]: " << t_code << ", " << aturtle[t] << endl;
			temp_names.pop_front();
		}
	
		low = num_turtles -1;
		mid = num_turtles -2;
		up = num_turtles -3;	
		low_pos = turtle_to_aindex[low];
		mid_pos = turtle_to_aindex[mid];
		up_pos =  turtle_to_aindex[up];
		bool keepgoing = true;
		int cascade = -1;

		while(low_pos > mid_pos && mid_pos > up_pos){
			low = up;	
			mid = up-1;
			up = up-2;
			low_pos = turtle_to_aindex[low];
			if(mid < num_turtles){
				mid_pos = turtle_to_aindex[mid];
			} else {
				mid_pos = 0;
			}
			if(up < num_turtles){
				up_pos =  turtle_to_aindex[up];
			} else {
				up_pos = 0;
			}
		}
	  	if (mid_pos > low_pos){
			//cout << "cascade on " << aturtle[mid_pos] << endl;
			cascade = aturtle[mid_pos];
		} else if (up_pos > mid_pos){
			//cout << "cascade on " << aturtle[up_pos] << endl;
			cascade = aturtle[up_pos];
		}
		for(int t = cascade; t >= 0; --t){
			cout <<code_to_name_map[t] << '\n'; 	
		}			
		cout << '\n';
		delete[] aturtle;
		//delete[] turtle_to_aindex;
		//delete[] code_to_name_map;
	}
	return 0;
}
