#include <iostream>
#include <cstdio>
#include <map>

int main(){
		char c;
        std::map<char,char> mymap;
        mymap['2']='1';
        mymap['3']='2';
        mymap['4']='3';
        mymap['5']='4';
        mymap['6']='5';
        mymap['7']='6';
        mymap['8']='7';
        mymap['9']='8';
        mymap['0']='9';
        mymap['-']='0';
        mymap['=']='-';
        mymap['W']='Q';
        mymap['E']='W';
        mymap['R']='E';
        mymap['T']='R';
        mymap['Y']='T';
        mymap['U']='Y';
		mymap['I']='U';
        mymap['O']='I';
        mymap['P']='O';
        mymap['[']='P';
        mymap[']']='[';
        mymap['\\']=']';
        mymap['S']='A';
        mymap['D']='S';
        mymap['F']='D';
        mymap['G']='F';
        mymap['H']='G';
        mymap['J']='H';
        mymap['K']='J';
        mymap['L']='K';
        mymap[';']='L';
        mymap['\'']=';';
        mymap['X']='Z';
        mymap['C']='X';
        mymap['V']='C';
        mymap['B']='V';
        mymap['N']='B';
		mymap['M']='N';
        mymap[',']='M';
        mymap['.']=',';
		mymap['/']='.';

	while((c=getchar())!=EOF)
			std::cout << (mymap.count(c)) ? mymap[c] : c;
	
}
