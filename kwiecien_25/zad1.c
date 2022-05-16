
#include<stdio.h> 
#include"naglowek.h" 
#define SUMA(a,b) a+b;
#define SWAP(t,x,y)  {t temp=x; x=y; y=temp;}
int main(){
	float x = 1.2;
	float y = 2.4;
	printf("%f %f\n",x,y);
	SWAP(float,x,y);
	printf("%f %f\n",x,y);
	SWAP(int,x,y);
	printf("%f %f\n",x,y);
  return 0;
}