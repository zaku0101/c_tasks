/*
Autor:  Arkadia Kowalczyk
Grupa:  ŒR/NP 14:15
Temat:  Laboratorium 2
Data:   13 listopada 2020 r.
*/
 
#include <cstdio>
#include <cmath>

void zad1();
void zad2();
void zad3();
void zad4();

int main()
{
	int zad, n=1;
	
	printf("Autor: Arkadia Kowalczyk (SR/NP 14:15) \n\n");
	
	while(n){
	printf("\nKtore zadanie chcesz zobaczyc: (wpisz \"1\" \"2\" \"3\" lub \"4\") ");
	scanf("%d", &zad);
	
	if(zad==1) zad1();
	if(zad==2) zad2();
	if(zad==3) zad3();
	if(zad==4) zad4();
	
	printf("\nCzy chcesz zobaczyc cos jeszcze? (wpisz 1 jesli tak a 0 jesli nie) ");
	scanf("%d",&n);
	}
	
	return 0;
}

void zad1(){
	//tabliczka mno¿enia
	
	int w, k; //wiersze, kolumny
	printf("\nPodaj liczbe wierszy oraz kolumn.\nWiersze: ");
	scanf("%d", &w);
	printf("Kolumny: ");
	scanf("%d", &k);
	
	for(int i=4;i>=0;i--) printf(" ");		 
	printf("| ");
    for(int i=1; i<=k; i++)printf("%4d",i);
    printf("\n");
    
    int ik=0; //ile kresek
	ik=(4*k)+8;
	for(;ik;ik--) printf("-");

	for(int i=1;i<=w;i++){
		printf("\n%4d | ", i);
		for(int j=1;j<=k;j++){
			printf("%4d", i*j);
		}
	}
}
void zad2(){
	//suma cyfr du¿ej liczby
	unsigned long liczba;
	int suma=0;
	printf("\nPodaj duza liczbe: ");
	scanf("%ld", &liczba);
	
	while(liczba){
		suma+=liczba%10;
		liczba/=10;
	}
	
	printf("Suma to: %d",suma);
}
void zad3(){
 	//nwd i nww bez rekurencji
 	int a, b;
 	printf("Podaj dwie liczby: ");
	scanf("%d %d", &a, &b);
    
	if(a>b){
		a+=b;
		b=a-b;
		a-=b;
	}
	
	//nwd
	int nwd;
	for(nwd=a;b%nwd;nwd--){
		while(a%nwd) nwd--;
		
		if(b%nwd){}else nwd++;
	}
	printf("twoje nwd: %d\n",nwd);
	
	//nww
	a/=nwd;
	int nww=a*b;

	printf("twoje nww: %d",nww);
}
void zad4(){
	
	//Suma 1
	
	int m=1; //m- mianownik
	double esp, S1=0, w=1.0/m ; // esp - dokladnosc, S1 - suma, w - wyraz szeregu
	printf("\nPodaj esp dla S1: ");
	scanf("%lf", &esp);
		
	
	for(float x=-1; esp<=fabs(w*4); x*=-1){
		S1+=w;
		m+=2;
		w=x/m;
	}
	
	S1*=4;
	
	printf("\nO to S1: %lf", S1);
	
	
	//Suma 2
	
	float S2=0;
	m=1; w=1/m;
	
	printf("\nPodaj esp dla S2: ");
	scanf("%lf", &esp);	
	
	for(int i=1; esp<=w; i++){
		S2+=w;
		m*=i;
		w=1.0/m;
	}
	
	printf("\nO to S2: %f", S2);
}
