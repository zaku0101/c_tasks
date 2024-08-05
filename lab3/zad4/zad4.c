#include <stdio.h>

int main(){
    
    int tab[26]={0};
    int curr_char;
    int i =1;
    int counter =0;

    while (1){
        curr_char = getc(stdin);
        if(curr_char == 27){
        break;
        }
        if(curr_char>='a' && curr_char<='z'){
            tab[curr_char-'a']++;
        }
        tab[curr_char-'A']++;
        counter++;
    }

    printf("Wpisano %d znakow.\n",counter);
    
    for(int i=0;i<26;i++){
        printf("Litera: %c %d " ,i+'A',tab[i]);
        for(int j =0; j<tab[i];j++){
            printf("#");
        }
        printf("\n");
     }
}