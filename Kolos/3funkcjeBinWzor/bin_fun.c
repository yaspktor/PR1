#include <stdio.h>

int rek(int l){

    if (l == 0)
    {
    	return 0;
    }
    if (l % 2 == 0)
    {
    	rek(l/2);
    	printf("%d", l % 2);
    }
    if (l % 2 == 1)
    {
    	rek(l/2);
    	printf("%d", l % 2);
    }
    return 0;
}


int main(void){
    
    printf("\n%d\n", rek(19));
    return 0;
}
