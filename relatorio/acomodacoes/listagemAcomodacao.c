#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "listagemAcomodacao.h"
#include "../../gestao_dados/acomodacao/acomodacao.h"

void listagemAcomodacoesCodigos(int codigo1, int codigo2, int formaArmazenamento, int opcaoRelatorio) {
    Acomodacao acomodacao;
    
    FILE *listAcomodacoesCodigo;
    switch (formaArmazenamento) {
        case 1:
            // binário
            FILE *acomodacaoBin;
            acomodacaoBin = fopen(ACOMODACAO_BIN, "rb");

            /* Verificação da abertura. */
            if (acomodacaoBin == NULL) {
                printf("Erro na abertura do arquivo.\n");
                exit(1);
            }

            // arquivo csv
            listAcomodacoesCodigo = fopen(ACOMODACOES_CODIGO_CSV, "w");
            for (int i = codigo1; i <= codigo2; i++) {
                rewind(acomodacaoBin);
                while (fread(&acomodacao, sizeof(Acomodacao), 1, acomodacaoBin) == 1) {
                    if (acomodacao.codigo == i) {
                        if (opcaoRelatorio == 1) {
                            // tela
                            printf("Código: %d\n", acomodacao.codigo);
                            printf("Descrição: %s\n", acomodacao.descricao);
                            printf("Facilidades: %d\n", acomodacao.facilidades);
                            printf("Categoria: %d\n", acomodacao.categoria);
                            printf("\n");
                        } else {

                            /* Verificação da abertura. */
                            if (listAcomodacoesCodigo == NULL) {
                                printf("Erro na abertura do arquivo.\n");
                                exit(1);
                            }

                            /* Inserindo no arquivo de texto. */
                            if (!feof(listAcomodacoesCodigo)) {
                                fprintf(listAcomodacoesCodigo, "%d;%s;%d;%d\n",
                                        acomodacao.codigo, acomodacao.descricao,
                                        acomodacao.facilidades, acomodacao.categoria);
                            } else {
                                printf("Arquivo cheio.\n");
                                exit(1);
                            }
                        }
                    }
                }
            }
            fclose(listAcomodacoesCodigo);
            fclose(acomodacaoBin);
            break;

        case 2:
            // txt
            FILE *acomodacaoTxt;
            acomodacaoTxt = fopen(ACOMODACAO_TXT, "r");

            /* Verificação da abertura. */
            if (acomodacaoTxt == NULL) {
                printf("Erro na abertura do arquivo.\n");
                exit(1);
            }

            rewind(acomodacaoTxt);

            // arquivo csv
            listAcomodacoesCodigo = fopen(ACOMODACOES_CODIGO_CSV, "w");
            for (int i = codigo1; i <= codigo2; i++) {
                /* %*s significa que a string lida será ignorada. */
                /* Iguala-se a 4 pois o fscanf deve fazer 4 "comparações" com sucesso para a leitura ser certa. */
                while (fscanf(acomodacaoTxt, "%*s %d\n%*s %[^\n]\n%*s %d\n%*s %d\n",
                              &acomodacao.codigo, acomodacao.descricao, &acomodacao.facilidades, &acomodacao.categoria) == 4) {

                    if (acomodacao.codigo == i) {
                        if (opcaoRelatorio == 1) {
                            // tela
                            printf("Código: %d\n", acomodacao.codigo);
                            printf("Descrição: %s\n", acomodacao.descricao);
                            printf("Facilidades: %d\n", acomodacao.facilidades);
                            printf("Categoria: %d\n", acomodacao.categoria);
                            printf("\n");
                        } else {

                            /* Verificação da abertura. */
                            if (listAcomodacoesCodigo == NULL) {
                                printf("Erro na abertura do arquivo.\n");
                                exit(1);
                            }

                            /* Inserindo no arquivo de texto. */
                            if (!feof(listAcomodacoesCodigo)) {
                                fprintf(listAcomodacoesCodigo, "%d;%s;%d;%d\n",
                                        acomodacao.codigo, acomodacao.descricao,
                                        acomodacao.facilidades, acomodacao.categoria);
                            } else {
                                printf("Arquivo cheio.\n");
                                exit(1);
                            }
                        }
                    }
                }
            }

            fclose(listAcomodacoesCodigo);
            fclose(acomodacaoTxt);
            break;
    }
}

void listagemAcomodacoesCategoria(int categoria, int formaArmazenamento, int opcaoRelatorio){
    Acomodacao acomodacao;
    FILE *listAcomodacoesCategoria;
    switch(formaArmazenamento){
        case 1:
            //binário
            FILE *acomodacaoBin;
            acomodacaoBin = fopen(ACOMODACAO_BIN, "rb");

            /* Verificação da abertura. */
            if(acomodacaoBin == NULL){
                printf("Erro na abertura do arquivo.\n");
                exit(1);
            }

            //arquivo csv
            listAcomodacoesCategoria = fopen(ACOMODACOES_CATEGORIA_CSV, "w");
            rewind(acomodacaoBin);
            while (fread(&acomodacao, sizeof(Acomodacao), 1, acomodacaoBin) == 1) {
                if (acomodacao.categoria == categoria) {
                    if(opcaoRelatorio == 1){
                        //tela
                        printf("Código: %d\n", acomodacao.codigo);
                        printf("Descrição: %s\n", acomodacao.descricao);
                        printf("Facilidades: %d\n", acomodacao.facilidades);
                        printf("Categoria: %d\n", acomodacao.categoria);
                        printf("\n");
                    }else{

                        /* Verificação da abertura. */
                        if(listAcomodacoesCategoria == NULL){
                            printf("Erro na abertura do arquivo.\n");
                            exit(1);
                        }

                        /* Inserindo no arquivo csv. */
                        if (!feof(listAcomodacoesCategoria)) {
                            fprintf(listAcomodacoesCategoria, "%d;%s;%d;%d\n",
                                    acomodacao.codigo, acomodacao.descricao, acomodacao.facilidades,
                                    acomodacao.categoria);
                        }
                        else {
                            printf("Arquivo cheio.\n");
                            exit(1);
                        }
                    }

                }
            }
            fclose(listAcomodacoesCategoria);
            fclose(acomodacaoBin);
        break;
        
        case 2:
            //txt
            FILE *acomodacaoTxt;
            acomodacaoTxt = fopen(ACOMODACAO_TXT, "r");
            
            /* Verificação da abertura. */
            if(acomodacaoTxt == NULL){
                printf("Erro na abertura do arquivo.\n");
                exit(1);
            }
            
            rewind(acomodacaoTxt);
            
            //arquivo csv
            listAcomodacoesCategoria = fopen(ACOMODACOES_CATEGORIA_CSV, "w");
            /* %*s significa que a string lida será ignorada. */
            /* Iguala-se a 4 pois o fscanf deve fazer 4 "comparações" com sucesso para a leitura ser certa. */
            while (fscanf(acomodacaoTxt, "%*s %d\n%*s %[^\n]\n%*s %d\n%*s %d",
                          &acomodacao.codigo, acomodacao.descricao, &acomodacao.facilidades, &acomodacao.categoria) == 4) {

                if (acomodacao.categoria == categoria) {
                    if(opcaoRelatorio == 1){
                        //tela
                        printf("Código: %d\n", acomodacao.codigo);
                        printf("Descrição: %s\n", acomodacao.descricao);
                        printf("Facilidades: %d\n", acomodacao.facilidades);
                        printf("Categoria: %d\n", acomodacao.categoria);
                        printf("\n");

                    }else{
                        /* Verificação da abertura. */
                        if(listAcomodacoesCategoria == NULL){
                            printf("Erro na abertura do arquivo.\n");
                            exit(1);
                        }

                        /* Inserindo no arquivo csv. */
                        if (!feof(listAcomodacoesCategoria)) {
                            fprintf(listAcomodacoesCategoria, "%d;%s;%d;%d\n",
                                    acomodacao.codigo, acomodacao.descricao, acomodacao.facilidades,
                                    acomodacao.categoria);
                        }
                        else {
                            printf("Arquivo cheio.\n");
                            exit(1);
                        }
                    }
                }
            }

            fclose(listAcomodacoesCategoria);
            fclose(acomodacaoTxt);
        break;
    }
}
