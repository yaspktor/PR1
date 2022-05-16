#include <stdio.h>
#include <math.h>

int main(void){
   char napis[100];
   unsigned int liczba;
   printf("Podaj liczbe w wybranym systemie: \n");
   scanf("%s", napis);
   printf("Podany napis: %s\n", napis);

   if(napis[0]=='0' && napis[1]!='x'){
	sscanf(napis, "%o", &liczba);
	printf("0%o %d 0x%x\n", liczba,liczba,liczba);
		
   }
   if(napis[0]=='0' && napis[1]=='x'){
	sscanf(napis, "%x", &liczba);
	printf("0%o %d 0x%x\n", liczba,liczba,liczba);
		
   }
   else{
	sscanf(napis, "%u", &liczba);
	printf("0%o %d 0x%x\n", liczba,liczba,liczba);
   }

return 0;
}