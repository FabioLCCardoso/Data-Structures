#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//functions

void menu( char tempname[20],char *name);
void addname(char tempname[20],char *name);
void removename(void);
void list( char *name);


int main( void ) {
    // tempname is a temp var and name the result
char tempname[20] = {};
char *name = NULL;

 menu(tempname, name);

return 0;
}

//just a simple menu function :)
//also, op is the operator var

void menu(char tempname[20],char *name){
    int op = 0;
    while( op >= 0 && op < 4  ){
    printf("1) Adicionar nome: \n2) Remover nome: \n3) Listar \n4) Sair\n");
    scanf("%d", &op);
    if( op < 0 || op > 4){
        printf("Escolha um numero valido: \n");
        op = 0;
    }
    switch(op){
        case 1: printf("Escreva o nome:\n");
         addname(tempname, name); 
        break;
        case 2 : 
        break; 
        case 3: 
         list(name);
        break;
        case 4: 
        free(name);
        exit(0);

    }
    }
}

//function to add name using dynamic allocation to increase the string length 

void addname(char tempname[20],char *name){

    scanf("%s", tempname);
    getchar();

    //if name is empty, it will allocate memory and copy tempname in it

    if(name == NULL){
        name = ( char * )(malloc (strlen (tempname) +1));
    int i;

    for( i = 0; i < strlen(name); i++){
        name[i] = tempname[i];
    }
    name[i + 1] = '\0' ;

    //reallocate memory and adds the size of the new name

    } else{
        name = (char * ) ( realloc ( name, strlen (tempname) + strlen (name) + 1));
    //copies the new name to the string 
    int i = 0;
    int j = 0;
        for ( i = strlen(name),  j;  j < strlen(tempname) ;  i++,  j++ ){
        name[i] = tempname[j];
        }
        name[i + 1 ]= '\0';
        

    }

}

void list(char *name){
    for( int i = 0; i<strlen(name); i++){
        printf("%s \n", name[i]);
    }
}

//TODO remove function