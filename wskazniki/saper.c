#include <stdio.h>
#include <stdlib.h>



int main(void)
{
	int n,m,i,j,x,y,z,c,counter;
   
    char d[10];
	char ** wsk;

	scanf("%d %d",&n, &m);
	wsk = (char **) malloc(n * sizeof(char*));
	for(i=0;i<n;i++){
        *(wsk + i) = (char *) malloc(m * sizeof(char));
    } 
   // printf("1TEST\n");
    // for(i=0;i<n;i++){
    //      /*printf(" i1TEST ");*/
    //     for(j=0;j<m;j++){
    //         //scanf("%c",&d);

    //         *(*(wsk+i)+j) = '*';
    //         printf("j1TEST %c",*(*(wsk+i)+j));

    //     }printf("\n");
    // }
    for(i=0;i<n;i++){
          
         
        scanf("%s",(*(wsk+i)));
       
    }
    printf("\n");
    
    //printf("TEST\n");
    counter = 0;
    for(x=0;x<n;x++){
        
        for(y=0;y<m;y++){
            //printf("wsp x: %d y: %d\n",x,y);
            if(*(*(wsk+x)+y) != '*' ){
                //printf("weszli \n");
                for(z=x-1;z<=x+1;z++){
                
                    for(c=y-1;c<=y+1;c++){
                        //printf("  wsp z: %d c: %d\n",z,c);
                        if(z == x && c == y) continue;
                        

                        if(z < 0 || z >= n || c < 0 || c >= m)
                        continue;
                       // printf("     wsp z: %d c: %d\n",z,c);
                        if( *(*(wsk+z)+c) == '*'){
                            //printf("bomba\n");
                            //printf("wsp z: %d c: %d\n",z,c);
                            //printf("test %c\n",*(*(wsk+z)+c));
                            counter++;
                           // printf("strzal %d",counter);
                            
                           // printf("pole %c",pole);

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
	printf("%g", *(*(wsk+3)+2) );
	for(i=0;i<n;i++) free( *(wsk + i));
	free(wsk);
	return 0;
}