#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "listagemProdutosEstoqueMin.h"
#include "../../gestao_dados/produto/produto.h"

void listagemProdutosEstoqueMinCodigo(int codigo1, int codigo2, int formaArmazenamento, int opcaoRelatorio){
    Produto produto;
    
    FILE *listProdutosEstoqueMinCodigo;
    switch (formaArmazenamento) {
        case 1:
            // binário
            FILE *produtoBin;
            produtoBin = fopen(PRODUTO_BIN, "rb");

            /* Verificação da abertura. */
            if (produtoBin == NULL) {
                printf("Erro na abertura do arquivo.\n");
                exit(1);
            }

            // arquivo csv
            listProdutosEstoqueMinCodigo = fopen(PRODUTOS_ESTOQUE_MINIMO_CODIGO_CSV, "w");
            for (int i = codigo1; i <= codigo2; i++) {
                rewind(produtoBin);
                while (fread(&produto, sizeof(produto), 1, produtoBin) == 1) {
                    if (produto.codigo == i && produto.estoque >= produto.estoqueMin) {
                        if (opcaoRelatorio == 1) {
                            // tela
                            printf("Código: %d\n", produto.codigo);
                            printf("Descrição: %s\n", produto.descricao);
                            printf("Estoque: %d\n", produto.estoque);
                            printf("Estoque mínimo: %d\n", produto.estoqueMin);
                            printf("Preço de custo: %.2f\n", produto.precoCusto);
                            printf("Preço de venda: %.2f\n", produto.precoVenda);
                            printf("\n");
                        } else {

                            /* Verificação da abertura. */
                            if (listProdutosEstoqueMinCodigo == NULL) {
                                printf("Erro na abertura do arquivo.\n");
                                exit(1);
                            }

                            /* Inserindo no arquivo de texto. */
                            if (!feof(listProdutosEstoqueMinCodigo)) {
                                fprintf(listProdutosEstoqueMinCodigo, "%d;%s;%d;%d;%.2f;%.2f\n",
                                        produto.codigo, produto.descricao,
                                        produto.estoque, produto.estoqueMin,
                                        produto.precoCusto, produto.precoVenda);
                            } else {
                                printf("Arquivo cheio.\n");
                                exit(1);
                            }
                        }
                    }
                }
            }
            fclose(listProdutosEstoqueMinCodigo);
            fclose(produtoBin);
            break;

        case 2:
            // txt
            FILE *produtoTxt;
            produtoTxt = fopen(PRODUTO_TXT, "r");

            /* Verificação da abertura. */
            if (produtoTxt == NULL) {
                printf("Erro na abertura do arquivo.\n");
                exit(1);
            }

            
            // arquivo csv
            listProdutosEstoqueMinCodigo = fopen(PRODUTOS_ESTOQUE_MINIMO_CODIGO_CSV, "w");
            for (int i = codigo1; i <= codigo2; i++) {
                rewind(produtoTxt);
                /* %*s significa que a string lida será ignorada. */
                /* Iguala-se a 6 pois o fscanf deve fazer 6 "comparações" com sucesso para a leitura ser certa. */
                while (fscanf(produtoTxt, "%*s %d\n%*s %[^\n]\n%*s %d\n%*s %d\n%*s %f\n%*s %f",
                        &produto.codigo, produto.descricao, &produto.estoque,
                        &produto.estoqueMin, &produto.precoCusto, &produto.precoVenda) == 6) {
                  printf("Código lido: %d\n", produto.codigo);
                  printf("%d\n", i);
                    if (produto.codigo == i && produto.estoque >= produto.estoqueMin) {
                        printf("CHEGOU AQUI %d\n", i);
                        if (opcaoRelatorio == 1) {
                            // tela
                            printf("Código: %d\n", produto.codigo);
                            printf("Descrição: %s\n", produto.descricao);
                            printf("Estoque: %d\n", produto.estoque);
                            printf("Estoque mínimo: %d\n", produto.estoqueMin);
                            printf("Preço de custo: %.2f\n", produto.precoCusto);
                            printf("Preço de venda: %.2f\n", produto.precoVenda);
                            printf("\n");
                        } else if(opcaoRelatorio == 2){
                            
                            /* Verificação da abertura. */
                            if (listProdutosEstoqueMinCodigo == NULL) {
                                printf("Erro na abertura do arquivo.\n");
                                exit(1);
                            }
                            
                            /* Inserindo no arquivo de texto. */
                            if (!feof(listProdutosEstoqueMinCodigo)) {
                                fprintf(listProdutosEstoqueMinCodigo, "%d;%s;%d;%d;%.2f;%.2f\n",
                                        produto.codigo, produto.descricao,
                                        produto.estoque, produto.estoqueMin,
                                        produto.precoCusto, produto.precoVenda);
                            } else {
                                printf("Arquivo cheio.\n");
                                exit(1);
                            }
                        }
                    }
                }
            }

            fclose(listProdutosEstoqueMinCodigo);
            fclose(produtoTxt);
            break;
    }
}