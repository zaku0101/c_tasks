#include <stdio.h>
#include <stdbool.h>

#define  ROZMIAR  5

int main() {

    float tab[ROZMIAR];

    for(int i = 0; i < ROZMIAR;i++){
        printf("Tab[%d] = ",i);
        scanf("%f",&tab[i]);
    }

    int negative=0;
    int positive=0;

    bool is_order_asc;

    for(int i =0; i<ROZMIAR-1;i++){
        is_order_asc = (tab[i] < tab[i+1]) ? true : false;
    }

    for(int i=0;i<ROZMIAR;i++){
        negative = tab[i] < 0 ? negative +=1 : negative ;
        positive = tab[i] > 0 ? positive +=1 : positive ;
    }
    
    printf(is_order_asc ? "Rosnaco\n":"Malejaco\n");
    printf("Liczba ujemnych: %d\n",negative);
    printf("Liczba dodatnich: %d\n", positive);
}