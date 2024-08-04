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
        double single_exp = (pow(-1, k+1) * (1/(2*k-1)));
        mod1 = fabs(single_exp);
        if(eps>mod1){
            break;
        }
        sum1 += 4*single_exp;
        printf("S1: %lf\n",sum1);
        k++;
    }

    printf("===Suma2===\n");
    double j=1;
    double first=1;
    double fact;

        while(1){

        if (j==first){
            fact=j;
        }
        else{
            fact *=  j;
        }
        
        double single_exp = 1/fact;
        mod2 = fabs(single_exp);
        if(eps>mod2){
            break;
        }
        sum2 += single_exp;
        printf("S2: %lf\n",sum2);
        j++;
    }
}       