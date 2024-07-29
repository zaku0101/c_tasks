/*
Autor:  Arkadia Kowalczyk
Grupa:  ŒR/NP 14:15
Temat:  Laboratorium 3
Data:   25 listopada 2020 r.
*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int tab[26]={0};

int main()
{
	char znak=27;
	int ile=0;
	
	printf("Autor: Arkadia Kowalczyk (SR/NP 14:15) \n\n");
	printf("Podaj znak: ");
	znak=getch();
	
	while(znak!=27){
		
		ile++;
		
		if(znak>='A' && znak<='Z'){
				znak-='A';
				tab[znak]++;
		}
		if(znak>='a' && znak<='z'){
				znak-='a';
				tab[znak]++;
		}
		
		znak=getch();
	}
	
	printf("Wprowadzono %d znakow, w tym:\n",ile);
	
	for(int i=0; i<26; i++){
		znak=i+'A';
		printf("\n%c %d ", znak, tab[i]);
		for(int j=tab[i]; j; j--) printf("#");
	}
	
	
	return 0;
}