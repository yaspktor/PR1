#include <stdio.h>
#include <math.h>

int main(void){
int n;
int m;
int i;
int j;
int druk;
printf("Podaj 2 liczby naturalne\n");
scanf("%d",&n);
scanf("%d",&m);
printf("Podane liczby: %d %d\n",n,m);

for (i = n; i>0; i--){
	for (j = m; j>0; j--){
		druk = i*j;
		if(j != 1) printf("%d\t",druk);	
		else printf("%d\t",druk);	
	}
	printf("\n");

}


return 0;
}