#include <stdio.h>
#include <ctype.h>




int main(void){
   
   int i = 0;
   int j;
   char napis[160];
   int tab[9][2] = {{2,0},{3,0},{4,0},{5,0},{6,0},{7,0},{8,0},{9,0},{0,0}};
   char znak;
   
   int wartosc;
   printf("Podaj tresc sms\n");
   scanf("%159[^\n]",napis);
   
   
   while(napis[i]!='\0'){
   	znak = tolower(napis[i]);
   	wartosc = znak-'0'-48;
        
        if (znak== ' '){
        	tab[8][1]+=1;
        }
        if (wartosc > 0 && wartosc <= 3){
        	tab[0][1]+=1;
        }
        if (wartosc > 3 && wartosc <= 6){
        	tab[1][1]+=wartosc - 3;
        }
        if (wartosc > 6 && wartosc <= 9){
        	tab[2][1]+=wartosc - 6;
        }
        if (wartosc > 9 && wartosc <= 12){
        	tab[3][1]+=wartosc - 9;
        }
        if (wartosc > 12 && wartosc <= 15){
        	tab[4][1]+=wartosc - 12;
        }
        if (wartosc > 15 && wartosc <= 19){
        	tab[5][1]+=wartosc - 15;
        }
        if (wartosc > 19 && wartosc <= 22){
        	tab[6][1]+=wartosc - 19;
        }
        if (wartosc > 22 && wartosc <= 26){
        	tab[7][1]+=wartosc - 22;
        }
   	
   	i = i + 1;
   	
   }
   for(j = 0; j < 9; j++){
   	if(tab[j][1]>0){
   		printf("wartosc klawisza  [%d] wynosi %d \n",tab[j][0],tab[j][1]);
   	}
   	
   }
   
   
   return 0;
}