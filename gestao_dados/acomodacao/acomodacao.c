#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "acomodacao.h"

void inserirAcomodacao (Acomodacao acomodacao, int opcao) {
    switch (opcao) {
        case 1:
            FILE *acomodacaoBin;
            acomodacaoBin = fopen(ACOMODACAO_BIN, "ab");

            /* Verificação da abertura. */
            if(acomodacaoBin == NULL){
                printf("Erro na abertura do arquivo.\n");
                exit(1);
            }

            /* Inserindo no arquivo binário. */
            if (!feof(acomodacaoBin)) {
                fwrite(&acomodacao, sizeof(Acomodacao), 1, acomodacaoBin);
            }
            else {
                printf("Arquivo cheio.\n");
                exit(1);
            }

            /* Fechando o arquivo. */
            fclose(acomodacaoBin);
        break;
        
        case 2:
            FILE *acomodacaoTxt;
            acomodacaoTxt = fopen(ACOMODACAO_TXT, "a");
            
            /* Verificação da abertura. */
            if(acomodacaoTxt == NULL){
                printf("Erro na abertura do arquivo.\n");
                exit(1);
            }
            
            /* Inserindo no arquivo de texto. */
            if (!feof(acomodacaoTxt)) {
                fprintf(acomodacaoTxt, "Código: %d\nDescrição: %s\nFacilidades: %d\nCategoria: %d\n",
                        acomodacao.codigo, acomodacao.descricao, acomodacao.facilidades,
                        acomodacao.categoria);
            }
            else {
                printf("Arquivo cheio.\n");
                exit(1);
            }

            fclose(acomodacaoTxt);
        break;
    }
}

void inserirAcomodacaoMemoria(Acomodacao dados, Acomodacao **listaAcom, int *contador) {
    *listaAcom = (Acomodacao *)realloc(*listaAcom, (*contador + 1) * sizeof(Acomodacao));

    /* Caso o ponteiro retorne NULL, significa que já não há mais espaço. */
    if (*listaAcom == NULL) {
        printf("Memória insuficiente!");
        exit(1);
    }

    (*listaAcom)[*contador] = dados;
    (*contador)++;
}

void lerAcomodacao (int codigo, int opcao) {
    Acomodacao acomodacao;
    int encontrado = 0;
    
    switch (opcao) {
        case 1:
            FILE *acomodacaoBin;
            acomodacaoBin = fopen(ACOMODACAO_BIN, "ab");

            /* Verificação da abertura. */
            if(acomodacaoBin == NULL){
                printf("Erro na abertura do arquivo.\n");
                exit(1);
            }

            rewind(acomodacaoBin);

            while (fread(&acomodacao, sizeof(Acomodacao), 1, acomodacaoBin) == 1) {
                if (acomodacao.codigo == codigo) {
                    printf("Código: %d\n", acomodacao.codigo);
                    printf("Descrição: %s\n", acomodacao.descricao);
                    printf("Categoria: %d\n", acomodacao.categoria);
                    printf("Facilidades: %d\n", acomodacao.facilidades);
                    printf("\n");
                    encontrado = 1;
                }
            }
            if (!encontrado) {
                printf("Acomodação com código %d não encontrado.\n", codigo);
            }

            /*Fechando o arquivo*/
            fclose(acomodacaoBin);
        break;
            
        case 2:
            FILE *acomodacaoTxt;
            acomodacaoTxt = fopen(ACOMODACAO_TXT, "r");

            /* Verificação da abertura. */
            if (acomodacaoTxt == NULL) {
                printf("Erro na abertura do arquivo.\n");
                exit(1);
            }
            
            rewind(acomodacaoTxt);
            while (fscanf(acomodacaoTxt, "%*s %d\n%*s %[^\n]\n%*s %d\n%*s %d",
                          &acomodacao.codigo, acomodacao.descricao, acomodacao.facilidades, &acomodacao.categoria) == 4) {
                if (acomodacao.codigo == codigo) {
                    printf("Código: %d\n", acomodacao.codigo);
                    printf("Descrição: %s\n", acomodacao.descricao);
                    printf("Facilidades: %d\n", acomodacao.facilidades);
                    printf("Categoria: %d\n", acomodacao.categoria);
                    printf("\n");
                    encontrado = 1;
                }
            }
            if (!encontrado) {
                printf("Acomodação com código %d não encontrado.\n", codigo);
            }
            
            fclose(acomodacaoTxt);
        break;
    }
}

int acomodacaoExiste (int codigo, int opcao) {
  Acomodacao acomodacao;
    int encontrado = 0;
    
    switch (opcao) {
        case 1:
            FILE *acomodacaoBin;
            acomodacaoBin = fopen(ACOMODACAO_BIN, "ab");

            /* Verificação da abertura. */
            if(acomodacaoBin == NULL){
                printf("Erro na abertura do arquivo.\n");
                exit(1);
            }

            rewind(acomodacaoBin);

            while (fread(&acomodacao, sizeof(Acomodacao), 1, acomodacaoBin) == 1) {
                if (acomodacao.codigo == codigo) {
                    encontrado = 1;
                    break;
                }
            }

            /*Fechando o arquivo*/
            fclose(acomodacaoBin);
            
            return encontrado;
        break;
            
        case 2:
            FILE *acomodacaoTxt;
            acomodacaoTxt = fopen(ACOMODACAO_TXT, "r");

            /* Verificação da abertura. */
            if (acomodacaoTxt == NULL) {
                printf("Erro na abertura do arquivo.\n");
                exit(1);
            }
            
            rewind(acomodacaoTxt);
            while (fscanf(acomodacaoTxt, "%*s %d\n%*s %[^\n]\n%*s %d\n%*s %d",
                          &acomodacao.codigo, acomodacao.descricao, acomodacao.facilidades, &acomodacao.categoria) == 4) {
                if (acomodacao.codigo == codigo) {
                    encontrado = 1;
                    break;
                }
            }
            
            fclose(acomodacaoTxt);
            
            return encontrado;
        break;
    }   
}

void lerAcomodacaoMemoria(Acomodacao *listaAcom, int tamanho, int codigo) {
    for (int i = 0; i < tamanho; i++) {
        if (listaAcom[i].codigo == codigo) {
            printf("Código: %d\n", listaAcom[i].codigo);
            printf("Descrição: %s\n", listaAcom[i].descricao);
            printf("Categoria: %d\n", listaAcom[i].categoria);
            printf("Facilidades: %d\n", listaAcom[i].facilidades);
            printf("\n");
        }
    }
}

int acomodacaoExisteMemoria (Acomodacao *listaAcom, int tamanho, int codigo) {
    int encontrado = 0;
    
    for (int i = 0; i < tamanho; i++) {
        if (listaAcom[i].codigo == codigo) {
            encontrado = 1;
            break;
        }
    }
    
    return encontrado;
}

void listarAcomodacoes (int opcao) {
    Acomodacao acomodacao;
    
    switch (opcao) {
        case 1:
            FILE *acomodacaoBin;
            acomodacaoBin = fopen(ACOMODACAO_BIN, "rb");

            /* Verificação da abertura. */
            if(acomodacaoBin == NULL){
                printf("Erro na abertura do arquivo.\n");
                exit(1);
            }

            rewind(acomodacaoBin);

            while (fread(&acomodacao, sizeof(Acomodacao), 1, acomodacaoBin) == 1) {
                printf("Código: %d\n", acomodacao.codigo);
                printf("Descrição: %s\n", acomodacao.descricao);
                printf("Facilidades: %d\n", acomodacao.facilidades);
                printf("Categoria: %d\n", acomodacao.categoria);
                printf("\n");
            }

            fclose(acomodacaoBin);
        break;
            
        case 2:
            FILE *acomodacaoTxt;
            acomodacaoTxt = fopen(ACOMODACAO_TXT, "r");

            /* Verificação da abertura. */
            if (acomodacaoTxt == NULL) {
                printf("Erro na abertura do arquivo.\n");
                exit(1);
            }
            
            rewind(acomodacaoTxt);
            while (fscanf(acomodacaoTxt, "%*s %d\n%*s %[^\n]\n%*s %d\n%*s %d",
                          &acomodacao.codigo, acomodacao.descricao, acomodacao.facilidades, &acomodacao.categoria) == 4) {
                printf("Código: %d\n", acomodacao.codigo);
                printf("Descrição: %s\n", acomodacao.descricao);
                printf("Facilidades: %d\n", acomodacao.facilidades);
                printf("Categoria: %d\n", acomodacao.categoria);
                printf("\n");
            }
            
            fclose(acomodacaoTxt);
        break;
    }
}

void listarAcomodacaoMemoria(Acomodacao *listaAcom, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("Código: %d\n", listaAcom[i].codigo);
        printf("Descrição: %s\n", listaAcom[i].descricao);
        printf("Categoria: %d\n", listaAcom[i].categoria);
        printf("Facilidades: %d\n", listaAcom[i].facilidades);
        printf("\n");
    }
}

void atualizarAcomodacao (Acomodacao novosDados, int codigo, int opcao) {
    switch (opcao) {
        case 1:
            if (acomodacaoExiste(codigo, opcao) != 0) {
                deletarAcomodacao(codigo, opcao);

                FILE *acomodacaoBin;
                acomodacaoBin = fopen(ACOMODACAO_BIN, "ab");

                /* Verificação da abertura. */
                if(acomodacaoBin == NULL){
                    printf("Erro na abertura do arquivo.\n");
                    exit(1);
                }

                fwrite(&novosDados, sizeof(Acomodacao), 1, acomodacaoBin);
                printf("Atualizada a acomodação de código %d.", codigo);

                fclose(acomodacaoBin);
            }
            else {
                printf("Acomodação de código %d não encontrado.", codigo);
            }
        break;
            
        case 2:
            if (acomodacaoExiste(codigo, opcao) != 0) {
                /* Deletando os dados antigos. */
                deletarAcomodacao(codigo, opcao);
                
                /* Atualizando o hóspede. */
                inserirAcomodacao(novosDados, opcao);
                
                printf("Atualizada a acomodação de código %d.", codigo);
            }
            else {
                printf("Acomodação de código %d não encontrado.", codigo);
            }
        break;
    }
}

void atualizarAcomodacaoMemoria (Acomodacao *listaAcom, Acomodacao novosDados, int codigo, int tamanho) {
    int encontrado = 0;
    
    for (int i = 0; i < tamanho; i++) {
        if (listaAcom[i].codigo == codigo) {
            listaAcom[i] = novosDados;
            encontrado = 1;
            break;
        }
    }
    
    if (encontrado == 0) {
        printf("Acomodação não encontrada!");
    }
}

void deletarAcomodacao (int codigo, int opcao) {
    int dadoAchado = 0;
    Acomodacao acomodacao;
    
    switch (opcao) {
        case 1:
            FILE *acomodacaoBin;
            acomodacaoBin = fopen(ACOMODACAO_BIN, "ab");

            /* Verificação da abertura. */
            if(acomodacaoBin == NULL){
                printf("Erro na abertura do arquivo.\n");
                exit(1);
            }

            FILE *acomodacaoBin_tmp;
            acomodacaoBin_tmp = fopen(ACOMODACAO_TMP_BIN, "wb");

            /* Verificação da abertura. */
            if(acomodacaoBin_tmp == NULL){
                printf("Erro na abertura do arquivo.\n");
                exit(1);
            }

            rewind(acomodacaoBin);
            while (fread(&acomodacao, sizeof(Acomodacao), 1, acomodacaoBin) == 1) {
                if (acomodacao.codigo == codigo) {
                    printf("Deleção concluída!");
                    dadoAchado = 1;
                }
                else {
                    fwrite(&acomodacao, sizeof(Acomodacao), 1, acomodacaoBin_tmp);
                }
            }

            if (dadoAchado == 0) {
                printf("Nenhuma categoria de acomodação foi encontrada com este código: %d.\n", codigo);
            }

            fclose(acomodacaoBin);
            fclose(acomodacaoBin_tmp);

            remove("acmodacao.bin");
            rename(ACOMODACAO_TMP_BIN, ACOMODACAO_BIN);
        break;
            
        case 2:
            FILE *acomodacaoTxt;
            acomodacaoTxt = fopen(ACOMODACAO_TXT, "r");

            /* Verificação da abertura. */
            if (acomodacaoTxt == NULL) {
                printf("Erro na abertura do arquivo.\n");
                exit(1);
            }

            FILE *acomodacaoTxt_tmp;
            acomodacaoTxt_tmp = fopen(ACOMODACAO_TMP_TXT, "w");

            /* Verificação da abertura. */
            if (acomodacaoTxt_tmp == NULL) {
                printf("Erro na abertura do arquivo.\n");
                exit(1);
            }
            
            rewind(acomodacaoTxt);
            while (fscanf(acomodacaoTxt, "%*s %d\n%*s %[^\n]\n%*s %d\n%*s %d",
                          &acomodacao.codigo, acomodacao.descricao, acomodacao.facilidades, &acomodacao.categoria) == 4) {
                if (acomodacao.codigo == codigo) {
                    printf("Deleção concluída!");
                    dadoAchado = 1;
                } else {
                    fprintf(acomodacaoTxt, "Código: %d\nDescrição: %s\nFacilidades: %d\nCategoria: %d\n",
                            acomodacao.codigo, acomodacao.descricao, acomodacao.facilidades,
                            acomodacao.categoria);
                }
            }

            if (dadoAchado == 0) {
                printf("Nenhuma acomodação foi encontrada com este código: %d.\n", codigo);
            }

            fclose(acomodacaoTxt);
            fclose(acomodacaoTxt_tmp);

            remove(ACOMODACAO_TXT);
            rename(ACOMODACAO_TMP_TXT, ACOMODACAO_TXT);
        break;
    }
}

void deletarAcomodacaoMemoria (Acomodacao *listaAcom, int *tamanho, int codigo) {
    int encontrado = 0;
    
    for (int i = 0; i < *tamanho; i++) {
        if (listaAcom[i].codigo == codigo) {
            for (int j = i; j < (*tamanho) - 1; j++) {
                (listaAcom)[j] = (listaAcom)[j+1];
            }
            
            encontrado = 1;
            
            (*tamanho)--;
            listaAcom = (Acomodacao *)realloc(listaAcom, (*tamanho) * sizeof(Acomodacao));
            
            if (listaAcom == NULL) {
                printf("Erro na alocação da memória.");
            }
            
            break;
        }
    }
    
    if (encontrado == 0) {
        printf("Deleção não concluída. Acomodação não encontrada.");
    }
}