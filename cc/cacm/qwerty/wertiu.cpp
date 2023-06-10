#include <cstdio>
#include <iostream>
#include <map>

using namespace std;

int main(){
	map<char,char> transformaciones;
	transformaciones['W']='Q';
	transformaciones['S']='A';
	transformaciones['X']='Z';
	transformaciones['E']='W';
	transformaciones['D']='S';
	transformaciones['C']='X';
	transformaciones['R']='E';
	transformaciones['F']='D';
	transformaciones['V']='C';
	transformaciones['T']='R';
	transformaciones['G']='F';
	transformaciones['B']='V';
	transformaciones['Y']='T';
	transformaciones['H']='G';
	transformaciones['N']='B';
	transformaciones['U']='Y';
	transformaciones['J']='H';
	transformaciones['M']='N';
	transformaciones['O']='I';
	transformaciones['L']='K';
	transformaciones['.']=',';
	transformaciones['[']='P';
	transformaciones['\'']=';';
//~ transformaciones['']='/';
	
	char ch;
	
	while(scanf("%c",&ch)!=EOF){
		switch(ch){
			case '\n': 	cout << "\n"; 
						break;
			case ' ': 	cout << " ";
						break;
			default: 
						if(transformaciones.find(ch)!=transformaciones.end()) cout << transformaciones[ch];
						else cout << ch;
			
			
		}
	}
	
}
