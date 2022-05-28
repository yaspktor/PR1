#include <stdio.h>

enum znaki{SLASH, BACKSLASH, ASTERISK, DOT};

void fun(int n, int m, enum znaki znakii){
	char znak;
	int i = 0;
	int j = 0;
	switch(znakii)
	{
		case SLASH:
			znak = '\\';
			break;
		case BACKSLASH:
			znak = '/';
			break;
		case ASTERISK:
			znak = '*';
			break;
		case DOT:
			znak = '.';
			break;
			
		
	}

	
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

int main(int args, char* argv[])
{
	fun(4, 10, SLASH);
	return 0;
}
