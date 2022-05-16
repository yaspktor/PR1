#include <stdio.h>
#include <stdlib.h>



int main(int argc, char *argv[]){
	
	
	printf("Wszystkich argumentow jest %d\n",argc);
	if(argc != 4){
		printf("Prawidlowe wywolanie %s float dzialanie float \n",argv[0]);
		return -1;
	}
	
	if(argv[2][0] == '+'){
		
		printf("%s + %s = %f\n",argv[1],argv[3],atof(argv[1])+atof(argv[3]));
		
	}
	else if(*argv[2] == 'x'){
	
		printf("%s x %s = %f\n",argv[1],argv[3],atof(argv[1])*atof(argv[3]));
	}
	else if(*argv[2] == '/'){
		if(*argv[3] == '0'){
			printf("blad nie mozna dzielic przez 0 \n");
		}
	
	}
	else{
		printf("brak dzialania \n");
	}
	
	return 0;
}