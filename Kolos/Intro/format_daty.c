#include <stdio.h>

int main(void)
{
	int rok;
	int miesiac;
	int dzien;
	char input[30];
	printf("Podaj date: ");
	scanf("%[^\n]", input);
	if (sscanf(input, "%4d/%2d/%2d", &rok, &miesiac, &dzien) == 3){
		printf("ok\n");
		printf("%d - %d - %d\n", dzien, miesiac, rok);
	}
	else if (sscanf(input, "%4d.%2d.%2d\n", &rok, &miesiac, &dzien) == 3)
	{
		printf("ok\n");
		printf( "%d - %d - %d\n", dzien, miesiac, rok);
	}
	else if (sscanf(input, "%4d %2d %2d\n", &rok, &miesiac, &dzien) == 3)
	{
		printf("ok\n");
		printf("%d - %d - %d\n", dzien, miesiac, rok);
	}
	else
	{
		printf("Nie ok\n");
	}
	return 0;
}
