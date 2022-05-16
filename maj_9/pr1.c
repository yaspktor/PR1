#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student{ 
	char imie[50];
	char nazwisko[50];
	int punkty;
	
}Student;


void swap (Student *student1, Student *student2){
	Student temp;
	memcpy(&temp, student1, sizeof(Student));
	memcpy(student1, student2, sizeof(Student));
	memcpy(student2, &temp, sizeof(Student));
	
	
}

void sort(Student *tab, int n){
	int i;
	int j;
	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			if(tab[j].punkty <tab[j+1].punkty){
				swap(tab+j,tab+j+1);
			}
		}
	}

}


int main(void){
	
	int n;
	int i;
	Student *tablica;
	scanf("%d",&n);
	tablica = (Student *) malloc (sizeof (Student)*n);
	for(i = 0; i < n; i++){
		scanf("%s %s %d", (tablica+i)->imie, (tablica+i)->nazwisko, &(tablica+i)->punkty);
	}
	
	for(i = 0; i < n; i++){
		printf("%s %s %d\n", (tablica+i)->imie, (tablica+i)->nazwisko, (tablica+i)->punkty);
	}
	swap(tablica,tablica+1);
	sort(tablica,n);
	for(i = 0; i < n; i++){
		printf("%s %s %d\n", (tablica+i)->imie, (tablica+i)->nazwisko, (tablica+i)->punkty);
	}
	
	free(tablica);
	
	
	
	
	
		
	
	
	
	
	

	return 0;
}