#include <stdio.h>
#include <stdlib.h>
#include <string.h>

    //CODE FORMAT ACCORDING TO DOOM 3 (i guess)

int main(){
    //temp name is a temporary var to get the names.
char tempname[20]{};
char *name;
//op is the operator var

int op = 0;

// MENU 
while(op >= 0 && op=<4){
    printf("\1) Adicionar nome:  \n2) Remover nome:  \n3) Listar nomes:  \n4)Sair: ");






 if ( op > 4 || op < 0 ){
    printf("\nDigite uma opcao valida: ");
    op = 0;
 }
}




return 0;
}