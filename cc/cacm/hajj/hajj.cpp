#include <cstdio>

int main(){
	char ch;
	int cas=1;
	while ((ch=getchar()) != EOF && ch != '*'){
		if (ch=='H') printf("Case %d: Hajj-e-Akbar\n", cas);
		if (ch=='U') printf("Case %d: Hajj-e-Asghar\n", cas);
		++cas;
		while(ch != '\n') ch = getchar();
	}
}
