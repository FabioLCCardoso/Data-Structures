#include <stdio.h>
#include <stdlib.h>
#include <string.h>

    //CODE FORMAT ACCORDING TO DOOM 3 (i guess)

int main(){
    //tempname is a temporary var to get the names.
char tempname[20] = {};
char *name = NULL;
//op is the operator var

int op = 0;

// MENU 
while(op >= 0 && op<4){
    printf("\n1) Adicionar nome:  \n2) Remover nome:  \n3) Listar nomes:  \n4)Sair: ");
    scanf("%d", &op);
 if ( op > 4 || op < 0 ){
    printf("\nDigite uma opcao valida: ");
    op = 0;
 }
    switch(op){
        case 1:
        scanf("%s", tempname);
        getchar();
        //if name is empty, it will allocate memory and copy tempname contents
        if(name == NULL){
            name = (char *)malloc(strlen(tempname)+ 1);
      
        strncpy(name, tempname, strlen( tempname) );

      
        }                         
          //reallocate memory and adds the size of the new name
        else{
            char *newname = (char *)realloc(name,  strlen(name) + strlen(tempname) +1 );
            name = newname;
            strcpy(name + strlen(name), tempname );
        }
        break;
        //TODO remove function to find and remove names chosen by the user
        case 2:
        break;
        //just list the names
        case 3:
        for(int i = 0; i<strlen(name); i++ ){
            printf("%c", name[i]);
        }

        break;
        case 4:
        //free allocated memory
        
        free(name);
        exit(1);
        
    }

}






return 0;
}