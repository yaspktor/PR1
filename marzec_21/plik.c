#include <stdio.h>
#include <stdlib.h>



int main(int argc, char *argv[]){
	int i;
	/*
	printf("Wszystkich argumentow jest %d\n",argc);
	for(i = 0; i < argc; i++){
		printf("%s \n", argv[i]);
	}*/
	printf("Wszystkich argumentow jest %d\n",argc);
	if(argc !=3){
		printf("Prawidlowe wywolanie %s int int\n",argv[0]);
		return -1;
	}
	printf("%s + %s = %d",argv[1],argv[2],atoi(argv[1])+atoi(+argv[2]));
	return 0;
}