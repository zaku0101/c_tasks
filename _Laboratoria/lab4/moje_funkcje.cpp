/*
Autor:  Arkadia Kowalczyk
Grupa:  ŒR/NP 14:15
Temat:  Laboratorium 4
Data:   11 grudnia 2020 r.
*/

#include <stdio.h>
#include <string.h>


char kopia2[100]; //wyzerowanie tablicy
const char r='a'-'A'; //uzywane w kilku funkcjach

size_t Moje_strlen(const char *zdanie);
//zwraca dlugosc zdania

int Moje_strcmp(const char *str1, const char *str2);
//porownuje dwa zdania

char* Moje_strcpy(char* destination, const char* source);
/*
kopiuje zdanie
					!!UWAGA!!
the size of the array pointed by destination 
shall be long enough to contain the same C string 
as source (including the terminating null character), 
and should not overlap in memory with source. 
*/

char* Moje_strncpy(char* destination, const char* source, size_t n);
// kopiuje pierwsze 5 znaków

char* moje_strupr(char* zdanie);
char* moje_strlwr(char* zdanie);

int main()
{
	char zdanie[100];
	char kopia[100];
	char komunikat[100];

	printf("Autor: Arkadia Kowalczyk (SR/NP 14:15) \n");
	
	printf("Podaj zdanie:");
	gets(zdanie);

	//strlen
	printf ("\nLiczba znakow wedlug strlen: %d.\n", (unsigned)strlen(zdanie));
	printf ("Liczba znakow wedlug moje strlen: %d.\n\n", Moje_strlen(zdanie));

	//strcmp
	char key[] = "Ala";
	char buffer[80];
	do
	{
		printf ("Kto ma kota? ");
		fflush (stdout);
		scanf ("%79s", buffer);
	}
	while (Moje_strcmp (key, buffer) != 0);
	printf ("Tak! Ala ma kota\n\n");

	//strcpy
	Moje_strcpy (kopia, zdanie);
	Moje_strcpy (komunikat, "Udane kopiowanie");
	printf ("zdanie:  %s\nkopia: %s\nkomunikat: %s\n\n", zdanie, kopia, komunikat);

	//strncpy
	Moje_strncpy (kopia2, zdanie, 5);
	printf ("Kopia 5ciu znakow\nzdanie:  %s\nkopia: %s\n", zdanie, kopia2);		
		
	Moje_strncpy (kopia2, zdanie, Moje_strlen(zdanie));
	printf ("Kopia calego zdania\nzdanie:  %s\nkopia: %s\n", zdanie, kopia2);
	
	//strupr
	moje_strupr(zdanie);
	printf("\n%s\n",zdanie);
	
	//strlwr
	moje_strlwr(zdanie);
	printf("\n%s\n",zdanie);
	
	return 0;
}

size_t Moje_strlen(const char *zdanie)
{
	int len = 0;
	while(zdanie[len] != 0) len++;
	return len;
}

int Moje_strcmp(const char* str1, const char* str2)
{
	int i = 0;

	for(; str1[i] == str2[i]; i++)
		if (str1[i] == 0) return 0;


	return str1[i] - str2[i];
}

char* Moje_strcpy(char* destination, const char* source)
{
	destination[0] = source[0];
	for(int i = 1; source[i - 1]; i++)
		destination[i] = source[i];

	return destination;
}

char* Moje_strncpy(char* destination, const char* source, size_t n)
{
	for(int i = 0; n; i++, n--)
	{
		if(source[i])
		   	destination[i] = source[i];
		else{ destination[i]=0;  i--;} 	   
	}

	return destination;
}

char* moje_strupr(char* zdanie)
{
	
	for(int i=0; zdanie[i]; i++)
	{
		if (zdanie[i]>='a' && zdanie[i]<='z') zdanie[i]-=r;
	}
	return zdanie;
}

char* moje_strlwr(char* zdanie)
{
		for(int i=0; zdanie[i]; i++)
	{
		if (zdanie[i]>='A' && zdanie[i]<='Z') zdanie[i]+=r;
	}
	return zdanie;
}