#include <stdio.h>

void pierwsze(unsigned int m, unsigned int n){
    int i;
    int j;
    int isp = 1;
    for(i = m; i < n; i++){
       
        isp = 1;
        if (i <= 1){
            isp = 0;
        }
        else if (i % 2 == 0 && i > 2) isp = 0;
        else{
            for(j = 3; j < i/2; j+=2){
           
                if (i % j == 0){
                    isp = 0;
                }
            }
        }
        
        if (isp == 1){
            printf("%d ", i);
        } 
    }


}

int main(void){

pierwsze(3 ,23);

return 0;
}