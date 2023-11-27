#include <stdlib.h>
#include <stdio.h>

#include "../caixa/caixa.h"
#include "contas_receber.h"

void baixarRecebimento (int opcao) {
    /* Nesta função, quando chamada, baixará os recebimentos pendentes do 
     * hotel, colocando-os no caixa. */
    
    int diaAtual = retornarDiaAtual();
    int mesAtual = retornarMesAtual();
    int anoAtual = retornarAnoAtual();
    float totalReceber = 0;
    ContasReceber contasReceber;
    Caixa caixa;
    
    switch (opcao) {
        case 1:
            FILE* contasReceberBin;
            contasReceberBin = fopen(CONTAS_RECEBER_BIN, "rb");
            if (contasReceberBin == NULL) {
                printf("Erro na abertura do arquivo.");
                exit(1);
            }
            
            FILE* contasReceberBin_tmp;
            contasReceberBin_tmp = fopen(CONTAS_RECEBER_TMP_BIN, "wb");
            if (contasReceberBin_tmp == NULL) {
                printf("Erro na abertura do arquivo.");
                exit(1);
            }
            
            /* Pegando o montante atual do caixa. */
            caixa.montante = retornarMontanteCaixa();
            
            while (fread(&contasReceber, sizeof(ContasReceber), 1, contasReceberBin) == 1) {
                if (contasReceber.diaRecebimento == diaAtual &&
                    contasReceber.mesRecebimento == mesAtual &&
                    contasReceber.anoRecebimento == anoAtual) {
                    totalReceber += contasReceber.montante;
                }
                else {
                    fwrite(&contasReceber, sizeof(ContasReceber), 1, contasReceberBin_tmp);
                }
            }
            
            /* Calculando o novo montante do caixa e colocando no arquivo. */
            caixa.montante += totalReceber;
            
            FILE* caixaBin;
            caixaBin = fopen(CAIXA_BIN, "wb");
            if (caixaBin == NULL) {
                printf("Erro na abertura do arquivo.");
                exit(1);
            }

            fwrite(&caixa, sizeof(Caixa), 1, caixaBin);
            
            /* Inserindo o lançamento no sistema. */
            inserirLancamento(totalReceber, "Baixa de recebimento", opcao);
            
            /* Fechando todos os arquivos. */
            fclose(caixaBin);
            fclose(contasReceberBin);
            fclose(contasReceberBin_tmp);
            
            remove(CONTAS_RECEBER_BIN);
            rename(CONTAS_RECEBER_TMP_BIN, CONTAS_RECEBER_BIN);
        break;
        case 2: break;
    }
}