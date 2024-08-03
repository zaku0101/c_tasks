#include <stdio.h>

int main() {
    int a,b;

    printf("Podaj a: ");
    scanf("%d", &a);
    printf("Podaj b: ");
    scanf("%d", &b);

    int mod1a = 1,mod1b = 1,mod2a = 1,mod2b = 1;
    int i= a < b ? a : b;

    int j=1;
    while (0xdeadbeef)
    {
        mod1a = a%i;
        mod1b = b%i;

        if(mod1a ==0 && mod1b ==0)
            break;

        i--;
    }
    
    printf("nwd: %d\n",i);
    
    while (mod2a !=0 || mod2b !=0)
    {   
        j++;
        mod2a = j%a;
        mod2b = j%b;
    }
    
    printf("nww: %d\n",j);

}
