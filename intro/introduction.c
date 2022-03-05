#include <stdio.h>
#include <math.h>

int main(void){




    /*Zadanie 1*/

    /*
    int i;
    printf("Podaj liczbę naturalna: ");
    scanf("%d",&i);
    printf("Podana liczba to: %d\n",i);

    if(i % 2 == 0){
        printf("Podana liczba %d jest podzielna przez 2\n",i);
    }
    if(i % 3 == 0){
        printf("Podana liczba %d jest podzielna przez 3\n",i);
    }
    if(i % 5 == 0){
        printf("Podana liczba %d jest podzielna przez 5\n",i);
    }
    if(i % 7 == 0){
        printf("Podana liczba %d jest podzielna przez 7\n",i);
    }
    */

    /*Zadanie 2*/

    /*
    int rok;
    printf("Podaj rok: ");
    scanf("%d",&rok);
    printf("Podany rok to: %d\n",rok);
    if(rok % 4 == 0){
        printf("Rok %d jest przestepny.",rok);
    }
    else{
        printf("Rok %d nie jest przestepny.\n",rok);
    }
    */


    /*Zadanie 3*/

    /*
    int liczba;
    int najwieksza;
    printf("Podaj liczbe calkowita: ");
    scanf("%d",&liczba);
    najwieksza = liczba;
    if(liczba<0){
        printf("Najwieksza liczba %d\n",liczba);
    }
    else{
        while(liczba>0){
            printf("Podaj liczbe calkowita: ");
            scanf("%d",&liczba);
            if(liczba>najwieksza){
                najwieksza = liczba;
            }

        }
        printf("Najwieksza liczba %d\n",najwieksza);
    }

    */

   /* Zadanie 4 */
   /*
    int n;
    float wynik = 0;
    float liczba;
    float wykladnik = 1/2;
    printf("Ile liczb zamierzasz wprowadzic: \n");
    scanf("%d",&n);
    while(n>0){
        printf("Podaj kolejna liczbe\n");
        scanf("%f",&liczba);
        wynik = wynik + pow(liczba,2);
        printf("wynik: %f\n",wynik);
        n = n-1;
    }
    wynik = sqrt(wynik);
    printf("Wynik: %f",wynik);

*/

    /* zadanie 5 */

    

    int rok;
    int miesiac;
    int dzien;
    
    char napis [10];
    printf("Podaj date w formacie xx xx xxxx lub xx/xx/xxxx lub xx.xxx.xxxx\n");
    scanf("%s",&napis);
    printf("%s\n",napis);
    rok = napis[6]-'0';
    
    printf("rok: %d\n",rok); 
    

    /*char znak;*/

    /*
    printf("Podaj pierwszy znak ");
    scanf("%c",&znak);
    printf("%c\n",znak);

    printf("Podaj drugi znak ");
    scanf("%c",&znak);
    printf("%c\n",znak);
    */

    /* rodzaj danych oraz adres gdzie ma byc (nazwa tablicy jest wskaznikiem na adres)*/
    /*s dziala tylko do pustego znaku*/


    /*int n = 27; */

    /*printf("%s", tab);*/




    return 0;
}