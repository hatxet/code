#include <iostream>
#include <deque>
#include <map>
#include <cstdio>

#define BUFFER 80
typedef unsigned int uint;

using namespace std;

int main() {
	uint num_cases, num_turtles, low, mid, up, low_pos, mid_pos, up_pos;
	uint *aturtle, *turtle_to_aindex;
	char ch, **code_to_name_map, **temp_names;
	map<char*, uint> name_to_code_map;

	scanf("%d",&num_cases);
	//cout << "N cases: " << num_cases << '\n';
	
	for(uint c = 0; c < num_cases; ++c){
		scanf("%d",&num_turtles);
        //cout << "Case " << c+1 << " with "<< num_turtles << '\n';
		aturtle = new uint[num_turtles];
		turtle_to_aindex = new uint[num_turtles];
		code_to_name_map = new char*[num_turtles];
		temp_names = new char*[num_turtles];	
		getchar();
    	for(uint t = 0; t < num_turtles; ++t){
			temp_names[t] = new char[BUFFER];
			uint i = 0;
			while((ch=getchar()) != '\n'){
				temp_names[t][i++] = ch;
			}
			temp_names[t][i] = '\0';
			//cout << "name: \"" << tname <<"\"\n";
    	}

    	for(uint t = 0; t < num_turtles; ++t){
			code_to_name_map[t] = new char[BUFFER];
			uint i = 0;
			while((ch=getchar()) != '\n'){
				code_to_name_map[t][i++] = ch;
			}
			code_to_name_map[t][i] = '\0';
			name_to_code_map[code_to_name_map[t]] = t;	
			cout << "name_map[\""<< code_to_name_map[t] << "\"] -> " << name_to_code_map[code_to_name_map[t]] << endl;
    	}

		for(uint t = 0; t < num_turtles; ++t){
			uint t_code = name_to_code_map[temp_names[t]];
			aturtle[t] = t_code; 
			turtle_to_aindex[t_code] = t;
			cout << "t_code: name_map[\""<< temp_names[t] << "\"] -> " << t_code << endl;
			cout << "a["<<t<<"]: " << t_code << " -> " << aturtle[t] << endl;
		}
	
		bool keepgoing = true;
		int cascade = -1;
		int count = 0;
		up = num_turtles -1;		
		do{
			++count;
			low = up;	
			mid = up-1;
			up = up-2;
			low_pos = turtle_to_aindex[low];
			mid_pos = (mid < num_turtles) ? turtle_to_aindex[mid] : 0;
			up_pos  = (up < num_turtles) ? turtle_to_aindex[up] : 0;
		} while(low_pos > mid_pos && mid_pos > up_pos);
	  	if (mid_pos > low_pos){
			//cout << "cascade on " << aturtle[mid_pos] << endl;
			cascade = aturtle[mid_pos];
		} else if (up_pos > mid_pos){
			//cout << "cascade on " << aturtle[up_pos] << endl;
			cascade = aturtle[up_pos];
		}
		for(int t = cascade; t >= 0; --t){
			printf("%s\n",code_to_name_map[t]); 	
		}			
		cout << count << '\n';
		delete[] aturtle;
		delete[] turtle_to_aindex;
		delete[] code_to_name_map;
	}
	return 0;
}
