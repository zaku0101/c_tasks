#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHARS 32

#define STRINGIFY(x) #x 
#define STR(x) STRINGIFY(x)

#define SPECIFIER_MAX_CHARS "%" STR(MAX_CHARS) "s"

void add_name(char*** dict, int *size){
    char name[MAX_CHARS];
    printf("Please type name: ");
    scanf(SPECIFIER_MAX_CHARS ,name);
    
    *dict = (char **)realloc(*dict, (sizeof(char *))*(*size + 1));
    (*dict)[*size] = (char *)malloc(MAX_CHARS);

    memcpy((*dict)[*size], name, MAX_CHARS);
    (*size)++;
}

void remove_name_by_index(char*** dict, int *size){
    int index;
    printf("Type index to be removed: ");
    scanf("%d",&index);  
    free(*dict[index]);
    (*dict)[index] = (*dict)[*size - 1];
    *dict = (char **)realloc(*dict, (sizeof(char *))*(*size - 1));
    (*size)--; 
}

void remove_name_by_name(char*** dict, int *size){
    char name[MAX_CHARS];
    printf("Type name to be removed: ");
    scanf(SPECIFIER_MAX_CHARS, name);

    for(int i =0;i< *size-1; i++){
        if(!strcmp(*dict[i],name)){
            free(*dict[i]);
            (*dict)[i]= (*dict)[*size-1];
            *dict = (char **)realloc(*dict, (sizeof(char *))*(*size - 1));
            (*size)--;
            break;
        }
    }
}

void
print_names(char **dict, int size)
{
    for(int i=0; i<size; i++)
        printf("%s\n", dict[i]);
}

void print_names_starting_with_char(char **dict, int size){
    char c;
    printf("Type character: ");
    scanf("%s", &c);

    for(int i = 0;i<size;i++){
        if(dict[i][0] == c){
            printf("%s\n", dict[i]);
        }
    }
}

void swap(char **str, int i, int j){
    char *temp = str[i];
    str[i] = str[j];
    str[j] = temp;
}

void sort_alphabet(char** dict, int size){
    for(int i = 0; i < size - 1; i++){
        for(int j =0; j < size - i - 1; j++){
            if(strcmp(dict[j],dict[j+1]) > 0){
                swap(dict, j, j+1 );
            }
        }
    }
}

void sort_length(char** dict, int size){
    for(int i = 0; i < size - 1; i++){
        for(int j =0; j < size - i - 1; j++){
            if(strlen(dict[j]) > strlen(dict[j+1])){
                swap(dict, j, j+1 );
            }
        }
    }    
}

void deinit_dict(char ***dict, int *size)
{
    for(int i=0; i<*size; i++)
        free(*dict[i]);

    free(*dict);
}
int main(){
    char **dict;
    int dict_size = 0;
    add_name(&dict,&dict_size);
    add_name(&dict,&dict_size);
    add_name(&dict,&dict_size);
    remove_name_by_index(&dict, &dict_size);
    print_names(dict,dict_size);
    sort_alphabet(dict,dict_size);
    print_names(dict,dict_size);
    sort_length(dict,dict_size);
    print_names(dict,dict_size);
    remove_name_by_name(&dict,&dict_size);
    print_names(dict,dict_size);
    print_names_starting_with_char(dict,dict_size);
}
