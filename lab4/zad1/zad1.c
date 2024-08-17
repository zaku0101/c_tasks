#include <stdio.h>

void read_equation(float *a, float *b, float *c){
    printf("Podaj a: ");
    scanf("%f", a );
    printf("Podaj b: ");
    scanf("%f", b );
    printf("Podaj c: ");
    scanf("%f", c );
}

float calculate_determinant(float p1, float p2, float p3, float p4){
    return (p1*p4) - (p3*p2);
} 

int calculate_result(float a1,float b1,float c1,float a2,float b2,float c2, float *x, float*y){
    float W = calculate_determinant(a1,b1,a2,b2);
    float Wx = calculate_determinant(c1,b1,c2,b2);
    float Wy = calculate_determinant(a1,c1,a2,c2);
    if (W !=0){
        *x = Wx/W;
        *y = Wy/W;
        return 1;
    }
    else if(Wx==0 && Wy ==0){
        return 2;
    }
    else if(Wx !=0 && Wy !=0){
        return 0;
    }
}
void print_results(int n, float x, float y){
    if(n==2){
        printf("Nieskonczenie wiele rozwiazan\n");
    }else if(n==1){
        printf("x = %.2f , y = %.2f\n",x,y);
    }else{
        printf("Brak rozwiazan. uklad sprzeczny\n");
    }
}

int main(){
    float a1,b1,c1;
    float a2,b2,c2;
    float x,y;
    int N;
    printf("Podaj wspolczynniki rownania nr: 1.\n");
    read_equation(&a1,&b1,&c1);
    printf("Podaj wspolczynniki rownania nr: 2.\n");
    read_equation(&a2,&b2,&c2);
    N = calculate_result(a1,b1,c1,a2,b2,c2,&x,&y);
    print_results(N,x,y);
    
    
}