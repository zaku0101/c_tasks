#include<stdio.h>
#include <math.h>

/*
Proszę napisać funkcję, która wczytuje minimalny i maksymalny promień koła oraz liczbę
wierszy tabeli, w której będą wypisane promienie i odpowiadające im obwód oraz pole koła.
Tabela z ramkami oraz nagłówkiem powinna zawierać cztery kolumny: numer wiersza,
promień koła, obwód koła, pole koła. Wzór tabelki pokazano na rysunku poniżej.

Wskazówka:
Do obliczeń obwodu i pola koła proszę wykorzystać dokładną wartość π, która jest
zdefiniowana w stałej M_PI z biblioteki math.h . 
*/

static inline calculate_perimeter(float radius){
   float perimeter = 2 * radius * M_PI;     
   return perimeter;    
}

static inline calculate_area(float radius){
   float area = M_PI * (radius*radius);         
   return area;
}

static inline calculate_step(float min_r, float max_r, float number_of_steps){
      float step = (max_r - min_r) / (number_of_steps - 1);
      return step;
}

int main(void)
{
    float min_r,max_r,number_of_rows;
    
    printf("Podaj minimalny promien:");
    scanf("%f", &min_r);
    printf("Podaj maksymalny promien:");
    scanf("%f", &max_r);
    printf("Podaj liczbe wierszy:");
    scanf("%f", &number_of_rows);

   printf("=========================================\n");
   printf(": Lp : promien : obwod kola : pole kola :\n");
   printf("=========================================\n");

   const step = calculate_step(min_r,max_r,number_of_rows);
   float radius = min_r;
   for(int i=1;i<=number_of_rows;i++){
      const float area = calculate_area(radius);
      const float perimeter = calculate_perimeter(radius);
      printf("| %2d | %6.2f | %10.2f | %10.2f |\n", i , radius, perimeter, area);
      radius+= step;  
   }
   printf("=========================================\n");
   return 0;
}