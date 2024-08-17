#include <stdio.h>
#include <string.h>
char  * my_strncpy(char *dest, const char* src, size_t num ){
    for(int i =0; i< num; i++){
        dest[i] = (src[i]!='\0') ? src[i] : 0;
    }
    return dest;
}

char * my_strrchr(char * s, int c){
    char *ptr = NULL;
    while(*s){
        if(*s == c){
            ptr = s;
        }
    s++;
    }
    return ptr;
}

const char * my_strchr(const char * s, int c){
    while(*s){
        if(*s == c){
            return s;
        }
    s++;
    }
    return NULL;
}

const char * my_strcpy(char *dest, const char *str){

    while (*str){
        *dest=*str;
        str++;
        dest++;
    }
    return str;
}

int my_strcmp(const char *s1, const char *s2){

    while (*s1 && (*s1 == *s2)){
        s1++;
        s2++;
    }
    return *(const unsigned char*)s1 - *(const unsigned char*)s2;
}
int my_strlen(const char *str){
    
    int i = -1;
    while(str[++i] != '\0');

    return i;
}

int main(){
    char r[] ="dupa123456";
    int i = strlen(r);
    int i2 = my_strlen(r);
    printf("Lib strlen: %d \n",i);
    printf("My strlen: %d \n",i2);
    
    int i3 = strcmp("dupa", "dup1");
    int i4 = my_strcmp("dupa","dup1");
    printf("Lib strcmp: %d\n",i3);
    printf("My strcmp: %d\n",i4);

    char dest1[20];
    char dest2[20];
    my_strcpy(dest1, "dupa");
    puts(dest1);
    strcpy(dest2,"dupa");
    puts(dest2);

    printf("My strchr: %s \n",my_strchr("dupa", 117));

    printf("my strrchr: %s \n", strrchr("dupa.dupa.com",46));

    char dest5[10];
    printf("my strncpy: %s \n", my_strncpy(dest5, "eloel" , 3));
}