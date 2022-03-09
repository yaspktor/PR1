#include <stdio.h>

int rek(int l){
    int counter = 0;
    if ( l <= 0){
        printf("\n");
        return 0;
    }
    else{
        if( l%2 == 1 ){
            printf("%d", l % 2);
            return rek(l/2) +1;
        }
        else{
            printf("%d", l % 2);
            return rek(l/2);
        }
    }
}


int main(void){
    
    printf("%d\n", rek(19));
}
