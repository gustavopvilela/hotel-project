#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "reservas.h"
//incluir o de gestão de dados para pegar os dados das acomodações

//função responsável por fazer as pesquisas em acomodações para verificar as especificações
void pesquisa(char* dataEnt, char* dataSai, char* categoria, int qtdAd, 
        int qtdCr, char* facilidade){
    
    int tam = 10;
    int *resultados = malloc(tam * sizeof(int));
    FILE *acomodacaoBin;
    acomodacaoBin = fopen("acomodacao.bin", "ab");
    
    /* Verificação da abertura. */
    if (acomodacaoBin == NULL) {
        printf("Erro na abertura do arquivo.\n");
        exit(1);
    }
    
    
}
