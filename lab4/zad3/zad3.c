#include<stdio.h>

#define OFFSET ('a'-'A')

char * my_strupr(char *str ){
     
    for(int i=0; str[i] != '\0'; i++){
        if(str[i] >= 'a' && str[i] <= 'z')
            str[i] = str[i] - OFFSET;
    }
    return str;
}    

char * my_strlwr(char *str){

        for(int i=0; str[i] != '\0'; i++){
        if(str[i] >= 'A' && str[i] <= 'Z')
            str[i] = str[i] + OFFSET;
    }

    return str;
}

int main(){
    char str[] = "dupa";
    printf("%s \n",my_strupr(str));
    char str2[] = "DUPA";
    printf("%s \n",my_strlwr(str2));
    
}