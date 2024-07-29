
#include <cstdio>
#include <cmath>

void zad1(){
	
	int a,b,c;
	float delta, x1, x2;
	
	printf("\nPodaj trzy liczby ");
	scanf("%d%d%d", &a, &b, &c); //wczytaj
	
	if(a){
		
		delta=b*b-4*a*c;
		if(delta<0){
		   	printf("brak pierwiastkow w zbiorze liczb rzeczywistych");

	    }else{
			if(delta>0){
					x1=(-b-sqrt(delta))/(2*a);
			 		x2=(-b+sqrt(delta))/(2*a);
		   	}
		 	else{   
			 		x1=-b/(2*a);
			 		x2=x1;
   			}
		   	printf("pierwiastki podanego rownania to: %f",x1);
		   	if(x1!=x2) printf(" i %f",x2);
		}
	}
	else printf("To nie jest rownanie kwadratowe");
	
}

bool czy_przestepny(int y){
	
	if(y%100){
		//nie dzieli si� przez 100
		if(y%4) return 0; //nie dzieli si� przez 4, np 2005
	}
	else{ //dzieli sie przez 100
		if(y%400) return 0; //nie dzieli sie przez 400, np 1300
	}
	//nie dzieli sie przez 100 a dzieli sie przez 4 np 2004
	//dzieli sie przez 400 np 2000 albo 1600
	return 1;
}

void zad2(){
	int d, m, y, w=0; //day month year wynik
	
	printf("\nPodaj date w formacie dzien miesiac rok. Poszczegolne liczby oddziel spacja. ");
	scanf("%d%d%d",&d,&m,&y);
	
	printf("\nTwoja data to: %d.%d.%dr.",d,m,y);
	if(d<=0) m=0;
	if( m<1 || m>12){
		printf("\nTo nie jest poprawna data.\n");
		return;
	}
	if(m%2){ //je�li nie parzyste
		if(m<8){ //1 3 5 7
dlugie:
			if(d<=31 && d>=1) w=1;	
		}
		else{ //9 11
krutkie:			
		 if(d<=30 && d>=1) w=1;	
	 	} 	
	}
	else{ //je�li parzyste
		if(m!=2){			
			if(m<8) goto krutkie;
			else goto dlugie;
		}
		else{//2
			if(czy_przestepny(y)) {if(d<=29 && d>=1) w=1;}
			else if(d<=28 && d>=1) w=1;
		}
	}
	if(w) printf("\nTo jest dobra data\n");
	else printf("\nTo nie jest dobra data\n");
}

void zad3(){
 
    int w; //ile wierszy
    float r,R; // maly promien, duzy pRomien
    
    float obw,pp,d; //obwod, pole powierzchni, delta promieni
    
    printf("\nPodaj najmniejszy promien: ");
    scanf("%f", &r);
    
    if(r<0){
		printf("\nPromien nie moze byc ujemny");
		return;
	}
    
    printf("\nPodaj najwiekszy promien: ");
    scanf("%f", &R);
    
    if(R<r){
		printf("\nNajwiekszy promien nie moze byc mniejszy od najmniejszego. \nZamieniam najwiekszy z najmniejszym...\n");
		
		r+=R;
		R=r-R;
		r-=R;
		
		if(r<0){
			printf("\nPromien nie moze byc ujemny");
		   	return;
	   	}
	}
    
    printf("\nPodaj liczbe wierszy: ");
    scanf("%d", &w);
    
    if(w<0){
		printf("\nLiczba wierszy nie moze byc ujemna");
		return;
	}
    
    printf("\n\n");
    for(int i=41; i--;) printf("=");
    printf("\n| LP | promien | obwod kola | pole kola |");
	printf("\n");
    for(int i=41; i--;) printf("=");
    
    d=(R-r)/(w-1);

	for(int j=0; j++, w--;){
		if(j!=1) r+=d;
		
		obw=2*r*M_PI;
		pp=r*r*M_PI;
		
		printf("\n|%3d |%8.2f |%11.2f |%10.2f |",j,r,obw,pp);
	}
	
	printf("\n");
    for(int i=41; i--;) printf("=");
	
}

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
	
	printf("\nCzy chcesz zobaczyc cos jeszcze? (wpisz 1 jesli tak a 0 jesli nie) ");
	scanf("%d",&n);
	}
	
	return 0;
}
