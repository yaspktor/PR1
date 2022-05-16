#include <stdio.h>
#include <stdlib.h>

enum znaki{SLASH, BACKSLASH, ASTERISK, DOT};
void fun(char znak, int n, int m){
	int i = 0;
	int j = 0;
	for(i = 0; i<m; i++){
	 	for(j = 0; j<n; j++){
			if(i == 0 || i == m-1){
				printf("%c",znak);
			}
			else{
				if(j == 0 || j == n-1){
				printf("%c",znak);
				}
				else printf(" ");
			}			
		}
		 printf("\n");
	 }	
}
void drukuj(int n, int m, enum znaki znak){
   switch(znak)
   {
   case ASTERISK:
     fun('*',n,m);
	break;
	case SLASH:
     fun('/',n,m);
	break;
	case BACKSLASH:
     fun('\\',n,m);
	break;
	case DOT:
     fun('.',n,m);
	break;
	
}	
}

int main(){
	
	drukuj(10, 4, BACKSLASH);
	drukuj(10, 4, SLASH);
	drukuj(10, 4, ASTERISK);
	drukuj(10, 4, DOT);

	return 0;
}