/*
Autor:  Arkadia Kowalczyk
Grupa:  ŒR/NP 14:15
Temat:  Laboratorium 4
Data:   8 grudnia 2020 r.
*/

#include <stdio.h>

void Etykietka();

/*
Wypisuje imie, nazwisko i reszte
*/


float LiczW(float a1, float a2, float b1, float b2);

/*
Liczy wyznacznik
parametry: a1 a2 b1 b2
zwraca: wyznacznik W=a1*b2-a2*b1
*/


int LiczU(float A1, float B1, float C1,
		  float A2, float B2, float C2,
		  float &x, float &y);

/*
Liczy uk³ad
Parametry: A1 B1 C1 - pierwsze równanie
	       A2 B2 C2 - drugie rownanie
           x, y - rozwiazanie ukladu
Przekazuje do LiczW (A1 A2 B1 B2)(C1 C2 B1 B2)(A1 A2 C1 C2)
Zwraca: N - liczba rozwi¹zan
*/


void WczytajR(float &A, float &B, float &C);
/*
wczytuje rownanie
parametry: A B C - wspó³czynniki opisujace rownanie
*/


void WypiszR(int N, float x, float y);
/*
wypisz rozwiazanie
parametry: N - liczba rozwiazan
		   x, y - rozwiazania
*/

void CzyKolejne(int &wykonaj){
	printf("\n\nCzy chcesz obliczyc kolejne rownanie? 1 - tak; 0 - nie; ");
	scanf("%d", &wykonaj);
}


int main()
{

	float a1, b1, c1;//deklaracja zmiennych
	float a2, b2, c2;
	float X, Y;//rozwiazania
	int N, wykonaj = 1;


	Etykietka();
	while(wykonaj)
	{
		wykonaj = 0;
		WczytajR(a1, b1, c1);
		WczytajR(a2, b2, c2);

		N = LiczU(a1, b1, c1, a2, b2, c2, X, Y);

		WypiszR(N, X, Y);
		CzyKolejne(wykonaj);
	}


	return 0;
}

void Etykietka()
{
	printf("Autor: Arkadia Kowalczyk (SR/NP 14:15) \n");
}

void WczytajR(float &A, float &B, float &C)
{

	printf("\nPodaj parametry rownania:\nA= ");
	scanf("%f", &A); //adres A
	printf("B= ");
	scanf("%f", &B); //adres B
	printf("C= ");
	scanf("%f", &C); //adres C
}

int LiczU(float A1, float B1, float C1,
		  float A2, float B2, float C2,
		  float &x, float &y)
{
	//1. oblicz wyznaczniki
	float W, Wx, Wy;
	int N;

	W = LiczW(A1, A2, B1, B2);
	Wx = LiczW(C1, C2, B1, B2);
	Wy = LiczW(A1, A2, C1, C2);

	//2. znajdŸ liczbe rozwiazan
	if(W)
	{
		N = 1;

		//3. znajdz rozwiazania
		x = Wx / W;
		y = Wy / W;
	}
	else
	{
		if(!Wx && !Wy) N = 2;
		else N = 0;
	}

	//4. przekaz liczbe rozwiazan
	return N;
}

float LiczW(float a1, float a2, float b1, float b2)
{

	float W;
	W = (a1 * b2) - (a2 * b1);
	return W;

}

void WypiszR(int N, float x, float y)
{
	if(!N)
	{
		printf("\nBrak rozwiazan");
		return;
	}
	if(N == 2)
	{
		printf("\nNieskonczenie wiele rozwiazan");
		return;
	}
	if(N == 1)
	{
		printf("\nX = %f Y = %f", x, y);
		return;
	}
	printf("\n wystapil blad: nieprawidlowa liczba rozwiazan");
}



