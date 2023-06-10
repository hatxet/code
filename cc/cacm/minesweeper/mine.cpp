#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <limits>

int w, h, **mines, size, pos;

void inc(int x, int y){
	if (x >= 0 && x < w && y >= 0 && y < h) ++mines[x][y];
}

void adj_inc(int x, int y){
	mines[x][y] = std::numeric_limits<int>::min();
	inc(x-1, y-1);
	inc(x-1, y);
	inc(x-1, y+1);
	inc(x, y-1);
	inc(x, y+1);
	inc(x+1, y-1);
	inc(x+1, y);
	inc(x+1, y+1);
}

int main(){
	char ch, field=0;
	while(scanf("%d %d",&w,&h) != EOF){
				
			if (w == 0 || h == 0) return 0;
			if (field > 0) putchar('\n');
			printf("Field #%d:\n", ++field);

			mines = (int**) calloc(w, sizeof(int*));
			if (mines == NULL) exit(1);
			for(int i = 0; i < w; ++i){
				mines[i] = (int*) calloc(h, sizeof(int));
				if (mines[i] == NULL) exit(1);
			}

			getchar();
			for(int x = 0; x < w; ++x){
				for(int y = 0; y < h; ++y){
					ch=getchar();	
					if(ch == '*') adj_inc(x,y);
				}
				getchar();
			}	

			for (int i = 0; i < w; ++i){
				for (int j =0; j < h; ++j){
					putchar(((mines[i][j] < 0) ? '*' : (char)mines[i][j]+48));
				}
				putchar('\n');
			}	
			for(int i = 0; i < w; ++i) free(mines[i]);
			free(mines);
	}
}
