/*
Autor:  Arkadia Kowalczyk
Grupa:  ŒR/NP 14:15
Temat:  Laboratorium 3
Data:   25 listopada 2020 r.
*/
 
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstdlib>

#define ROZMIAR 10

float Tab[ROZMIAR];

void zad1();
void Wypisz_tab();
void Wypisz_kom();
void zad2();
void zad3();

int main()
{
	int zad, n=1;
	
	printf("Autor: Arkadia Kowalczyk (SR/NP 14:15) \n\n");
	
	while(n){
	printf("\nKtore zadanie chcesz zobaczyc: (wpisz \"1\" \"2\" lub \"3\") ");
	scanf("%d", &zad);
	
	if(zad==1) zad1();  
	if(zad==2) zad2();
	if(zad==3) zad3();
	
	Wypisz_tab(); Wypisz_kom();

	printf("\nCzy chcesz zobaczyc cos jeszcze? (wpisz 1 jesli tak a 0 jesli nie) ");
	scanf("%d",&n);
	}
	
	return 0;
}

void zad1(){
	//wczytanie elementów tablicy z klawiatury
	
	for(int i=0; i<ROZMIAR; i++){
		printf("Tab[%d]: ", i);
		scanf("%f", &Tab[i]);
	}
	return;	
}

void Wypisz_tab(){
	//wypisz elementy tablicy
	
	printf("\n Oto twoja tablica: \n Tab = [  ");
	for(int i=0; i<ROZMIAR; i++) printf("%.1f  ", Tab[i]);
	printf("]\n");
}
void Wypisz_kom(){
	//wypisz komunikaty
	int dod=0, uje=0, ros=1, mal=1; //dodatnie ujemne rosn¹co malej¹co
	float sud=0, suu=0, sr=0; //suma dodatnia, suma ujemna, srednia
	
	for(int i=0; i<ROZMIAR; i++){
		
		if(Tab[i]>0){
			dod++;
			sud+=Tab[i];
		}
		//nie else bo zero nie jest ani dodatnie ani ujemne
		if(Tab[i]<0){
			uje++;
			suu+=Tab[i];
		}
		
		if(i+1<ROZMIAR){
			if(Tab[i]<Tab[i+1]) mal=0;
			if(Tab[i]>Tab[i+1]) ros=0;
		}
	}
	
	if(dod){
		sr=sud/dod;
		printf("\nJest %d liczb dodatnich. Ich suma to: %.1f a srednia to: %.1f", dod, sud, sr);
	}else printf("\nNie ma liczb dodatnich");
	
	if(uje){
		sr=suu/uje;
		printf("\nJest %d liczb ujemnych. Ich suma to: %.1f a srednia to: %.1f", uje, suu, sr);
	}else printf("\nNie ma liczb ujemnych");
	
	if(ros) printf("\nLiczby sa uporzadkowane rosnaco");
	if(mal) printf("\nLiczby sa uporzadkowane malejaco");

}

void zad2(){
	//wype³nij tablice losowymi liczbami
	
	srand(time(NULL));
	
	float mini, maxi;
	printf ("\nPodaj min: "); scanf("%f", &mini);
	printf ("\nPodaj max: "); scanf("%f", &maxi);
	
	for(int i=0; i<ROZMIAR; i++) Tab[i]= mini + (maxi-mini)*rand()/((double)RAND_MAX);
	
}

void zad3(){
 	//uporz¹dkuj elementy tablicy rosn¹co
 	
 	float p;
 	for(int i=0; i<ROZMIAR-1;i++){
		 for(int j=i+1; j<ROZMIAR; j++){
		 	
			 if(Tab[i]>Tab[j]){
				 p=Tab[i];
				 Tab[i]=Tab[j];
				 Tab[j]=p;
			 }
			 
		 }	 
	}	
}
