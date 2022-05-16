#include <stdio.h>
#include <stdlib.h>


int main(void)
{
	int n,m,i,j,x,y,z,c,counter;
	int ** wsk;

	scanf("%d",&n);
    m = n;
	wsk = (int **) malloc(n * sizeof(int*));
	for(i=0;i<m;i++){
        *(wsk + i) = (int *) malloc(m * sizeof(int));
    } 

    for(z=0;z<m;z++){ 
        for(c=0;c<m;c++){ 
            printf("%d\n",m);
            printf("%d,  %d: \n",z,c);
            scanf("%d",*(*(wsk+z)+c));
       
    }
    }
    printf("\n");
    
    counter = 0;
    for(x=0;x<n;x++){   
        for(y=0;y<m;y++){
            
                printf("%d",*(*(wsk+x)+y));
            }
         printf("\n");

        }
       
    

	printf("\n");
	printf("%g", *(*(wsk+3)+2) );
	for(i=0;i<n;i++) free( *(wsk + i));
	free(wsk);
	return 0;
}