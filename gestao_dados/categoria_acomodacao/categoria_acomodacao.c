#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "categoria_acomodacao.h"

void inserirCategoriaAcomodacao (CategoriaAcomodacao catAcom, int opcao) {
    switch (opcao) {
        case 1:
            FILE *catAcomBin;
            catAcomBin = fopen(CATACOM_BIN, "ab");

            /* Verificação da abertura. */
            if(catAcomBin == NULL){
                printf("Erro na abertura do arquivo.\n");
                exit(1);
            }

            /* Inserindo no arquivo binário. */
            if (!feof(catAcomBin)) {
                if (categoriaAcomodacaoExiste(catAcom.codigo, opcao) == 0) {
                    fwrite(&catAcom, sizeof(CategoriaAcomodacao), 1, catAcomBin);
                }
                else {
                    printf("Categoria de acomodação com este código já existente.");
                }

            }
            else {
                printf("Arquivo cheio.\n");
                exit(1);
            }

            /*Fechando o arquivo*/
            fclose(catAcomBin);
        break;
        
        case 2:
            FILE *catAcomTxt;
            catAcomTxt = fopen(CATACOM_TXT, "a");
            
            /* Verificação da abertura. */
            if(catAcomTxt == NULL){
                printf("Erro na abertura do arquivo.\n");
                exit(1);
            }
            
            /* Inserindo no arquivo de texto. */
            if (!feof(catAcomTxt)) {
                fprintf(catAcomTxt, "Código: %d\nDescrição: %s\nCategoria: %d\nDiaria: %f\nAdultos: %d\nCrianças: %d\n",
                        catAcom.codigo, catAcom.descricao, catAcom.categoria,
                        catAcom.valorDiaria, catAcom.qtdeAdultos, catAcom.qtdeCriancas);
            }
            else {
                printf("Arquivo cheio.\n");
                exit(1);
            }


            fclose(catAcomTxt);
        break;
    }
}

void inserirCategoriaAcomodacaoMemoria(CategoriaAcomodacao dados, CategoriaAcomodacao **listaCatAcom, int *contador) {
    *listaCatAcom = (CategoriaAcomodacao *)realloc(*listaCatAcom, (*contador + 1) * sizeof(CategoriaAcomodacao));

    /* Caso o ponteiro retorne NULL, significa que já não há mais espaço. */
    if (*listaCatAcom == NULL) {
        printf("Memória insuficiente!");
        exit(1);
    }

    (*listaCatAcom)[*contador] = dados;
    (*contador)++;
}

void lerCategoriaAcomodacao (int codigo, int opcao) {
    CategoriaAcomodacao catAcom;
    int encontrado = 0;
    
    switch (opcao) {
        case 1:
            FILE *catAcomBin;
            catAcomBin = fopen(CATACOM_BIN, "rb");

            /* Verificação da abertura. */
            if(catAcomBin == NULL){
                printf("Erro na abertura do arquivo.\n");
                exit(1);
            }

            rewind(catAcomBin);

            while (fread(&catAcom, sizeof(CategoriaAcomodacao), 1, catAcomBin) == 1) {
                if (catAcom.codigo == codigo) {
                    printf("Código: %d\n", catAcom.codigo);
                    printf("Descrição: %s\n", catAcom.descricao);
                    printf("Categoria: %d\n", catAcom.categoria);
                    printf("Valor da diária: %f\n", catAcom.valorDiaria);
                    printf("Quantidade de adultos: %d\n", catAcom.qtdeAdultos);
                    printf("Quantidade de crianças: %d\n", catAcom.qtdeCriancas);
                    printf("\n");
                    encontrado = 1;
                }
            }
            if (!encontrado) {
                printf("Categoria de acomodação com código %d não encontrado.\n", codigo);
            }

            /*Fechando o arquivo*/
            fclose(catAcomBin);
        break;
            
        case 2:
            FILE *catAcomTxt;
            catAcomTxt = fopen(CATACOM_TXT, "r");

            /* Verificação da abertura. */
            if (catAcomTxt == NULL) {
                printf("Erro na abertura do arquivo.\n");
                exit(1);
            }
            
            rewind(catAcomTxt);
            while (fscanf(catAcomTxt, "%*s %d\n%*s %[^\n]\n%*s %d\n%*s %f\n%*s %d\n%*s %d",
                          &catAcom.codigo, catAcom.descricao, &catAcom.categoria, &catAcom.valorDiaria, &catAcom.qtdeAdultos, &catAcom.qtdeCriancas) == 6) {
                if (catAcom.codigo == codigo) {
                    printf("Código: %d\n", catAcom.codigo);
                    printf("Descrição: %s\n", catAcom.descricao);
                    printf("Categoria: %d\n", catAcom.categoria);
                    printf("Valor da diária: %f\n", catAcom.valorDiaria);
                    printf("Quantidade de adultos: %d\n", catAcom.qtdeAdultos);
                    printf("Quantidade de crianças: %d\n", catAcom.qtdeCriancas);
                    printf("\n");
                    
                    encontrado = 1;
                }
            }
            if (!encontrado) {
                printf("Categoria de acomodação com código %d não encontrado.\n", codigo);
            }
            
            fclose(catAcomTxt);
        break;
    }
}

int categoriaAcomodacaoExiste (int codigo, int opcao) {
    CategoriaAcomodacao catAcom;
    int encontrado = 0;
    
    switch (opcao) {
        case 1:
            FILE *catAcomBin;
            catAcomBin = fopen(CATACOM_BIN, "rb");

            /* Verificação da abertura. */
            if(catAcomBin == NULL){
                printf("Erro na abertura do arquivo.\n");
                exit(1);
            }

            rewind(catAcomBin);

            while (fread(&catAcom, sizeof(CategoriaAcomodacao), 1, catAcomBin) == 1) {
                if (catAcom.codigo == codigo) {
                    encontrado = 1;
                }
            }

            /*Fechando o arquivo*/
            fclose(catAcomBin);
            
            return encontrado;
        break;
            
        case 2:
            FILE *catAcomTxt;
            catAcomTxt = fopen(CATACOM_TXT, "r");

            /* Verificação da abertura. */
            if (catAcomTxt == NULL) {
                printf("Erro na abertura do arquivo.\n");
                exit(1);
            }
            
            rewind(catAcomTxt);
            while (fscanf(catAcomTxt, "%*s %d\n%*s %[^\n]\n%*s %d\n%*s %f\n%*s %d\n%*s %d",
                          &catAcom.codigo, catAcom.descricao, &catAcom.categoria, &catAcom.valorDiaria, &catAcom.qtdeAdultos, &catAcom.qtdeCriancas) == 6) {
                if (catAcom.codigo == codigo) {
                    encontrado = 1;
                }
            }
            
            fclose(catAcomTxt);
            
            return encontrado;
        break;
    }
}

void lerCategoriaAcomodacaoMemoria(CategoriaAcomodacao *listaCatAcom, int tamanho, int codigo) {
    for (int i = 0; i < tamanho; i++) {
        if (listaCatAcom[i].codigo == codigo) {
            printf("Código: %d\n", listaCatAcom[i].codigo);
            printf("Descrição: %s\n", listaCatAcom[i].descricao);
            printf("Categoria: %d\n", listaCatAcom[i].categoria);
            printf("Valor da diária: %f\n", listaCatAcom[i].valorDiaria);
            printf("Quantidade de adultos: %d\n", listaCatAcom[i].qtdeAdultos);
            printf("Quantidade de crianças: %d\n", listaCatAcom[i].qtdeCriancas);
            printf("\n");
        }
    }
}

int categoriaAcomodacaoExisteMemoria(CategoriaAcomodacao *listaCatAcom, int tamanho, int codigo) {
    int encontrado = 0;
    
    for (int i = 0; i < tamanho; i++) {
        if (listaCatAcom[i].codigo == codigo) {
            encontrado = 1;
        }
    }
    
    return encontrado;
}

void listarCategoriaAcomodacao (int opcao) {
    CategoriaAcomodacao catAcom;
    
    switch (opcao) {
        case 1:
            FILE *catAcomBin;
            catAcomBin = fopen(CATACOM_BIN, "rb");

            /* Verificação da abertura. */
            if(catAcomBin == NULL){
                printf("Erro na abertura do arquivo.\n");
                exit(1);
            }

            rewind(catAcomBin);
            while (fread(&catAcom, sizeof(CategoriaAcomodacao), 1, catAcomBin) == 1) {
                printf("Código: %d\n", catAcom.codigo);
                printf("Descrição: %s\n", catAcom.descricao);
                printf("Categoria: %d\n", catAcom.categoria);
                printf("Valor da diária: %f\n", catAcom.valorDiaria);
                printf("Quantidade de adultos: %d\n", catAcom.qtdeAdultos);
                printf("Quantidade de crianças: %d\n", catAcom.qtdeCriancas);
                printf("\n");
            }

            fclose(catAcomBin);
        break;
            
        case 2:
            FILE *catAcomTxt;
            catAcomTxt = fopen(CATACOM_TXT, "r");

            /* Verificação da abertura. */
            if (catAcomTxt == NULL) {
                printf("Erro na abertura do arquivo.\n");
                exit(1);
            }
            
            rewind(catAcomTxt);
            while (fscanf(catAcomTxt, "%*s %d\n%*s %[^\n]\n%*s %d\n%*s %f\n%*s %d\n%*s %d",
                          &catAcom.codigo, catAcom.descricao, &catAcom.categoria, &catAcom.valorDiaria, &catAcom.qtdeAdultos, &catAcom.qtdeCriancas) == 6) {
                printf("Código: %d\n", catAcom.codigo);
                printf("Descrição: %s\n", catAcom.descricao);
                printf("Categoria: %d\n", catAcom.categoria);
                printf("Valor da diária: %f\n", catAcom.valorDiaria);
                printf("Quantidade de adultos: %d\n", catAcom.qtdeAdultos);
                printf("Quantidade de crianças: %d\n", catAcom.qtdeCriancas);
                printf("\n");
            }
            
            fclose(catAcomTxt);
        break;
    }
}

void listarCategoriaAcomodacaoMemoria (CategoriaAcomodacao *listaCatAcom, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("Código: %d\n", listaCatAcom[i].codigo);
        printf("Descrição: %s\n", listaCatAcom[i].descricao);
        printf("Categoria: %d\n", listaCatAcom[i].categoria);
        printf("Valor da diária: %f\n", listaCatAcom[i].valorDiaria);
        printf("Quantidade de adultos: %d\n", listaCatAcom[i].qtdeAdultos);
        printf("Quantidade de crianças: %d\n", listaCatAcom[i].qtdeCriancas);
        printf("\n");
    }
}

void atualizarCategoriaAcomodacao (CategoriaAcomodacao novosDados, int codigo, int opcao) {
    switch (opcao) {
        case 1:
            if (categoriaAcomodacaoExiste(codigo, opcao) != 0) {
               deletarCategoriaAcomodacao(codigo, opcao);

               FILE *catAcomBin;
               catAcomBin = fopen(CATACOM_BIN, "ab");

               /* Verificação da abertura. */
               if(catAcomBin == NULL){
                   printf("Erro na abertura do arquivo.\n");
                   exit(1);
               }

               fwrite(&novosDados, sizeof(CategoriaAcomodacao), 1, catAcomBin);
               printf("Atualizado a categoria de acomodação de código %d.", codigo);

               fclose(catAcomBin);
            }
            else {
                printf("Categoria de acomodacao de código %d não encontrado.", codigo);
            }
        break;
            
        case 2:
            if (categoriaAcomodacaoExiste(codigo, opcao) != 0) {
                /* Deletando os dados antigos. */
                deletarCategoriaAcomodacao(codigo, opcao);
                
                /* Atualizando o hóspede. */
                inserirCategoriaAcomodacao(novosDados, opcao);
                
                printf("Atualizada a categoria de acomodação de código %d.", codigo);
            }
            else {
                printf("Categoria de acomodação de código %d não encontrado.", codigo);
            }
        break;
    }
}

void atualizarCategoriaAcomodacaoMemoria (CategoriaAcomodacao *listaCatAcom, CategoriaAcomodacao novosDados, int codigo, int tamanho) {
    int encontrado = 0;
    
    for (int i = 0; i < tamanho; i++) {
        if (listaCatAcom[i].codigo == codigo) {
            listaCatAcom[i] = novosDados;
            encontrado = 1;
            break;
        }
    }
    
    if (encontrado == 0) {
        printf("Categoria de acomodação não encontrada!");
    }
}

void deletarCategoriaAcomodacao (int codigo, int opcao) {
    int dadoAchado = 0;
    CategoriaAcomodacao catAcom;
    
    switch (opcao) {
        case 1:
            FILE *catAcomBin;
            catAcomBin = fopen(CATACOM_BIN, "rb");

            /* Verificação da abertura. */
            if(catAcomBin == NULL){
                printf("Erro na abertura do arquivo.\n");
                exit(1);
            }

            FILE *catAcomBin_tmp;
            catAcomBin_tmp = fopen(CATACOM_TMP_BIN, "wb");

            /* Verificação da abertura. */
            if(catAcomBin_tmp == NULL){
                printf("Erro na abertura do arquivo.\n");
                exit(1);
            }

            rewind(catAcomBin);
            while (fread(&catAcom, sizeof(CategoriaAcomodacao), 1, catAcomBin) == 1) {
                if (catAcom.codigo == codigo) {
                    printf("Deleção concluída!");
                    dadoAchado = 1;
                }
                else {
                    fwrite(&catAcom, sizeof(CategoriaAcomodacao), 1, catAcomBin_tmp);
                }
            }

            if (dadoAchado == 0) {
                printf("Nenhuma categoria de acomodação foi encontrada com este código: %d.\n", codigo);
            }

            fclose(catAcomBin);
            fclose(catAcomBin_tmp);

            remove(CATACOM_BIN);
            rename(CATACOM_TMP_BIN, CATACOM_BIN);
        break;
            
        case 2:
            FILE *catAcomTxt;
            catAcomTxt = fopen(CATACOM_TXT, "r");

            /* Verificação da abertura. */
            if (catAcomTxt == NULL) {
                printf("Erro na abertura do arquivo.\n");
                exit(1);
            }

            FILE *catAcomTxt_tmp;
            catAcomTxt_tmp = fopen(CATACOM_TMP_TXT, "w");

            /* Verificação da abertura. */
            if (catAcomTxt_tmp == NULL) {
                printf("Erro na abertura do arquivo.\n");
                exit(1);
            }
            
            rewind(catAcomTxt);
            while (fscanf(catAcomTxt, "%*s %d\n%*s %[^\n]\n%*s %d\n%*s %f\n%*s %d\n%*s %d",
                          &catAcom.codigo, catAcom.descricao, &catAcom.categoria, &catAcom.valorDiaria, &catAcom.qtdeAdultos, &catAcom.qtdeCriancas) == 6) {
                if (catAcom.codigo == codigo) {
                    printf("Deleção concluída!");
                    dadoAchado = 1;
                } else {
                    fprintf(catAcomTxt, "Código: %d\nDescrição: %s\nCategoria: %d\nDiaria: %f\nAdultos: %d\nCrianças: %d\n",
                        catAcom.codigo, catAcom.descricao, catAcom.categoria,
                        catAcom.valorDiaria, catAcom.qtdeAdultos, catAcom.qtdeCriancas);
                }
            }

            if (dadoAchado == 0) {
                printf("Nenhuma categoria de acomodação foi encontrada com este código: %d.\n", codigo);
            }

            fclose(catAcomTxt);
            fclose(catAcomTxt_tmp);

            remove(CATACOM_TXT);
            rename(CATACOM_TMP_TXT, CATACOM_TXT);
        break;
    }
}

void deletarCategoriaAcomodacaoMemoria (CategoriaAcomodacao *listaCatAcom, int *tamanho, int codigo) {
    int encontrado = 0;
    
    for (int i = 0; i < *tamanho; i++) {
        if (listaCatAcom[i].codigo == codigo) {
            for (int j = i; j < (*tamanho) - 1; j++) {
                (listaCatAcom)[j] = (listaCatAcom)[j+1];
            }
            
            encontrado = 1;
            
            (*tamanho)--;
            listaCatAcom = (CategoriaAcomodacao *)realloc(listaCatAcom, (*tamanho) * sizeof(CategoriaAcomodacao));
            
            if (listaCatAcom == NULL) {
                printf("Erro na alocação da memória.");
            }
            
            break;
        }
    }
    
    if (encontrado == 0) {
        printf("Deleção não concluída. Categoria de acomodação não encontrada não encontrada.");
    }
}