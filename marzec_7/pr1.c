#include <stdio.h>

float funkcja(float a, float b, float c, float d, int wybor){
	
	if(wybor == 1){
		if (a >= b && a >= c && a >= d){
			return a;
			
		}
		if (b >= c && b >= a && b >= d){
			return b;
			
		}
		if (c >= a && c >= b && c >= d){
			return c;
			
		}
		if (d >= b && d >= c && d >= a){
			return d;
			
		}
	}
	if(wybor == -1){
		if (a <= b && a <= c && a <= d){
			return a;
			
		}
		if (b <= c && b <= a && b <= d){
			return b;
			
		}
		if (c <= a && c <= b && c <= d){
			return c;
			
		}
		if (d <= b && d <= c && d <= a){
			return d;
			
		}
	}
	if (wybor == 0){
		return (a+b+c+d)/4;
	
	}
	return 0;
}



int main(void){
	
	float a;
	float b;
	float c;
	float d;
	int wybor;
	float wartosc;
	scanf("%f %f %f %f %d",&a,&b,&c,&d,&wybor);
	wartosc = funkcja(a,b,c,d,wybor);
	printf("%f",wartosc);
	return 0;
}