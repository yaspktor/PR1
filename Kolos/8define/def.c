#include <stdio.h>
#define SWAP(t, x, y) {t temp = x; x = y; y = temp; }

int main(int args, char* argv[])

{

	float x = 1.2;
	float y = 2.4;
	printf("%f %f\n",x,y);
	SWAP(float,x,y);
	printf("%f %f\n",x,y);
	SWAP(int,x,y);
	printf("%f %f\n",x,y);
  	return 0;
}
	

