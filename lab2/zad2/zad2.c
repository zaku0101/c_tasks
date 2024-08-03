#include <stdio.h>

int main(){
    
    unsigned long number;
    int sum=0,rem;
    
    printf("Podaj potezna liczbe: ");   
    scanf("%lu", &number);

    while(number != 0){
        rem = number%10;
        sum = sum + rem;
        number = number/10;
    }
    
    printf("Suma cyfr: %d\n",sum);
    
    }