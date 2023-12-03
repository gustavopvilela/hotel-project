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
    
    /* Primeiro, calculamos o total da venda feita para o hóspede. */
    for (int i = 0; i < qtdeProdutos; i++) {
        produtoAtual = retornarProduto(produtos[i], opcao);
        total += produtoAtual.precoVenda;

        /* Aqui, a quantidade em estoque do produto é decrementada. */
        produtoAtual.estoque--;
    }
    
    switch (opcao) {
        case 1:
            /* Pegando o montante atual do caixa. */
            caixa.montante = retornarMontanteCaixa(opcao);

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
        case 2:
            /* Pegando o montante atual do caixa. */
            caixa.montante = retornarMontanteCaixa(opcao);

            /* Agora, escrevendo o novo montante no arquivo. */
            caixa.montante += total;

            FILE* caixaTxt;
            caixaTxt = fopen(CAIXA_TXT, "w");
            if (caixaBin == NULL) {
                printf("Erro na abertura do arquivo.");
                exit(1);
            }

            fprintf(caixaTxt, "Montante: %f\n", caixa.montante);
            
            /* Agora, colocando o lançamento do caixa no arquivo de lançamentos. */
            inserirLancamento(total, "Venda de produto", opcao);

            fclose(caixaTxt);
        break;
    }
}

void inserirVendaAnotar (int codigoHospede, int *produtos, int qtdeProdutos, int opcao) {
    float total = 0;
    ContaHospede conta;
    Produto produtoAtual;
    
    /* Primeiro, calculamos o total da venda feita para o hóspede. */
    for (int i = 0; i < qtdeProdutos; i++) {
        produtoAtual = retornarProduto(produtos[i], opcao);
        total += produtoAtual.precoVenda;

        /* Aqui, a quantidade em estoque do produto é decrementada. */
        produtoAtual.estoque--;
    }
    
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
        case 2:
            FILE *arqContaTxt = fopen(CONTA_HOSPEDE_TXT, "r");
            if (arqContaTxt == NULL) {
                printf("Erro na abertura do arquivo.");
                exit(1);
            }

            FILE *arqContaTxt_tmp = fopen(CONTA_HOSPEDE_TMP_TXT, "w");
            if (arqContaTxt_tmp == NULL) {
                printf("Erro na abertura do arquivo.");
                exit(1);
            }
            
            /* Agora, adicionamos à conta do hóspede. Fazemos isso */
            rewind(arqContaTxt);
            while (fscanf(arqContaTxt, "%*s %d\n%*s %d\n%*s %f\n%*s %f", &conta.codigoConta, &conta.codigoHospede, &conta.totalDiarias, &conta.totalConsumo) == 4) {
                if (conta.codigoHospede != codigoHospede) {
                    fprintf(arqContaTxt_tmp, "CódigoConta: %d\nCódigoHospede: %d\nTotalDiárias: %.2f\nTotalConsumo: %.2f\n", conta.codigoConta, conta.codigoHospede, conta.totalDiarias, conta.totalConsumo);
                }
                else {
                    conta.totalConsumo += total;
                    
                    fprintf(arqContaTxt_tmp, "CódigoConta: %d\nCódigoHospede: %d\nTotalDiárias: %.2f\nTotalConsumo: %.2f\n", conta.codigoConta, conta.codigoHospede, conta.totalDiarias, conta.totalConsumo);
                }
            }
            
            fclose(arqContaTxt);
            fclose(arqContaTxt_tmp);
            
            remove(CONTA_HOSPEDE_TXT);
            rename(CONTA_HOSPEDE_TMP_TXT, CONTA_HOSPEDE_TXT);
        break;
    }
}

void gerarNota (int *produtos, int qtdeProdutos, int opcao) {
    char* nota = "";
    char* temp;
    Produto produtoAtual;
    float total = 0;
    
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
}