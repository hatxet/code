#define putchar(c) putc(c, stdout)

const char *string = "The 1500'th ugly number is 859963392.";
int i = 0;
int main(){ i=0; while(string[i] != '\0') putchar(string[i++]); putchar('\n'); return 0;}
