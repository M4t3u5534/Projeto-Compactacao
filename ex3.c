//Aluno: Pedro Henrique Carvalho Pereira
//RA: 10418861
//Referência utilizada (linha 42 - Imprimir uma string de tamanho específico): https://stackoverflow.com/a/2239571 
//Referência utilizada (linha 27 - Comando strncmp() para comparar strings e verificar repetição): https://www.tutorialspoint.com/c_standard_library/c_function_strncmp.htm 

#include <stdio.h>
#include <string.h>

void ex3(const char *string) {
    int tamString = strlen(string);
    int i = 0;

    while (i < tamString) {

        int tamMAXSubString = tamString - i; 
        int tamSubStringRep = 0;
        int repeticoes = 1;

        for (int TamTesteDeSubString = 1; TamTesteDeSubString <= tamMAXSubString/2; TamTesteDeSubString++) {
            const char *SubString = &string[i]; //ARMAZENA TUDO APÓS i, QUE É ONDE COMEÇA A SUBSTRING - OU SEJA, ARMAZENA A SUBSTRING

            // ATUALIZAÇÃO DAS REPETIÇÇÕES PARA NOVAS BUSCAS
            repeticoes = 1;

            // VERIFICAÇÃO DE REP CONSECUTIVA 
            int j = i + TamTesteDeSubString; //INICIALIZA J PARA COMEÇAR APÓS SUBSTRING ATUAL
            while (j + TamTesteDeSubString <= tamString && strncmp(SubString, &string[j], TamTesteDeSubString) == 0) { 
                repeticoes++;
                j += TamTesteDeSubString;
            } //strncmp(SubString, &string[j], TamTesteDeSubString) == 0 -->  &string[j] contém tudo após a subtring atual. 
            //O TamTesteDeSubString limita a comparação entre "SubString" e "&string[j]" para o tamanho da substring sendo testada nessa passagem do while

            // Se encontrar uma substring repetida maior, atualiza o melhor tamanho
            if (repeticoes > 1 && TamTesteDeSubString > tamSubStringRep) {
                tamSubStringRep = TamTesteDeSubString;
                break;
            }
        }

        // FORMATAÇÃO SAÍDA E ATUALIZAÇÃO DO WHILE
        if (tamSubStringRep > 0) {
            printf("%.*s%d", tamSubStringRep, &string[i], repeticoes); //IMPRIME A SUBSTRING A PARTIR DO PONTO i DO TAMANHO DA "tamSubStringRep"
            i += tamSubStringRep * repeticoes; //AVANÇA i PARA O FINAL DA SUBSTRING REPETIDA
        } else {
            printf("%c1", string[i]);
            i++;
        }
        if (i < tamString) {
            printf("-");
        }
    }
    printf("\n");
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Para compactar, escreva como a forma ao lado: %s \"string\"\n", argv[0]);
        return 1;
    }
    ex3(argv[1]);
    return 0;
}