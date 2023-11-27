#include <stdio.h>
#include <stdlib.h>
#include "../../reserva/reserva.h"
#include "../controle_caixa/caixa/caixa.h"
#include "../controle_caixa/contas_receber/contas_receber.h"
#include "checkout.h"

/* Quando o hóspede faz check-in, deve ser criada uma conta para
 * que no check-out seja verificado se há coisas a pagar. */
void criarContaHospede (ContaHospede conta, int opcao) {
    switch (opcao) {
        case 1:
            FILE* arqContaBin;
            arqContaBin = fopen(CONTA_HOSPEDE_BIN, "ab");
            if (arqContaBin == NULL) {
                printf("Erro na abertura do arquivo.");
                exit(1);
            }
            
            /* Como a conta será aberta na hora do check-in e será excluída
             * no momento do check-out, é seguro dizer que não é necessário
             * verificação para que haja unicidade de hóspede, apenaa de código
             * de conta. */
            if (!feof(arqContaBin)) {
                fwrite(&conta, sizeof(ContaHospede), 1, arqContaBin);
            }
            else {
                printf("Arquivo cheio.\n");
                exit(1);
            }
            
            fclose(arqContaBin);
        break;
        case 2: break;
    }
}

/* Essa função será ativada quando o pagamento das contas do
 * checkout forem feitas em dinheiro. */
void efetuarCheckOutDinheiro (ContaHospede conta, int opcao) {
    float total = 0;
    Caixa caixa;
    Lancamento lancamento;
    
    switch (opcao) {
        case 1:
            total += conta.totalDiarias; /* Adicionando as diárias, caso haja. */
            total += conta.totalConsumo; /* Adicionando o total de consumo. */
            
            /* Pegando o montante atual. 
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
            
            fclose(caixaBin);
            
            /* Agora, colocando o lançamento do caixa no arquivo de lançamentos. */
            inserirLancamento(total, "Check-out", opcao);
            
            /* Como o check-out foi efeutado, pode-se excluir o
             * registro da conta do hóspede do arquivo de contas. */
            deletarConta(conta.codigoHospede, opcao);
            
            printf("Check-out efetuado com sucesso!");
        break;
        case 2: break;
    }
}

void efetuarCheckOutCartao (ContaHospede conta, int opcao, int diaVencCartao, int mesVencCartao, int anoVencCartao) {
    float total = 0;
    ContasReceber contasReceber;
    
    switch (opcao) {
        case 1:
            total += conta.totalDiarias; /* Adicionando as diárias, caso haja. */
            total += conta.totalConsumo; /* Adicionando o total de consumo. */
            
            /* Colocando a conta a receber no seu arquivo. */
            FILE* contasReceberBin;
            contasReceberBin = fopen(LANCAMENTOS_BIN, "ab");
            if (contasReceberBin == NULL) {
                printf("Erro na abertura do arquivo.");
                exit(1);
            }
            
            contasReceber.montante = total;
            contasReceber.descricao = "Check-out";
            contasReceber.diaRecebimento = diaVencCartao;
            contasReceber.mesRecebimento = mesVencCartao;
            contasReceber.anoRecebimento = anoVencCartao;
            
            if (!feof(contasReceberBin)) {
                fwrite(&contasReceber, sizeof(ContasReceber), 1, contasReceberBin);
            }
            else {
                printf("Arquivo cheio.");
                exit(1);
            }
            
            fclose(contasReceberBin);
            
            /* Como o check-out foi efeutado, pode-se excluir o
             * registro da conta do hóspede do arquivo de contas. */
            deletarConta(conta.codigoHospede, opcao);
            
            printf("Check-out efetuado com sucesso!");
        break;
        case 2: break;
    }
}

void deletarConta (int codigoHospede, int opcao) {
    int dadoAchado = 0;
    ContaHospede conta;
    
    switch (opcao) {
        case 1:
            FILE* arqContaBin;
            arqContaBin = fopen(CONTA_HOSPEDE_BIN, "rb");
            if (arqContaBin == NULL) {
                printf("Erro na abertura do arquivo.");
                exit(1);
            }

            FILE *arqContaBin_tmp;
            arqContaBin_tmp = fopen(CONTA_HOSPEDE_TMP_BIN, "wb");

            /* Verificação da abertura. */
            if(arqContaBin_tmp == NULL){
                printf("Erro na abertura do arquivo.\n");
                exit(1);
            }

            rewind(arqContaBin);
            while (fread(&conta, sizeof(ContaHospede), 1, arqContaBin) == 1) {
                if (conta.codigoHospede == codigoHospede) {
                    dadoAchado = 1;
                }
                else {
                    fwrite(&conta, sizeof(ContaHospede), 1, arqContaBin_tmp);
                }
            }

            fclose(arqContaBin);
            fclose(arqContaBin_tmp);

            remove(CONTA_HOSPEDE_BIN);
            rename(CONTA_HOSPEDE_TMP_BIN, CONTA_HOSPEDE_BIN);
        break;
        
        case 2:
            break;
    }
}

ContaHospede retornarConta (int codigoHospede, int opcao) {
    ContaHospede conta;
    
    switch (opcao) {
        case 1:
            FILE* arqContaBin;
            arqContaBin = fopen(CONTA_HOSPEDE_BIN, "rb");
            if (arqContaBin == NULL) {
                printf("Erro na abertura do arquivo.");
                exit(1);
            }
            
            while (fread(&conta, sizeof(ContaHospede), 1, arqContaBin) == 1) {
                if (conta.codigoHospede == codigoHospede) {
                    return conta;
                }
            }
            
            fclose(arqContaBin);
        break;
        case 2: break;
    }
}