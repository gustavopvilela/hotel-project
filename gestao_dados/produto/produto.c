#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "produto.h"

void inserirProduto (Produto produto, int opcao) {
    switch (opcao) {
        case 1:
            FILE *produtoBin;
            produtoBin = fopen(PRODUTO_BIN, "ab");

            /* Verificação da abertura. */
            if(produtoBin == NULL){
                printf("Erro na abertura do arquivo.\n");
                exit(1);
            }

            /* Inserindo no arquivo binário. */
            if (!feof(produtoBin)) {
                fwrite(&produto, sizeof(Produto), 1, produtoBin);
            }
            else {
                printf("Arquivo cheio.\n");
                exit(1);
            }

            /*Fechando o arquivo*/
            fclose(produtoBin);
        break;
            
        case 2:
            FILE *produtoTxt;
            produtoTxt = fopen(PRODUTO_TXT, "a");
            
            /* Verificação da abertura. */
            if(produtoTxt == NULL){
                printf("Erro na abertura do arquivo.\n");
                exit(1);
            }
            
            /* Inserindo no arquivo de texto. */
            if (!feof(produtoTxt)) {
                fprintf(produtoTxt, "Código: %d\nDescrição: %s\nEstoque: %d\nEstoqueMinimo: %d\nPrecoCusto: %f\nPrecoVenda: %d\n",
                        produto.codigo, produto.descricao, produto.estoque,
                        produto.estoqueMin, produto.precoCusto, produto.precoVenda);
            }
            else {
                printf("Arquivo cheio.\n");
                exit(1);
            }

            fclose(produtoTxt);
        break;
    }
}

void inserirProdutoMemoria(Produto dados, Produto **listaProdutos, int *contador) {
    *listaProdutos = (Produto *)realloc(*listaProdutos, (*contador + 1) * sizeof(Produto));

    /* Caso o ponteiro retorne NULL, significa que já não há mais espaço. */
    if (*listaProdutos == NULL) {
        printf("Memória insuficiente!");
        exit(1);
    }

    (*listaProdutos)[*contador] = dados;
    (*contador)++;
}

void lerProduto (int codigo, int opcao) {
    Produto produto;
    int encontrado = 0;
    
    switch (opcao) {
        case 1:
            FILE *produtoBin;
            produtoBin = fopen(PRODUTO_BIN, "rb");

            /* Verificação da abertura. */
            if(produtoBin == NULL){
                printf("Erro na abertura do arquivo.\n");
                exit(1);
            }


            rewind(produtoBin);

            while (fread(&produto, sizeof(Produto), 1, produtoBin) == 1) {
                if (produto.codigo == codigo) {
                    printf("Código: %d\n", produto.codigo);
                    printf("Descrição: %s\n", produto.descricao);
                    printf("Estoque: %d\n", produto.estoque);
                    printf("Estoque mínimo: %d\n", produto.estoqueMin);
                    printf("Preço de custo: %.2f\n", produto.precoCusto);
                    printf("Preço de venda: %.2f\n", produto.precoVenda);
                    printf("\n");
                    encontrado = 1;
                }
            }
            if (!encontrado) {
                printf("Produto com código %d não encontrado.\n", codigo);
            }
            
            fclose(produtoBin);
            
            return encontrado;
        break;
            
        case 2:
            FILE *produtoTxt;
            produtoTxt = fopen(PRODUTO_TXT, "r");

            /* Verificação da abertura. */
            if (produtoTxt == NULL) {
                printf("Erro na abertura do arquivo.\n");
                exit(1);
            }
            
            rewind(produtoTxt);
            while (fscanf(produtoTxt, "%*s %d\n%*s %[^\n]\n%*s %d\n%*s %d\n%*s %f\n%*s %f",
                          &produto.codigo, produto.descricao, &produto.estoque,
                          &produto.estoqueMin, &produto.precoCusto, &produto.precoVenda) == 6) {
                if (produto.codigo == codigo) {
                    printf("Código: %d\n", produto.codigo);
                    printf("Descrição: %s\n", produto.descricao);
                    printf("Estoque: %d\n", produto.estoque);
                    printf("Estoque mínimo: %d\n", produto.estoqueMin);
                    printf("Preço de custo: %.2f\n", produto.precoCusto);
                    printf("Preço de venda: %.2f\n", produto.precoVenda);
                    printf("\n");
                    
                    encontrado = 1;
                }
            }
            if (!encontrado) {
                printf("Produto com código %d não encontrado.\n", codigo);
            }
            
            fclose(produtoTxt);
            
            return encontrado;
        break;
    }
}

int produtoExiste (int codigo, int opcao) {
    Produto produto;
    int encontrado = 0;
    
    switch (opcao) {
        case 1:
            FILE *produtoBin;
            produtoBin = fopen(PRODUTO_BIN, "rb");

            /* Verificação da abertura. */
            if(produtoBin == NULL){
                printf("Erro na abertura do arquivo.\n");
                exit(1);
            }


            rewind(produtoBin);

            while (fread(&produto, sizeof(Produto), 1, produtoBin) == 1) {
                if (produto.codigo == codigo) {
                    encontrado = 1;
                }
            }
            fclose(produtoBin);
            
            return encontrado;
        break;
            
        case 2:
            FILE *produtoTxt;
            produtoTxt = fopen(PRODUTO_TXT, "r");

            /* Verificação da abertura. */
            if (produtoTxt == NULL) {
                printf("Erro na abertura do arquivo.\n");
                exit(1);
            }
            
            rewind(produtoTxt);
            while (fscanf(produtoTxt, "%*s %d\n%*s %[^\n]\n%*s %d\n%*s %d\n%*s %f\n%*s %f",
                          &produto.codigo, produto.descricao, &produto.estoque,
                          &produto.estoqueMin, &produto.precoCusto, &produto.precoVenda) == 6) {
                if (produto.codigo == codigo) {
                    encontrado = 1;
                }
            }
            
            fclose(produtoTxt);
            
            return encontrado;
        break;
    }
}

void lerProdutoMemoria(Produto *listaProdutos, int tamanho, int codigo) {
    for (int i = 0; i < tamanho; i++) {
        if (listaProdutos[i].codigo == codigo) {
            printf("Código: %d\n", listaProdutos[i].codigo);
            printf("Descrição: %s\n", listaProdutos[i].descricao);
            printf("Estoque: %d\n", listaProdutos[i].estoque);
            printf("Estoque mínimo: %d\n", listaProdutos[i].estoqueMin);
            printf("Preço de custo: %.2f\n", listaProdutos[i].precoCusto);
            printf("Preço de venda: %.2f\n", listaProdutos[i].precoVenda);
            printf("\n");
        }
    }
}

int produtoExisteMemoria (Produto *listaProdutos, int tamanho, int codigo) {
    int encontrado = 0;
    
    for (int i = 0; i < tamanho; i++) {
        if (listaProdutos[i].codigo == codigo) {
            encontrado = 1;
        }
    }
    
    return encontrado;
}

void listarProdutos(int opcao) {
    Produto produto;
    
    switch (opcao) {
        case 1:
            FILE *produtoBin;
            produtoBin = fopen(PRODUTO_BIN, "rb");

            rewind(produtoBin);

            while (fread(&produto, sizeof(Produto), 1, produtoBin) == 1) {
                printf("Código: %d\n", produto.codigo);
                printf("Descrição: %s\n", produto.descricao);
                printf("Estoque: %d\n", produto.estoque);
                printf("Estoque mínimo: %d\n", produto.estoqueMin);
                printf("Preço de custo: %.2f\n", produto.precoCusto);
                printf("Preço de venda: %.2f\n", produto.precoVenda);
                printf("\n");
            }

            fclose(produtoBin);
        break;
            
        case 2:
            FILE *produtoTxt;
            produtoTxt = fopen(PRODUTO_TXT, "r");

            /* Verificação da abertura. */
            if (produtoTxt == NULL) {
                printf("Erro na abertura do arquivo.\n");
                exit(1);
            }
            
            rewind(produtoTxt);
            while (fscanf(produtoTxt, "%*s %d\n%*s %[^\n]\n%*s %d\n%*s %d\n%*s %f\n%*s %f",
                          &produto.codigo, produto.descricao, &produto.estoque,
                          &produto.estoqueMin, &produto.precoCusto, &produto.precoVenda) == 6) {
                printf("Código: %d\n", produto.codigo);
                printf("Descrição: %s\n", produto.descricao);
                printf("Estoque: %d\n", produto.estoque);
                printf("Estoque mínimo: %d\n", produto.estoqueMin);
                printf("Preço de custo: %.2f\n", produto.precoCusto);
                printf("Preço de venda: %.2f\n", produto.precoVenda);
                printf("\n");
            }
            
            fclose(produtoTxt);
        break;
    }
}

void listarProdutosMemoria(Produto *listaProdutos, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("Código: %d\n", listaProdutos[i].codigo);
        printf("Descrição: %s\n", listaProdutos[i].descricao);
        printf("Estoque: %d\n", listaProdutos[i].estoque);
        printf("Estoque mínimo: %d\n", listaProdutos[i].estoqueMin);
        printf("Preço de custo: %.2f\n", listaProdutos[i].precoCusto);
        printf("Preço de venda: %.2f\n", listaProdutos[i].precoVenda);
        printf("\n");
    }
}

void atualizarProduto (Produto novosDados, int codigo, int opcao) {
    switch (opcao) {
        case 1:
            if (produtoExiste(codigo, opcao) != 0) {
                deletarProduto(codigo, opcao);

                FILE *produtoBin;
                produtoBin = fopen(PRODUTO_BIN, "ab");

                /* Verificação da abertura. */
                if(produtoBin == NULL){
                    printf("Erro na abertura do arquivo.\n");
                    exit(1);
                }

                fwrite(&novosDados, sizeof(Produto), 1, produtoBin);
                printf("Atualizado o produto de código %d.", codigo);

                fclose(produtoBin);
            }
            else {
                printf("Produto de código %d não encontrado.", codigo);
            }
        break;
            
        case 2:
            if (produtoExiste(codigo, opcao) != 0) {
                /* Deletando os dados antigos. */
                deletarProduto(codigo, opcao);
                
                /* Atualizando o hóspede. */
                inserirProduto(novosDados, opcao);
                
                printf("Atualizada a produto de código %d.", codigo);
            }
            else {
                printf("Produto de código %d não encontrado.", codigo);
            }
        break;
    }
    
}

void atualizarProdutoMemoria (Produto *listaProdutos, Produto novosDados, int codigo, int tamanho) {
    int encontrado = 0;
    
    for (int i = 0; i < tamanho; i++) {
        if (listaProdutos[i].codigo == codigo) {
            listaProdutos[i] = novosDados;
            encontrado = 1;
            break;
        }
    }
    
    if (encontrado == 0) {
        printf("Produto não encontrado!");
    }
}

void deletarProduto(int codigo, int opcao) {
    int dadoAchado = 0;
    Produto produto;
    
    switch (opcao) {
        case 1:
            FILE *produtoBin;
            produtoBin = fopen(PRODUTO_BIN, "rb");

            /* Verificação da abertura. */
            if(produtoBin == NULL){
                printf("Erro na abertura do arquivo.\n");
                exit(1);
            }

            FILE *produtoBin_tmp;
            produtoBin_tmp = fopen(PRODUTO_TMP_BIN, "wb");

            /* Verificação da abertura. */
            if(produtoBin_tmp == NULL){
                printf("Erro na abertura do arquivo.\n");
                exit(1);
            }

            rewind(produtoBin);
            while (fread(&produto, sizeof(Produto), 1, produtoBin) == 1) {
                if (produto.codigo == codigo) {
                    printf("Deleção concluída!");
                    dadoAchado = 1;
                }
                else {
                    fwrite(&produto, sizeof(Produto), 1, produtoBin_tmp);
                }
            }

            if (dadoAchado == 0) {
                printf("Nenhum produto foi encontrado com este código: %d.\n", codigo);
            }

            fclose(produtoBin);
            fclose(produtoBin_tmp);

            remove(PRODUTO_BIN);
            rename(PRODUTO_TMP_BIN, PRODUTO_BIN);
        break;
            
        case 2:
            FILE *produtoTxt;
            produtoTxt = fopen(PRODUTO_TXT, "r");

            /* Verificação da abertura. */
            if (produtoTxt == NULL) {
                printf("Erro na abertura do arquivo.\n");
                exit(1);
            }

            FILE *produtoTxt_tmp;
            produtoTxt_tmp = fopen(PRODUTO_TMP_TXT, "w");

            /* Verificação da abertura. */
            if (produtoTxt_tmp == NULL) {
                printf("Erro na abertura do arquivo.\n");
                exit(1);
            }
            
            rewind(produtoTxt);
            while (fscanf(produtoTxt, "%*s %d\n%*s %[^\n]\n%*s %d\n%*s %d\n%*s %f\n%*s %f",
                          &produto.codigo, produto.descricao, &produto.estoque,
                          &produto.estoqueMin, &produto.precoCusto, &produto.precoVenda) == 6) {
                if (produto.codigo == codigo) {
                    printf("Deleção concluída!");
                    dadoAchado = 1;
                } else {
                    fprintf(produtoTxt, "Código: %d\nDescrição: %s\nEstoque: %d\nEstoqueMinimo: %d\nPrecoCusto: %f\nPrecoVenda: %d\n",
                        produto.codigo, produto.descricao, produto.estoque,
                        produto.estoqueMin, produto.precoCusto, produto.precoVenda);
                }
            }

            if (dadoAchado == 0) {
                printf("Nenhum produto foi encontrado com este código: %d.\n", codigo);
            }

            fclose(produtoTxt);
            fclose(produtoTxt_tmp);

            remove(PRODUTO_TXT);
            rename(PRODUTO_TMP_TXT, PRODUTO_TXT);
        break;
    }
   
    
   
}

void deletarProdutoMemoria (Produto *listaProdutos, int *tamanho, int codigo) {
    int encontrado = 0;
    
    for (int i = 0; i < *tamanho; i++) {
        if (listaProdutos[i].codigo == codigo) {
            for (int j = i; j < (*tamanho) - 1; j++) {
                (listaProdutos)[j] = (listaProdutos)[j+1];
            }
            
            encontrado = 1;
            
            (*tamanho)--;
            listaProdutos = (Produto *)realloc(listaProdutos, (*tamanho) * sizeof(Produto));
            
            if (listaProdutos == NULL) {
                printf("Erro na alocação da memória.");
            }
            
            break;
        }
    }
    
    if (encontrado == 0) {
        printf("Deleção não concluída. Produto não encontrado.");
    }
}