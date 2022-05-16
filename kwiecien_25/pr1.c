/* 
Dyrektywy preprocesora.
Proszę zapoznać się z tym przykładem, dokładnie prześledzić kod wraz z komentarzami.
Warto podejrzeć, jak wygląda kod po kompilacji preprocesorem, w tym celu użyj flagi -E w czasie kompilacji i podejrzyj plik wynikowy (swojego kodu należy szukać na końcu pliku).*/

#include<stdio.h> /*#include jest dyrektywą preprocesora, którą powinniśmy już znać. Pozwala na dołączenie zawrtości pliku. Warto zwrócić uwagę na różnicę pomiędzy użytymi nawiasami. Używając <...> odwołujemy się do plików, które znajdują się w domyślnej ścieżce*/
#include"naglowek.h" /* użycie cudzysłowu ""  pozwala nam załączyć plik znajdujący się w katalogu naszego pliku. W tym przypadku możemy użyć również ścieżki bezwzględnej*/

#define SUMA(a,b) a+b

int main(){
   printf("Przyklad uzycia dyrektyw preprocesora, koniecznie zapoznaj sie z komentarzami w kodzie!\n");
    #ifndef PI /* jeśli Pi nie jest zdefiniowane, na przykład nie mamy pliku naglowek.h, to wykona się poniższa dyrektywa*/
      #define PI 3.14 /*definiujemy stałą PI, jeśli nie była zdefiniowana*/	
   #else
      printf("Stala PI jest juz zdefiniowana\n");
   #endif
   printf("Stala PI:%f\n",PI); 
   #undef PI
   #define PI 3.14159
   printf("Zmienilem dokładność stałej PI\n");
   printf("Stala PI:%f\n",PI);

   printf("Wyswietlam SUMA(2,3)*2: %d\n",SUMA(2,3)*2); /*korzystamy z makra SUMA. Pamiętaj, że dyrektywy są używane, na etapie kompilacji preprocesora. To znaczy, że w miejsce SUMA(2,3) zostanie wstawione 2+3, jednak nie obliczony. Obliczenia wykonają się w momencie uruchomienia pogramu (będziemy mieli 2+3*2=2+6=8 kolejność działań!)*/
  printf("Uzywam LEPSZA_SUMA(2,3)*2:%d\n", LEPSZA_SUMA(2,3)*2); /* makro LEPSZA_SUMA jest zdefiniowane w naglowek.h, dodanie nawiasów zmienia wartosc.*/
  printf("Uzywam LEPSZY_ILOCZYN(2+3,5):%d\n",LEPSZY_ILOCZYN(2+3,5)); /*makro LEPSZY_ILOCZYN jest zdefiniowane w naglowek.h, dodanie nawiasów tu nie pomaga.*/
  printf("Uzywam JESZCZE_LEPSZY_ILOCZYN(2+3,5):%d\n",JESZCZE_LEPSZY_ILOCZYN(2+3,5)); /*makro JESZCZE_LEPSZY_ILOCZYN jest zdefiniowane w naglowek.h. Prosze przemyslec te przyklady. Wazne, aby zapamietac, ze dyrektywy preprocesora są wykonywane na tym etapie kompilacji*/
  return 0;
}