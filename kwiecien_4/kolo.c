#include <stdio.h>
#include <stdlib.h>
#include <math.h>
enum znaki{SLASH, BACKSLASH, ASTERISK, DOT};
struct punkt{
	float x;
	float y;
	};

struct kolo{
	float promien;
	struct punkt srodek;
	
	
	};



void fun(struct kolo elo){
	int i = 0;
	int j = 0;
	for( i= 0 ; i < 2*(elo.promien);i++){
		for( j= 0 ; j < 2*(elo.promien);i++){
			if(  sqrt(((i-elo.srodek.x)*(i-elo.srodek.x)) -  ((j-elo.srodek.y)*(j-elo.srodek.y))) ){
			printf("*");
			}
		}printf("\n");
	}
	
				
}


int main(void){
 	struct kolo elo = { 3, 3, 3};
	fun(elo);

	return 0;
}