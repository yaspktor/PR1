#include <stdio.h>
#include <stdlib.h>

int fib(int n) {
   if(n == 0){
      return 0;
   } else if(n == 1) {
      return 1;
   } else {
      return (fib(n-1) + fib(n-2));
   }
}


int main(int argc, char *argv[]){
	
	int liczba;
	int argument = atoi(argv[1]);
	/*printf("a %d\n",argument);*/
	liczba = fib(argument);
	printf("%s wyraz ciagu wynosi %d\n",argv[1],liczba);
	
	return 0;
}