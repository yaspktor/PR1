#include <stdio.h>
#include <stdlib.h>


void swap(int* x, int* y){
	int t = *x;
    *x = *y;
    *y = t;

}



int main(void){
	int x = 1;
	int y = 2;
	swap(&x,&y);
	printf("%d, %d\n",x,y);
	return 0;
}