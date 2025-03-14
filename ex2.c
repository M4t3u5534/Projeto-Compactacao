// Carolina Lee - 10440304
// Mateus Ribeiro Cerqueira - 10443901
//Pedro Carvalho - 10418861
//Referência utilizada (Linha 15 - Conversão de char em int): https://pt.stackoverflow.com/a/3763

#include <stdio.h>

void ex2(const char *codigoCompac) {
    while (*codigoCompac != '\0') {
        char caractere = *codigoCompac;
        codigoCompac++;
        int cont = 0;

        while (*codigoCompac >= '0' && *codigoCompac <= '9') {
            cont = (cont * 10) + (*codigoCompac - '0');
            codigoCompac++;
        }
        for (int i = 0; i < cont; i++) {
            putchar(caractere);
        }
        if (*codigoCompac == '-') {
            codigoCompac++;
        }
    }
    printf("\n");
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Para descompactar, escreva como a forma ao lado: %s \"string compactada (letraNumero-letraNumero...)\"\n", argv[0]);
        return 1;
    }
    ex2(argv[1]);
    return 0;
}
