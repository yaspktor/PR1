#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	int n,m,i,x,y,z,c,counter;
	char ** wsk;

	scanf("%d %d",&n, &m);
	wsk = (char **) malloc(n * sizeof(char*));
	for(i=0;i<n;i++){
        *(wsk + i) = (char *) malloc(m * sizeof(char));
    } 

    for(i=0;i<n;i++){ 
        scanf("%s",(*(wsk+i)));
       
    }
    printf("\n");
    
    counter = 0;
    for(x=0;x<n;x++){   
        for(y=0;y<m;y++){
            
            if(*(*(wsk+x)+y) != '*' ){ 
                for(z=x-1;z<=x+1;z++){
                    for(c=y-1;c<=y+1;c++){
                  
                        if(z == x && c == y) continue;
                        if(z < 0 || z >= n || c < 0 || c >= m)
                        continue;
               
                        if( *(*(wsk+z)+c) == '*'){
                            
                            counter++;
                        }
                    }
                }
                
                printf("%c",counter+'0');
                counter = 0;

            }else{
                printf("%c",*(*(wsk+x)+y));
            }
        
        }
        printf("\n");

    }

	printf("\n");
	printf("%d", *(*(wsk+3)+2) );
	for(i=0;i<n;i++) free( *(wsk + i));
	free(wsk);
	return 0;
}