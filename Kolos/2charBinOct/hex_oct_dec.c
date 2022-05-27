#include <stdio.h>

int main(void)
{
	int num;
	int num2;
	int num3;
	
	scanf("%i", &num);
	scanf("%i", &num2);
	scanf("%i", &num3);
	printf("0%o %d 0x%x \n", num, num, num);
	printf("0%o %d 0x%x \n", num2, num2, num2);
	printf("0%o %d 0x%x \n", num3, num3, num3);
	return 0;
}
