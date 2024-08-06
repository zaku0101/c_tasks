#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>

#define  ROZMIAR  5

void read_user_input(float *tab){
    for(int i = 0; i < ROZMIAR;i++){
    printf("Tab[%d] = ",i);
    scanf("%f",&tab[i]);
    }
}
void rand_fill_table(float *tab){
    int rand_max;
    printf("Podaj max rnd: ");
    scanf("%d", &rand_max);
    srand(time(NULL));
    for(int i=0;i<ROZMIAR;i++){
        tab[i]= (float) (rand() % rand_max+1 );
    }

}

void is_order_asc(float tab[]){
    bool is_order_asc;

    for(int i =0; i<ROZMIAR-1;i++){
        is_order_asc = (tab[i] < tab[i+1]) ? true : false;
    }
    printf(is_order_asc ? "Rosnaco\n":"Malejaco\n");
}

void print_pos_neg(float tab[]){
    int negative=0;
    int positive=0;

    for(int i=0;i<ROZMIAR;i++){
        negative = tab[i] < 0 ? negative +=1 : negative ;
        positive = tab[i] > 0 ? positive +=1 : positive ;
    }
    
    printf("Liczba ujemnych: %d\n",negative);
    printf("Liczba dodatnich: %d\n", positive);
}
void sort_arr_asc(float *tab){
    for(int i=0;i<ROZMIAR-1;i++){
        for(int j=0;j<ROZMIAR-i-1;j++){
            if(tab[j]>tab[j+1]){
                float temp = tab[j];
                tab[j] =tab[j+1];
                tab[j+1] = temp;
            }
        }
    }
}

void print_table(float tab[]){
    printf("Tab = [  ");
    for(int i=0;i <ROZMIAR;i++){
        printf("%.1f  " , tab[i]);
    }
    printf("]");
}

int main() {

    float tab[ROZMIAR];
    rand_fill_table(tab);
    print_table(tab);
    sort_arr_asc(tab);
    print_table(tab);

}  