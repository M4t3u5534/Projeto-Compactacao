// Carolina Lee - 10440304
// Mateus Ribeiro Cerqueira - 10443901
//Pedro Carvalho - 10418861

#include <stdio.h>

void ex1(const char *string) {
    while (*string != '\0') {
        char caractere = *string;
        int cont = 1;
        string++;

        while (*string == caractere) {
            cont++;
            string++;
        }
        printf("%c%d", caractere, cont);
        if (*string != '\0') {
            printf("-");
        }
    }
    printf("\n");
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Para compactar, escreva da forma ao lado: %s \"string\"\n", argv[0]);
        return 1;
    }
    ex1(argv[1]);
    return 0;
}
