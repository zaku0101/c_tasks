#include<stdio.h>
#include<math.h>

int main(void){
    float a,b,c;
    
    do
    {
        printf("Podaj a:");
        scanf("%f", &a);
        printf("Podaj b:");
        scanf("%f", &b);
        printf("Podaj c:");
        scanf("%f", &c);
    }
    while(a==0);

    int delta = (b*b) - (4*a*c);

    if(delta < 0){
        printf("Brak pierwiastków rzeczywistych\n");
        return 1;
    }else if(delta == 0){
        float x = -b/(2*a);
        printf("Istnieje tylko jeden pierwiastek x = %f\n",x);
    }else{
        float x1 = (-b - sqrt(delta))/(2*a);
        float x2 = (-b + sqrt(delta))/(2*a);
        printf("Obliczone pierwiastki x1: %f%s%f\n",x1,"x2: ",x2);
    }

    return 0;
}
