#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
        case 2:
            FILE* arqContaTxt;
            arqContaTxt = fopen(CONTA_HOSPEDE_TXT, "a");

            if (arqContaTxt == NULL) {
                printf("Erro na abertura do arquivo.\n");
                exit(1);
            }
            
            if (!feof(arqContaTxt)) {
                fprintf(arqContaTxt, "CódigoConta: %d\nCódigoHospede: %d\nTotalDiárias: %.2f\nTotalConsumo: %.2f\n", conta.codigoConta, conta.codigoHospede, conta.totalDiarias, conta.totalConsumo);
            }

            fclose(arqContaTxt);
        break;
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
            
            fclose(caixaBin);
            
            /* Agora, colocando o lançamento do caixa no arquivo de lançamentos. */
            inserirLancamento(total, "Check-out", opcao);
            
            /* Como o check-out foi efeutado, pode-se excluir o
             * registro da conta do hóspede do arquivo de contas. */
            deletarConta(conta.codigoHospede, opcao);
            
            printf("Check-out efetuado com sucesso!");
        break;
        case 2:
            total += conta.totalDiarias; /* Adicionando as diárias, caso haja. */
            total += conta.totalConsumo; /* Adicionando o total de consumo. */

            /* Pegando o montante atual do caixa. */
            caixa.montante = retornarMontanteCaixa(opcao);

            /* Agora, escrevendo o novo montante no arquivo. */
            caixa.montante += total;

            FILE *caixaTxt;
            caixaTxt = fopen(CAIXA_TXT, "a");
            if (caixaTxt == NULL) {
                printf("Erro na abertura do arquivo.");
                exit(1);
            }

            fprintf(caixaTxt, "Montante: %.2f\n", caixa.montante);

            fclose(caixaTxt);

            /* Agora, colocando o lançamento do caixa no arquivo de lançamentos. */
            inserirLancamento(total, "Check-out", opcao);

            /* Como o check-out foi efetuado, pode-se excluir o
             * registro da conta do hóspede do arquivo de contas. */
            deletarConta(conta.codigoHospede, opcao);

            printf("Check-out efetuado com sucesso!");
        break;
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
            contasReceberBin = fopen(CONTAS_RECEBER_BIN, "ab");
            if (contasReceberBin == NULL) {
                printf("Erro na abertura do arquivo.");
                exit(1);
            }
            
            contasReceber.codigoHospede = conta.codigoHospede;
            contasReceber.montante = total;
            strcpy(contasReceber.descricao, "Check-out");
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
        case 2:
            total += conta.totalDiarias; /* Adicionando as diárias, caso haja. */
            total += conta.totalConsumo; /* Adicionando o total de consumo. */

            /* Colocando a conta a receber no seu arquivo. */
            FILE *contasReceberTxt;
            contasReceberTxt = fopen(CONTAS_RECEBER_TXT, "a");
            if (contasReceberTxt == NULL) {
                printf("Erro na abertura do arquivo.");
                exit(1);
            }

            contasReceber.codigoHospede = conta.codigoHospede;
            contasReceber.montante = total;
            strcpy(contasReceber.descricao, "Check-out");
            contasReceber.diaRecebimento = diaVencCartao;
            contasReceber.mesRecebimento = mesVencCartao;
            contasReceber.anoRecebimento = anoVencCartao;

            fprintf(contasReceberTxt, "Hóspede: %d\nMontante: %.2f\nDescrição: %s\nDiaRecebimento: %d\nMesRecebimento: %d\nAnoRecebimento: %d\n", contasReceber.codigoHospede, contasReceber.montante, contasReceber.descricao,
                    contasReceber.diaRecebimento, contasReceber.mesRecebimento, contasReceber.anoRecebimento);

            fclose(contasReceberTxt);

            /* Como o check-out foi efetuado, pode-se excluir o registro da conta do hóspede do arquivo de contas. */
            deletarConta(conta.codigoHospede, opcao);

            printf("Check-out efetuado com sucesso!");
        break;
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
            
            if (dadoAchado == 0) {
                printf("Conta não encontrada!");
            }

            fclose(arqContaBin);
            fclose(arqContaBin_tmp);

            remove(CONTA_HOSPEDE_BIN);
            rename(CONTA_HOSPEDE_TMP_BIN, CONTA_HOSPEDE_BIN);
        break;
        
        case 2:
            FILE* arqContaTxt;
            arqContaTxt = fopen(CONTA_HOSPEDE_TXT, "r");
            if (arqContaTxt == NULL) {
                printf("Erro na abertura do arquivo.");
                exit(1);
            }

            FILE* arqContaTxt_tmp;
            arqContaTxt_tmp = fopen(CONTA_HOSPEDE_TMP_TXT, "w");

            /* Verificação da abertura. */
            if (arqContaTxt_tmp == NULL) {
                printf("Erro na abertura do arquivo.\n");
                exit(1);
            }

            while (fscanf(arqContaTxt, "%*s %d\n%*s %d\n%*s %f\n%*s %f", &conta.codigoConta, &conta.codigoHospede, &conta.totalDiarias, &conta.totalConsumo) == 4) {
                if (conta.codigoHospede == codigoHospede) {
                    dadoAchado = 1;
                } else {
                    fprintf(arqContaTxt, "CódigoConta: %d\nCódigoHospede: %d\nTotalDiárias: %.2f\nTotalConsumo: %.2f\n", conta.codigoConta, conta.codigoHospede, conta.totalDiarias, conta.totalConsumo);
                }
            }
            
            if (dadoAchado == 0) {
                printf("Conta não encontrada!");
            }

            fclose(arqContaTxt);
            fclose(arqContaTxt_tmp);

            remove(CONTA_HOSPEDE_TXT);
            rename(CONTA_HOSPEDE_TMP_TXT, CONTA_HOSPEDE_TXT);
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
        case 2:
            FILE* arqContaTxt;
            arqContaTxt = fopen(CONTA_HOSPEDE_TXT, "r");

            if (arqContaTxt == NULL) {
                printf("Erro na abertura do arquivo.");
                exit(1);
            }

            while (fscanf(arqContaTxt, "%*s %d\n%*s %d\n%*s %f\n%*s %f", &conta.codigoConta, &conta.codigoHospede, &conta.totalDiarias, &conta.totalConsumo) == 4) {
                if (conta.codigoHospede == codigoHospede) {
                    fclose(arqContaTxt);
                    return conta;
                }
            }

            fclose(arqContaTxt);
        break;
    }
}

int contaHospedeExiste (int codigoHospede, int codigoConta, int opcao) {
    ContaHospede conta;
    int encontrado = 0;
    
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
                    encontrado = 1; // A conta existe
                    break;
                }
                if (conta.codigoConta == codigoConta) {
                    encontrado = 1; // A conta existe
                    break;
                }
            }

            fclose(arqContaBin);
            
            return encontrado;
        break;
        case 2:
            FILE* arqContaTxt = fopen(CONTA_HOSPEDE_TXT, "r");
    
            if (arqContaTxt == NULL) {
                printf("Erro na abertura do arquivo.");
                exit(1);
            }

            while (fscanf(arqContaTxt, "%*s %d\n%*s %d\n%*s %f\n%*s %f", &conta.codigoConta, &conta.codigoHospede, &conta.totalDiarias, &conta.totalConsumo) == 4) {
                if (conta.codigoHospede == codigoHospede) {
                    encontrado = 1; // A conta existe
                    break;
                }
                if (conta.codigoConta == codigoConta) {
                    encontrado = 1; // A conta existe
                    break;
                }
            }

            fclose(arqContaTxt);
            
            return encontrado; // A conta não existe
        break;
    }
}