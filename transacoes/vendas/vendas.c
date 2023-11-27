#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "vendas.h"
#include "../checkout/checkout.h"
#include "../controle_caixa/caixa/caixa.h"
#include "../../gestao_dados/produto/produto.h"

void inserirVendaAVista (int *produtos, int qtdeProdutos, int opcao) {
    /* A venda à vista não precisa do código do hóspede, uma vez que o
     * dinheiro vai direto para o caixa do hotel. */
    
    float total = 0;
    Caixa caixa;
    Produto produtoAtual;
    
    switch (opcao) {
        case 1:
            /* Primeiro, calculamos o total da venda feita para o hóspede. */
            for (int i = 0; i < qtdeProdutos; i++) {
                produtoAtual = retornarProduto(produtos[i], opcao);
                total += produtoAtual.precoVenda;

                /* Aqui, a quantidade em estoque do produto é decrementada. */
                produtoAtual.estoque--;
            }

            /* Pegando o montante atual do caixa.
            FILE* caixaBin;
            caixaBin = fopen(CAIXA_BIN, "rb");
            if (caixaBin == NULL) {
                printf("Erro na abertura do arquivo.");
                exit(1);
            }

            rewind(caixaBin);
            fread(&caixa, sizeof(Caixa), 1, caixaBin);

            fclose(caixaBin); */
            
            /* Pegando o montante atual do caixa. */
            caixa.montante = retornarMontanteCaixa();

            /* Agora, escrevendo o novo montante no arquivo. */
            caixa.montante += total;

            FILE* caixaBin;
            caixaBin = fopen(CAIXA_BIN, "wb");
            if (caixaBin == NULL) {
                printf("Erro na abertura do arquivo.");
                exit(1);
            }

            fwrite(&caixa, sizeof(Caixa), 1, caixaBin);
            
            /* Agora, colocando o lançamento do caixa no arquivo de lançamentos. */
            inserirLancamento(total, "Venda de produto", opcao);

            fclose(caixaBin);
        break;
        case 2: break;
    }
}

void inserirVendaAnotar (int codigoHospede, int *produtos, int qtdeProdutos, int opcao) {
    float total = 0;
    ContaHospede conta;
    Produto produtoAtual;
    
    switch (opcao) {
        case 1:
            /* Abrindo o arquivo da conta do hóspede. */
            FILE *arqConta;
            arqConta = fopen(CONTA_HOSPEDE_BIN, "rb");
            if (arqConta == NULL) {
                printf("Erro na abertura do arquivo.");
                exit(1);
            }
            
            FILE *arqConta_tmp;
            arqConta_tmp = fopen(CONTA_HOSPEDE_TMP_BIN, "ab");
            if (arqConta_tmp == NULL) {
                printf("Erro na abertura do arquivo.");
                exit(1);
            }
            
            /* Primeiro, calculamos o total da venda feita para o hóspede. */
            for (int i = 0; i < qtdeProdutos; i++) {
                produtoAtual = retornarProduto(produtos[i], opcao);
                total += produtoAtual.precoVenda;
                
                /* Aqui, a quantidade em estoque do produto é decrementada. */
                produtoAtual.estoque--;
            }
            
            /* Agora, adicionamos à conta do hóspede. Fazemos isso */
            rewind(arqConta);
            while (fread(&conta, sizeof(ContaHospede), 1, arqConta) == 1) {
                if (conta.codigoHospede != codigoHospede) {
                    fwrite(&conta, sizeof(ContaHospede), 1, arqConta_tmp);
                }
                else {
                    conta.totalConsumo += total;
                    
                    fwrite(&conta, sizeof(ContaHospede), 1, arqConta_tmp);
                }
            }
            
            fclose(arqConta);
            fclose(arqConta_tmp);
            
            remove(CONTA_HOSPEDE_BIN);
            rename(CONTA_HOSPEDE_TMP_BIN, CONTA_HOSPEDE_BIN);
        break;
        case 2: break;
    }
}

void gerarNota (int *produtos, int qtdeProdutos, int opcao) {
    char* nota = "";
    char* temp;
    Produto produtoAtual;
    float total = 0;
    
    switch (opcao) {
        case 1:
            strcat(nota, "PRODUTO | PREÇO UNITÁRIO\n")
            
            for (int i = 0; i < qtdeProdutos; i++) {
                produtoAtual = retornarProduto(produtos[i], opcao);
                
                strcpy(temp, "");
                sprintf(temp, "%s | R$ %.2f\n", produtoAtual.descricao, produtoAtual.precoVenda);
                strcat(nota, temp);
                total += produtoAtual.precoVenda;
            }
            
            strcpy(temp, "");
            sprintf(temp, "TOTAL: R$ %.2f", total);
            strcat(nota, temp);
            
            printf("%s", nota);
        break;
        case 2: break;
    }
}

Produto retornarProduto (int codigo, int opcao) {
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
            
            rewind(produtoBin);

            while (fread(&produto, sizeof (Produto), 1, produtoBin) == 1) {
                if (produto.codigo == codigo) {
                    return produto;
                }
            }
            
            fclose(produtoBin);
        break;
        case 2: break;
    }
}

int existeContaHospede (int codigoHospede, int opcao) {
    ContaHospede conta;
    int encontrado = 0;
    
    switch (opcao) {
        case 1: 
            FILE *arqConta;
            arqConta = fopen(CONTA_HOSPEDE_BIN, "ab");
            if (arqConta == NULL) {
                printf("Erro na abertura do arquivo.");
                exit(1);
            }
            
            while (fread(&conta, sizeof(ContaHospede), 1, arqConta) == 1) {
                if (conta.codigoHospede == codigoHospede) {
                    encontrado = 1;
                    break;
                }
            }
            
            return encontrado;
        break;
        case 2: break;
    }
}