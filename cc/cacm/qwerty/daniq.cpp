#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <sstream>

using namespace std;

int main( int argc, char *argv[] )
{
	string uno[] = {"`1234567890-=", "QWERTYUIOP[]\\", "ASDFGHJKL;'", "ZXCVBNM,./"};
	string line;
	getline(cin, line);
	while(!cin.eof()){
		string line2 = "";
		for(char& c : line) {
			bool found = false;
			int i = 0;
			char c2;
			while(!found  && i <4) {
					int pos = uno[i].find(c);
					if (pos>-1) {
						c2 = uno[i].at(pos-1);
						found = true;
					}
					
					i++;
				}
			if (!found)
				c2 = c;
			
			line2 = line2+c2;
		}
		for(char& c : line2) {
			cout << c;
		}
		getline(cin, line);
	}

    
	return 0;
}

