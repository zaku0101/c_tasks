/*
Autor:  Arkadia Kowalczyk
Grupa:  ŒR/NP 14:15
Temat:  Laboratorium 4
Data:   29 grudnia 2020 r.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Etykietka();
//Wypisuje imie, nazwisko i reszte


void InitTab(char **&wsk); 
// Inicjalizuje Tablice wskaznikow

void PokazMenu();
// Pokazuje menu

void AddName(char *buf, char **&wsk, int &poz); 
// Dodawanie nowego imienia do tablicy dynamiczne.j

void RemoveName(int nr, char **&wsk, int &poz);
// Usuwanie imienia znajduj¹cego siê w tablicy na pozycji nr,
 
void RemoveThatName(char *buf, char **&wsk, int &poz); 
//Uusuwanie z tablicy imienia, wprowadzonego z klawiatury

void PrintAllNames(char **wsk); 
// drukowanie na ekranie wszystkich imion

void PrintNames(char &first_letter, char **wsk);
// drukowanie na ekranie imion rozpoczynaj¹cych wskazan¹ liter¹

void SortAlphabet(char **wsk); 
// sortowanie imion zawartych w tablicy wed³ug alfabetu

void SortLength(char **wsk); 
// sortowanie imion zawartych w tablicy wed³ug d³ugoœci


int main()
{
	char** wsk;
	char buf[81];
	int poz=0, wybor; //na ktorej pozycji jest 0
	
	Etykietka();
	InitTab(wsk); 
	PokazMenu();
	
	while(true)
	{
		printf("\nCo chcesz zrobic?\n(aby ponownie wyswietlic opcje wybierz '8')\n");
		scanf("%d", &wybor);
		getchar(); //usuwam enter z bufora
		
		switch(wybor)
		{
			case 1: AddName(buf, wsk, poz); 
				break;
			
			case 2:	RemoveName(-1, wsk, poz);
				break;
			
			case 3: RemoveThatName(buf, wsk, poz);
				break;
			
			case 4: PrintAllNames(wsk); 
				break;
			
			case 5: PrintNames(buf[0], wsk);
				break;
			
			case 6:	SortAlphabet(wsk); 
				break;
			
			case 7: SortLength(wsk); 
				break;
			
			case 8:	PokazMenu();
				break;
			
			case 9: return 0;
		}

	}
	
	


	return 0;
}

void Etykietka()
{
	printf("Autor: Arkadia Kowalczyk (SR/NP 14:15) \n");
}

void PokazMenu()
{
	printf("\nWitaj! O to co mozesz zrobic:\n");
	
	printf("\n1. Dodaj imie");
	printf("\n2. Usun imie z danej pozycji");
	printf("\n3. Usun wszystkie wystapienia konkretnego imienia");
	printf("\n4. Wydrukuj liste imion");
	printf("\n5. Wydrukuj imiona na konkretna litere");
	printf("\n6. Posortuj alfabetycznie");
	printf("\n7. Posortuj wedlug dlugosci");
	printf("\n8. Pokaz opcje jeszcze raz");
	printf("\n9. Zakoncz program");
}

void InitTab(char **&wsk)
{
	//zaalokuj pamiec o rozmiarze 1go wskaznika na char
	wsk=(char**)malloc(sizeof(char*));
	
	if (wsk) wsk[0]=0;
	else printf("nie mozna zainicjalizowac tablicy");
	
	return;
} 

void AddName(char *buf, char **&wsk, int &poz)
{
	char **tempWSK;
	
	//zwieksz tablice a nowy adres przypisz do tempWSK
	tempWSK=(char**)realloc(wsk, sizeof(char*)*(poz+2));
	
	//sprawdz czy udalo sie zwiekszyc tablice
	if(!tempWSK)
	{
		printf("Nie udalo sie zwiekszyc tablicy");
		return;
	}
	
	wsk=tempWSK;
	
	//interakcja z uzytkownikiem
	printf("\nJakie imie chcesz dodac: ");
	gets (buf);
	
	//dodaj imie do listy
	wsk[poz]=strdup(buf);
		
	//for(int i=0; wsk[poz][i]; i++) printf("%c",wsk[poz][i]);
	
	poz++;
	wsk[poz]=0;
	
	return;
	
} 

void RemoveName(int nr, char **&wsk, int &poz)
{
	char** temp;
	
	if(nr<0)
	{
		printf("\nZ ktorej pozycji chcesz usunac imie?");
		scanf("%d",&nr);
		getchar();
	}
	
	if(nr<0||nr>poz) 
	{
		printf("\nNieprawidlowa pozycja");
		return;
	}
	
	free(wsk[nr]);
	
	//przesun dane o oczko wyzej
	for (int i=nr; wsk[i]; i++) wsk[i]=wsk[i+1];
	
	temp=(char**)realloc(wsk,poz*sizeof(char*));

	if(!temp)
	{
		printf("\nNie udalo sie zmniejszyc tablicy");
		return;
	}
	
	wsk=temp;
	poz--;
	
	return;
	
}

void RemoveThatName(char *buf, char **&wsk, int &poz)
{
	printf("\nPodaj imie: ");
	gets(buf);
	
	for (int i=0; wsk[i]; i++)
	{
		if(!strcmp(wsk[i],buf)) RemoveName(i,wsk,poz);
	}
	
	printf("\nUsunieto imie\n");
	return;
}

void PrintAllNames(char **wsk)
{
	printf("\n");
	for (int i=0; wsk[i]; i++)
	{
	 	printf("%d. ",i);
		puts(wsk[i]);
	}
	
	return;
}

void PrintNames(char &first_letter, char **wsk)
{
	printf("Podaj litere: ");
	first_letter=getchar();
	getchar(); //usuwam enter z bufora
	
	printf("\n");
	for(int i=0; wsk[i]; i++)
	{
		if(wsk[i][0]==first_letter)
		{
			printf("%d. ",i);
		   	puts(wsk[i]);
		}
	}
	
	
	return;
}

void SortAlphabet(char **wsk)
{ 
	char* temp;
	for(int i=0, z; wsk[i+1]; i++)
	{
		if(strcmp(wsk[i],wsk[i+1])>0)
		{
			
			temp=wsk[i];
			wsk[i]=wsk[i+1];
			wsk[i+1]=temp;
			
			for(z=i; z && strcmp(wsk[z-1],wsk[z])>0;z--)
			{
				  temp=wsk[z];
				  wsk[z]=wsk[z-1];
				  wsk[z-1]=temp; 	
			}
		}
	}
	return;
}

void SortLength(char **wsk)
{
	char* temp;
	for(int i=0, z; wsk[i+1]; i++)
	{
		if(strlen(wsk[i])>strlen(wsk[i+1]))
		{
			
			temp=wsk[i];
			wsk[i]=wsk[i+1];
			wsk[i+1]=temp;
			
			for(z=i; z && strlen(wsk[z-1])>strlen(wsk[z]);z--)
			{
				  temp=wsk[z];
				  wsk[z]=wsk[z-1];
				  wsk[z-1]=temp; 	
			}
		}
	}
	return;
}