#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(){
    double eps;
    double max = 0.1;

    double mod1=0, mod2=0, sum1 =0, sum2=0;

    do {
        printf("Podaj eps mniejsze niz 0.1: ");
        scanf("%lf", &eps);
    }while (eps >= max);
    double k = 1;
    
    printf("===Suma1===\n");
    while(1){
        const double single_exp = (pow(-1, k+1) * (1/(2*k-1)));
        mod1 = fabs(single_exp);
        if(eps>mod1){
            break;
        }
        sum1 += 4*single_exp;
        printf("S1: %lf\n",sum1);
        k++;
    }

    printf("===Suma2===\n");
    double j=2;
    double fact=1;

        while(1){

        fact *=  j;
        
        const double single_exp = 1/(fact);
        mod2 = fabs(single_exp);
        if(eps>mod2){
            break;
        }
        sum2 += single_exp;
        printf("S2: %lf\n",sum2);
        j++;
    }
}       