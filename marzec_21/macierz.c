#include <stdio.h>
#include <stdlib.h>

int matrix(int **m, int **n){
	
	
}

int main(void)
{
	int n,m,i,x,y,counter;
	int ** wsk;
	

	scanf("%d %d",&n, &m);
	wsk = (int **) malloc(n * sizeof(int*));
	for(i=0;i<n;i++){
        *(wsk + i) = (int *) malloc(m * sizeof(int));
    } 

    for(i=0;i<n;i++){ 
        scanf("%d",(*(wsk+i)));
       
    }
    printf("\n");
    
    counter = 0;
    for(x=0;x<n;x++){   
        for(y=0;y<m;y++){
            printf("\n");
        }
        printf("\n");

    }

	printf("\n");
	printf("%d", *(*(wsk+3)+2) );
	for(i=0;i<n;i++) free( *(wsk + i));
	free(wsk);
	return 0;
}