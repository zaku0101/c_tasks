#include <stdio.h>


int main(){
    
    int rows,cols;
    
    printf("Podaj liczbe kolumn: ");
    scanf("%d", &cols);
    printf("Podaj liczbe wierszy: ");
    scanf("%d", &rows);
    
    printf("  |");
    for(int i = 1; i <= cols; i++){
        printf("%4d", i);
        
    }
    printf("\n");
    printf("--|-");
    for (int i =1; i<=cols;i++){
        printf("----");
    }
    printf("\n");
    for(int i =1;i<=cols;i++){      
        printf("%2d|",i);
        for(int j=1;j<=rows;j++){
           
            int prod = i*j;
            printf("%4d",prod);
        }   
        printf("\n");
    }
}