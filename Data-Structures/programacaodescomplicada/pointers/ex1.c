#include <stdio.h>

int main() {
    int inteiro = 10;
    float real = 5.5;
    char palavra = 'A';
   
    //Ponteiros
    int *pinteiro;
    float *preal;
    char *ppalavra;

    // associa os ponteiros as variaveis
    pinteiro = &inteiro;
    preal = &real;
    ppalavra = &palavra;

    // printa os valores antigos
    printf("Valores anteriores :\n");
    printf("Inteiro: %d\n", inteiro);
    printf("Real: %.2f\n", real);
    printf("Caractere: %c\n", palavra);

    // modifica os valores.
    *pinteiro = 50;
    *preal = 69.9;
    *ppalavra = 'Z';

    // printa os valores novos
    printf("\nNovos valores :\n");
    printf("Inteiro: %d\n", inteiro);
    printf("Real: %.2f\n", real);
    printf("Caractere: %c\n", palavra);

    return 0;
}