#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>

#define MAX_ANS 4
#define MAX_TRY 2

using namespace std;
typedef unsigned int uint;

static const char SOL_MARK = 'X'; // This will mark the solution to the question.
static const string RIGHT_ANS = "OK";
static const string WRONG_ANS = "WRONG";

class question{
		string _title, _answers[MAX_ANS];
		uint _sol_pos;
		
	public:
		question(){
			_title = "";
			_sol_pos=0;
			for(uint i = 0; i < MAX_ANS; ++i){
				_answers[i] = "";
			}
		}

		void title(string t){
			_title = t;
		}
		
		void answer(string a, uint pos){
			if(pos < MAX_ANS)
				_answers[pos] = a;
		}		
		
		void sol(uint pos){
			_sol_pos = pos;
		}
		
		uint sol(){
			return _sol_pos;
		}

		bool check_ans(uint a){
			return (a <= MAX_ANS) && (a == _sol_pos);
		}	

		void randomize(){
			srand( time(0) );
			for (int i=0; i<MAX_ANS-1; i++) {
				int r = i + (rand() % (MAX_ANS-i));
				//cout << "Replacing [" << i << "]\""<<_answers[i]<< "\" with [" << r << "]\"" << _answers[r] << "\"\n";
   	     		string temp = _answers[i]; _answers[i] = _answers[r]; _answers[r] = temp;
				if(r+1 == _sol_pos){
				//	cout << "Since answer is " << _sol_pos << ", new ans is " << i+1 << endl;
					 _sol_pos = i+1;
				} else if(i+1 == _sol_pos){
				//	cout << "Since answer is " << _sol_pos << ", new ans is " << r+1 << endl;
					 _sol_pos = r+1;
				}
			}
		}

		void print(ostream& out) const {
			out << " \"" << _title << "\"\n";		
			for(int i = 0; i < MAX_ANS; ++i)
				out << '\t' << i+1 << ") " << _answers[i] << '\n';
		}
		
		vector<string> answers(){
			
		}
};

ostream& operator<<(ostream& out, const question& q){
		q.print(out);
		return out;
}

bool read_question(ifstream& input, vector<question>& questions){
	question q;
	string question="", answer, s;

	getline(input, question, '\n');
	if(question == "" ) return false;
	q.title(question);

	for(int i = 0; i < MAX_ANS; ++i){
		getline(input, s, '\n');
		if( s[s.length()-1] == SOL_MARK ){
			//cout << "Found sol at pos" << i+1 << endl;
			q.sol(i+1);
			s.resize(s.length()-1);
		}
		q.answer(s, i);	
	}
	questions.push_back(q);
	getline(input,s,'\n');
	return true;
}

bool read_input(vector<question>& questions){
	ifstream ifile;
	ifile.open("input");

	if( ifile.is_open() ) // Try reading till you find a question
		while(ifile.good() && read_question(ifile,questions));
	else
		return false;

	ifile.close();
	return true;
}

void randomize(vector<question>& questions){
	srand ( time (0) );	
	random_shuffle ( questions.begin(), questions.end() );
}

float score(int right, int wrong, int total){
	return (right-(wrong*0.33))/total*10;	
}

void print_results(int right,int wrong,int total){
	cout.precision(2);
	cout << "Right " << right << " (" << ((double)right/total)*100
		 << "%) / Wrong " << wrong << " / Total "<< total
		 << " ["<< score(right, wrong, total) <<"]" << endl;

}

void begin_test(vector<question>& questions){
	int ans = -1;
	uint tries=0, right=0, wrong=0, total=0;
	bool next_question = false, interrupt = false;

	for(vector<question>::iterator it = questions.begin(); it != questions.end() && !interrupt; ++it){
		(*it).randomize();
		cout << total +1 << "] ";
		cout << (*it);

		next_question = false;
		tries = 0;
		do{	
			cin >> ans;
			if( cin.eof() ) interrupt = true; // Stop the test.
			else {
				if(ans < 0) {		// Negative answers count as a pass.
					++total; 		// User might finish before all questions are printed, keep track of printed questions.
					next_question = true; 
				} else {
					if( (*it).check_ans(ans) ){
						cout << RIGHT_ANS << '\n'; // Good for you.
						++right;
						++total;
						next_question = true;
					} else {
						cout << WRONG_ANS << '\n';
						if( ++tries >= MAX_TRY){ // Wrong and out of tries.
							++total;
							++wrong;		
							next_question = true; 
						}
					}
				}
			}
		}while(!interrupt && !next_question);
	}

	if(total>0) print_results(right, wrong, total);
}

template <typename T>
void print_vector(vector<T>& v){
	for(int i = 0; i < v.size(); ++i)
		cout << v[i] << endl;
}

int main(){
	vector<question> questions;

	if(!read_input(questions))
		return -1;

	randomize(questions);

	begin_test(questions);
	return 0;
}
