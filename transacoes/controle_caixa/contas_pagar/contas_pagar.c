#include <stdlib.h>
#include <stdio.h>

#include "../caixa/caixa.h"
#include "contas_pagar.h"

void baixarRetirada (int opcao) {
    /* Nesta função, quando chamada, baixará os recebimentos pendentes do 
     * hotel, colocando-os no caixa. */
    
    int diaAtual = retornarDiaAtual();
    int mesAtual = retornarMesAtual();
    int anoAtual = retornarAnoAtual();
    float totalRetirada = 0;
    ContasPagar contasPagar;
    Caixa caixa;
    
    switch (opcao) {
        case 1:
            FILE* contasPagarBin;
            contasPagarBin = fopen(CONTAS_PAGAR_BIN, "rb");
            if (contasPagarBin == NULL) {
                printf("Erro na abertura do arquivo.");
                exit(1);
            }
            
            FILE* contasPagarBin_tmp;
            contasPagarBin_tmp = fopen(CONTAS_PAGAR_TMP_BIN, "wb");
            if (contasPagarBin_tmp == NULL) {
                printf("Erro na abertura do arquivo.");
                exit(1);
            }
            
            /* Pegando o montante atual do caixa. */
            caixa.montante = retornarMontanteCaixa(opcao);
            
            while (fread(&contasPagar, sizeof(ContasPagar), 1, contasPagarBin) == 1) {
                if (contasPagar.diaPagamento == diaAtual &&
                    contasPagar.mesPagamento == mesAtual &&
                    contasPagar.anoPagamento == anoAtual) {
                    totalRetirada += contasPagar.montante;
                }
                else {
                    fwrite(&contasPagar, sizeof(ContasPagar), 1, contasPagarBin_tmp);
                }
            }
            
            /* Calculando o novo montante do caixa e colocando no arquivo. */
            caixa.montante -= totalRetirada;
            
            FILE* caixaBin;
            caixaBin = fopen(CAIXA_BIN, "wb");
            if (caixaBin == NULL) {
                printf("Erro na abertura do arquivo.");
                exit(1);
            }

            fwrite(&caixa, sizeof(Caixa), 1, caixaBin);
            
            /* Inserindo o lançamento no sistema. */
            inserirRetirada(totalRetirada, "Baixa de retirada", opcao);
            
            /* Fechando todos os arquivos. */
            fclose(caixaBin);
            fclose(contasPagarBin);
            fclose(contasPagarBin_tmp);
            
            remove(CONTAS_PAGAR_BIN);
            rename(CONTAS_PAGAR_TMP_BIN, CONTAS_PAGAR_BIN);
        break;
        case 2:
            FILE* contasPagarTxt = fopen(CONTAS_PAGAR_TXT, "r");
            if (contasPagarTxt == NULL) {
                printf("Erro na abertura do arquivo.");
                exit(1);
            }

            FILE* contasPagarTxt_tmp = fopen(CONTAS_PAGAR_TMP_TXT, "w");
            if (contasPagarTxt_tmp == NULL) {
                printf("Erro na abertura do arquivo.");
                exit(1);
            }

            // Pegando o montante atual do caixa.
            caixa.montante = retornarMontanteCaixa(opcao);

            while (fscanf(contasPagarTxt, "*s %f\n%*s [^\n]\n%*s %d\n%*s %d\n",
                          &contasPagar.montante, contasPagar.descricao, &contasPagar.diaPagamento,
                          &contasPagar.mesPagamento, &contasPagar.anoPagamento) == 5) {
                if (contasPagar.diaPagamento == diaAtual &&
                    contasPagar.mesPagamento == mesAtual &&
                    contasPagar.anoPagamento == anoAtual) {
                    totalRetirada += contasPagar.montante;
                } else {
                    fprintf(contasPagarTxt_tmp, "Montante: %f\nDescrição: %s\nDiaPagamento: %d\nMesPagamento: %d\nAnoPagamento: %d\n",
                            contasPagar.montante, contasPagar.descricao, contasPagar.diaPagamento,
                            contasPagar.mesPagamento, contasPagar.anoPagamento);
                }
            }

            // Calculando o novo montante do caixa e colocando no arquivo.
            caixa.montante -= totalRetirada;

            FILE* caixaTxt = fopen(CAIXA_TXT, "w");
            if (caixaTxt == NULL) {
                printf("Erro na abertura do arquivo.");
                exit(1);
            }

            fprintf(caixaTxt, "Montante: %f\n", caixa.montante);

            // Inserindo o lançamento no sistema.
            inserirRetirada(totalRetirada, "Baixa de retirada", opcao);

            // Fechando todos os arquivos.
            fclose(caixaTxt);
            fclose(contasPagarTxt);
            fclose(contasPagarTxt_tmp);

            remove(CONTAS_PAGAR_TXT);
            rename(CONTAS_PAGAR_TMP_TXT, CONTAS_PAGAR_TXT);
        break;
    }
}